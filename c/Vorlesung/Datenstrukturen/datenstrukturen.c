#include <stdio.h>
#include <string.h>
 


  struct Wohnort 
  {
      char ort[100];
      int postleitzsahl;
  };
  
 struct person
    {
        char name[50];
        int age;
        struct Wohnort adresse;  // somit kann man nach bestimmten bedingungen filtern 
        
        
        

    };
int main()
{

    struct person person1;
    person1.age = 19;
    person1.adresse.postleitzsahl = 73730;  

    //person1.name = "Adam"; //  dasgeht nicht brudi 
    strcpy(person1.name, "Adam"); // immer für char nehmen 

    printf("%s %d %d\n\n", person1.name, person1.age, person1.adresse.postleitzsahl);

    printf("%d \n\n", sizeof( person1));
    return 0;
}