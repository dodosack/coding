#include <iostream>


class ClubMember
{
  static int _s_count;
  int _member_id;
  static int _id_generator;

public:
  ClubMember()
  {
    _s_count++;
    _member_id = ++_id_generator;
  }

  ~ClubMember()
  {
    _s_count--;
  }

  void print()
  {
    std::cout << "Mitgliedsnumer: " << _member_id << std::endl;
  }

  static int get_count()
  {
    return _s_count;
  }
};

int ClubMember::_s_count = 0;
int ClubMember::_id_generator = 0;

int main()
{

  std::cout << "member count: " << ClubMember::get_count() << std::endl;

  ClubMember peter;
  peter.print();
  peter.~ClubMember();
  ClubMember alice;
  alice.print();
  std::cout << "member count: " << ClubMember::get_count() << std::endl;
  ClubMember gustav;
  gustav.print();

  std::cout << "member count: " << ClubMember::get_count() << std::endl;

  return 0;
}