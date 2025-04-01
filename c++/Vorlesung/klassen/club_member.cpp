#include <iostream>

class ClubMember {
    static int s_count;

    int _member_id;

    static int s_id_generator;

  public:
    ClubMember() {
        s_count++;
        _member_id = s_id_generator++;
    }
    ~ClubMember() {
        s_count--;
    }
    void print() {
        std::cout << "Mitgliedsnummer " << _member_id << std::endl;
    }

    static int get_count() {
        std ::cout << s_count << std::endl;
    }
    
};
int ClubMember::_s = 0;
int 

int main() {

    std::cout << "Anzahl der Member " << ClubMember::get_count() << std::endl;

    ClubMember ali;
    ali.print();
    ClubMember lisa;
    lisa.print();

    ClubMember affe;
    affe.print();

    
   std:: cout<< "Anzahl der Member "<<  ClubMember::get_count()<< std:: endl;
}