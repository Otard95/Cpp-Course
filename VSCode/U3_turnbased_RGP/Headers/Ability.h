#ifndef __ABILITY_H__
#define __ABILITY_H__

#include <string>

using namespace std;

class Ability {

  public:
    Ability(string name, int damage, int shield_buff, int cooldown);

    string get_info        () const; // Return string of information about this ability
    int    get_cd          () const; // Return the current cooldown of this ability
    bool   is_ready        () const; // Returns true if ability is ready to use otherwise false
    int    get_damage      () const; // Returns damage value of the ability
    int    get_shield_buff () const; // Returns shiled_buff value of ablity
    void   use             ();       // Sets cooldown
    void   update          ();       // Updates cooldown

    ~Ability();

  private:
    string m_attack_name;
    int m_damage;
    int m_shield_buff;
    int m_cooldown;
    int m_current_cd;

};

#endif