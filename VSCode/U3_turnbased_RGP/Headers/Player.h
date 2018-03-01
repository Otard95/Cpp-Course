#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <vector>
#include <memory>
#include "CharacterClass.h"
#include "Ability.h"

    using namespace std;

class Player {

  public: 
    Player (string /*name*/, int /*character type*/);

    string         get_name      () const;
    CharacterClass get_class     () const;
    bool           is_dead       () const;
    void           print_attacks () const;
    void           set_target    (shared_ptr<Player>);
    void           set_ability   (int);
    void           use_ability   ();
    void           update        ();

    ~Player ();

  private:
    string         m_name;
    CharacterClass m_class;

    int m_hp;
    int m_shield;
    vector<Ability> m_abilities;

    int    m_incoming_damage;
    shared_ptr<Player> m_target;
    Ability m_selected_ability;

};

#endif