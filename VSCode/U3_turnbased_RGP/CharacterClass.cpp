#include "Headers/CharacterClass.h"
#include <iostream>

ostream &operator<< (ostream &s, const CharacterClass &c) {
  return s << static_cast<int>(c);
}