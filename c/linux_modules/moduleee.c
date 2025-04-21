#include <linux/module.h>
#include <linux/kernel.h>

_init int my_init module(void) { return 0; }
_exit void my_cleanup_module(void){}


module_init(my_init_module);
module_exit(my_cleanup_module);
