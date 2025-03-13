void ownStrcpy(char *chopied_pointer, char *orginal_pointer)
{ // funktion deklarieen und argumente
    //chopied_pointer = orginal_pointer; funktioniert nicht hier weil pointer pass by value gemacht werden und somit nur eine lokale kopie , wie wenn ich eine variable in eine funktoion gebe...
    
    
    //for (int i = 0; *orginal_pointer != '\0'; i++)
    
    // bei nullterminator bricht er ab aber Nullterminator brauchen wir 
   //orginal_pointer[i] != '\0' geht auch nicht weil wir pointer arithmetik machen
   
while (*orginal_pointer != '\0')
    {//lieber while wenn man mit arithmetik arbeitet

        *chopied_pointer=*orginal_pointer; // werte der adressen kopiert
        chopied_pointer++;                   // pointer steight um eine stelle
        orginal_pointer++;                   //selbe nochmal 

    }
    *chopied_pointer = '\0';
    //chopied_pointer[i] = ' \0'; // geht nicht weil wir unserre addressen ja immer verschieben  zeile 8 /9
}
