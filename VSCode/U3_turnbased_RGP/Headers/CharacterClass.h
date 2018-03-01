#ifndef __RACES_H_
#define __RACES_H_

#include <map>
#include <string>

using namespace std;

enum class CharacterClass {
  Wizard = 1,
  Fighter,
  Druid,
  Count,         // acts as a vectos length
  First = Wizard // acts as a getFirst() or index 0
};

// ++CharacterClass
inline CharacterClass operator++( CharacterClass& c ) {
  int ic = static_cast<int>(c) + 1;
  return c = static_cast<CharacterClass>(ic);
};

typedef map<CharacterClass, string> CCNames;

const CCNames CharacterClassNames = {
  {CharacterClass::Wizard, "Wizard"},
  {CharacterClass::Fighter, "Fighter"},
  {CharacterClass::Druid, "Druid"}
};

ostream &operator<<(ostream &s, const CharacterClass &c);

#endif
