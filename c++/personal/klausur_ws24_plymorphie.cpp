#include <iostream>
using namespace std;
class Developer
{
public:
 void knows_languages() { cout << "some language." << endl; };
 void has_programming_skills() { cout << "Writes uncommented code in "; };
 void write_code()
 {
 this->has_programming_skills();
 this->knows_languages();
 };
};

class JuniorDeveloper : public Developer
{
public:
 virtual void knows_languages() { cout << "C" << endl; }
 void has_programming_skills() { cout << "Writes commented code in "; }
 void write_code()
 {
 this->has_programming_skills();
 this->knows_languages();
 };
};
class SeniorDeveloper : public JuniorDeveloper
{
public:
 void knows_languages() override { cout << "C and C++" << endl; }
 virtual void has_programming_skills()
 {
 cout << "Writes structured code in ";
 }
 void write_code()
 {
 this->has_programming_skills();
 this->knows_languages();
 };
};

class PrincipalDeveloper : public SeniorDeveloper
{
public:
 void knows_language() { cout << "C, C++ and C#" << endl; }
 void has_programming_skills() override
 {
 cout << "Writes structured and tested code in ";
 }
 void write_code()
 {
 this->has_programming_skills();
 this->knows_languages();
 };
};
int main()
{
 Developer d;
 PrincipalDeveloper pd;
 JuniorDeveloper jd = static_cast<JuniorDeveloper>(pd);
 SeniorDeveloper sd;
 PrincipalDeveloper *p_pd = &pd;
 JuniorDeveloper *p_jd = p_pd;
 SeniorDeveloper *p_sd = dynamic_cast<SeniorDeveloper *>(p_jd);
 Developer* p_d = &sd;
 d.write_code();
 // Ausgabe:
 p_d->write_code();
 // Ausgabe:
 jd.write_code();
 // Ausgabe:
 p_jd->write_code();
 // Ausgabe:
 sd.write_code();
 // Ausgabe:
 p_sd->write_code();
 // Ausgabe:
 pd.write_code();
 // Ausgabe:
 return 0;
} 