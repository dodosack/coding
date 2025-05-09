#include <linux/init.h> // Makros __init und __exit für Init- und Exit-Funktionen
#include <linux/kernel.h> // Zugriff auf printk und Log-Level-Definitionen (z.B. KERN_INFO)
#include <linux/kprobes.h> // API für Kprobes: dynamisches Einhängen in Kernel-Funktionen
#include <linux/module.h> // Grundlegende Strukturen und Makros für Kernelmodule
#include <linux/proc_fs.h> // Erzeugen und Verwalten von Dateien im /proc-Dateisystem
#include <linux/seq_file.h> // Unterstützung für sequentielle Ausgaben in /proc

#define MAX_SYSCALLS                                                           \
  6900 // Maximale Anzahl zum Zählen, um Überlauf zu verhindern

MODULE_LICENSE("GPL"); // Lizenz des Moduls (verhindert Kernel-Taint)
MODULE_AUTHOR(
    "ADAAAAAAMMMMMMMMMM"); // Autor des Moduls (wird in modinfo angezeigt)
MODULE_DESCRIPTION("Track read, write, open, close, mkdir syscalls using "
                   "kprobes"); // Kurzbeschreibung
MODULE_VERSION("2.0");         // Versionsnummer

static unsigned int read_count = 0;  // Zähler für read()-Aufrufe
static unsigned int write_count = 0; // Zähler für write()-Aufrufe
static unsigned int open_count = 0;  // Zähler für openat()-Aufrufe
static unsigned int close_count = 0; // Zähler für close()-Aufrufe
static unsigned int mkdir_count = 0; // Zähler für mkdir()-Aufrufe

// Zeiger für den /proc-Eintrag
static struct proc_dir_entry *proc_entry;

// Definition der Kprobe-Objekte zum Abfangen der Syscalls
static struct kprobe read_kp = {.symbol_name =
                                    "__x64_sys_read"}; // Hook auf sys_read()
static struct kprobe write_kp = {.symbol_name =
                                     "__x64_sys_write"}; // Hook auf sys_write()
static struct kprobe open_kp = {
    .symbol_name = "__x64_sys_openat"}; // Hook auf sys_openat()
static struct kprobe close_kp = {.symbol_name =
                                     "__x64_sys_close"}; // Hook auf sys_close()
static struct kprobe mkdir_kp = {.symbol_name =
                                     "__x64_sys_mkdir"}; // Hook auf sys_mkdir()

// Pre-Handler für read(): wird VOR Ausführung von sys_read() aufgerufen
static int handler_pre_read(struct kprobe *p, struct pt_regs *regs) {
  if (read_count < MAX_SYSCALLS) // Prüfen, ob Zähler noch unter Grenze ist
    read_count++;                // Zähler erhöhen
  return 0; // 0 = Kernel führt Original-Funktion weiter aus
}

// Pre-Handler für write(): wird VOR Ausführung von sys_write() aufgerufen
static int handler_pre_write(struct kprobe *p, struct pt_regs *regs) {
  if (write_count < MAX_SYSCALLS)
    write_count++;
  return 0;
}

// Pre-Handler für openat(): wird VOR Ausführung von sys_openat() aufgerufen
static int handler_pre_open(struct kprobe *p, struct pt_regs *regs) {
  if (open_count < MAX_SYSCALLS)
    open_count++;
  return 0;
}

// Pre-Handler für close(): wird VOR Ausführung von sys_close() aufgerufen
static int handler_pre_close(struct kprobe *p, struct pt_regs *regs) {
  if (close_count < MAX_SYSCALLS)
    close_count++;
  return 0;
}

// Pre-Handler für mkdir(): wird VOR Ausführung von sys_mkdir() aufgerufen
static int handler_pre_mkdir(struct kprobe *p, struct pt_regs *regs) {
  if (mkdir_count < MAX_SYSCALLS)
    mkdir_count++;
  return 0;
}

// Callback, um die Zählerstände in /proc/syscall_tracker auszugeben
static int syscall_tracker_show(struct seq_file *m, void *v) {
  seq_printf(m, "Tracked read() syscalls: %u\n",
             read_count); // Ausgabe read_count
  seq_printf(m, "Tracked write() syscalls: %u\n",
             write_count); // Ausgabe write_count
  seq_printf(m, "Tracked open() syscalls: %u\n",
             open_count); // Ausgabe open_count
  seq_printf(m, "Tracked close() syscalls: %u\n",
             close_count); // Ausgabe close_count
  seq_printf(m, "Tracked mkdir() syscalls: %u\n",
             mkdir_count); // Ausgabe mkdir_count
  return 0;                // Erfolgreiches Schreiben
}

// Open-Callback für /proc/syscall_tracker: initialisiert die seq_file
static int syscall_tracker_open_proc(struct inode *inode, struct file *file) {
  return single_open(file, syscall_tracker_show, NULL);
}

// Verknüpft Dateioperationen im /proc mit unseren Callbacks
static const struct proc_ops proc_fops = {
    .proc_open = syscall_tracker_open_proc, // open()
    .proc_read = seq_read,                  // read()
    .proc_release = single_release,         // close()
};

// Init-Funktion: wird beim Laden des Moduls (insmod) ausgeführt
static int __init syscall_tracker_init(void) {
  int ret; // Rückgabewert für register_kprobe()

  // Weist die Pre-Handler den Kprobe-Strukturen zu
  read_kp.pre_handler = handler_pre_read;
  write_kp.pre_handler = handler_pre_write;
  open_kp.pre_handler = handler_pre_open;
  close_kp.pre_handler = handler_pre_close;
  mkdir_kp.pre_handler = handler_pre_mkdir;

  // Registriert die Kprobes; bei Fehlern wird zu den Labels gesprungen
  if ((ret = register_kprobe(&read_kp)) < 0)
    goto fail;
  if ((ret = register_kprobe(&write_kp)) < 0)
    goto fail_unregister_read;
  if ((ret = register_kprobe(&open_kp)) < 0)
    goto fail_unregister_write;
  if ((ret = register_kprobe(&close_kp)) < 0)
    goto fail_unregister_open;
  if ((ret = register_kprobe(&mkdir_kp)) < 0)
    goto fail_unregister_close;

  // Legt die Datei /proc/syscall_tracker an, mit unseren proc_ops
  proc_entry = proc_create("syscall_tracker", 0, NULL, &proc_fops);
  if (!proc_entry) { // Prüfen, ob Anlage erfolgreich war
    ret = -ENOMEM;   // Fehler: nicht genug Speicher
    goto fail_unregister_mkdir;
  }

  printk(KERN_INFO
         "Syscall tracker module loaded.\n"); // Log-Ausgabe bei Erfolg
  return 0;                                   // Modul erfolgreich geladen

// Fehlerbehandlung: hebelt die Kprobes in umgekehrter Reihenfolge wieder aus
fail_unregister_mkdir:
  unregister_kprobe(&mkdir_kp);
fail_unregister_close:
  unregister_kprobe(&close_kp);
fail_unregister_open:
  unregister_kprobe(&open_kp);
fail_unregister_write:
  unregister_kprobe(&write_kp);
fail_unregister_read:
  unregister_kprobe(&read_kp);
fail:
  return ret; // Fehlercode zurückgeben
}
module_init(syscall_tracker_init); // Registriert Init-Funktion

// Exit-Funktion: wird beim Entfernen des Moduls (rmmod) ausgeführt
static void __exit syscall_tracker_exit(void) {
  proc_remove(proc_entry);      // Entfernt die /proc-Datei
  unregister_kprobe(&mkdir_kp); // Hebt mkdir-Probe auf
  unregister_kprobe(&close_kp); // Hebt close-Probe auf
  unregister_kprobe(&open_kp);  // Hebt openat-Probe auf
  unregister_kprobe(&write_kp); // Hebt write-Probe auf
  unregister_kprobe(&read_kp);  // Hebt read-Probe auf

  printk(KERN_INFO "Syscall tracker module unloaded.\n"); // Log-Ausgabe
  printk(KERN_INFO "=== Syscall Tracker Summary ===\n");  // Überschrift
  printk(KERN_INFO "read()  calls: %u\n", read_count);    // Endstand read()
  printk(KERN_INFO "write() calls: %u\n", write_count);   // Endstand write()
  printk(KERN_INFO "open()  calls: %u\n", open_count);    // Endstand openat()
  printk(KERN_INFO "close() calls: %u\n", close_count);   // Endstand close()
  printk(KERN_INFO "mkdir() calls: %u\n", mkdir_count);   // Endstand mkdir()
}
module_exit(syscall_tracker_exit); // Registriert Exit-Funktion
