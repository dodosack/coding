#include "kunde.h"
using namespace std;

int Kunde::_id_generator = 0;

Kunde::Kunde(string name)
    : name(name),
      _kundennummer(++Kunde::_id_generator) {}

bool Kunde::operator==(const Kunde& k) const {
    return this->_kundennummer == k._kundennummer;
}
