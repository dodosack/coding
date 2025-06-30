#include <iostream>
using namespace std;
class Tier
{
public:
 virtual void laufe() { cout << "Tier::laeuft" << endl; }
 void fliege() { cout << "Tier::kann nicht fliegen" << endl; }
 void friss() { cout << "Tier::frisst Nahrung" << endl; }
};
class Vogel : public Tier
{
public:
 void laufe() override { cout << "Vogel::laeuft" << endl; }
 virtual void fliege() { cout << "Vogel::fliegt" << endl; }
 void friss() { cout << "Vogel::frisst Wuermer" << endl; }
};
class Papagei : public Vogel
{
public:
 void laufe() override { cout << "Papagei::laeuft" << endl; }
 void fliege() override { cout << "Papagei::fliegt" << endl; }
 virtual void friss() { cout << "Papagei::frisst Koerner" << endl; }
};
int main()
{
 Papagei papagei;
 Vogel vogel;
 Tier* p_tier = &vogel;
 Vogel* p_vogel = &papagei;
 Papagei* p_papagei = &papagei;
 p_tier->laufe(); // Ausgabe:
 p_vogel->laufe(); // Ausgabe:
 p_papagei->laufe(); // Ausgabe:

 p_tier->fliege(); // Ausgabe:
 vogel.fliege(); // Ausgabe:
 p_vogel->fliege(); // Ausgabe:
 p_papagei->fliege(); // Ausgabe:
 p_tier->friss(); // Ausgabe:
 p_vogel->friss(); // Ausgabe:
 p_papagei->friss(); // Ausgabe:
 return 0;
}