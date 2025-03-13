void toUpper(char *char_string)
{ // erstmal funktion deklarieren und was welche parameter //passby reference also die speicheradresse verändern mit pointern
    // umwandlung
    for (int i = 0; char_string[i] != '\0'; i++) // aufhören bei  nullterminator NICHT i!= sondern char_string[i]!!!!!!!!!!
    {
        if (char_string[i] >= 'a' && char_string[i] <= 'z')// 
        {
            char_string[i] = char_string[i] - ('a' - 'A');
        }

    }
}