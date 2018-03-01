#include <iostream>
#include "Headers/AbilityFactory.h"
#include "Headers/Player.h"

using namespace std;

Player::Player(string name, int character_class)
: m_name(name)
, m_class(static_cast<CharacterClass>(character_class))
, m_hp(100)
, m_shield(0)
, m_incoming_damage(0)
, m_abilities(AbilityFactory::Create(character_class))
, m_selected_ability(m_abilities[0])
{}

Player::~Player () {}

string Player::get_name () const { return m_name; }

CharacterClass Player::get_class () const { return m_class; }

bool Player::is_dead () const { return m_hp <= 0; }

void Player::print_attacks () const {

  int i = 1;
  for (auto a : m_abilities) {
    cout << i << " : " << a.get_info() << endl;
    i++;
  }

}

void Player::set_target (shared_ptr<Player> p) { m_target = p; }

void Player::set_ability (int index) {
  // index is printed as 'index + 1' when printing abilities
  m_selected_ability = m_abilities[index-1]; 
}

void Player::use_ability () {

  m_target->m_incoming_damage += m_selected_ability.get_damage();
  m_target->m_shield += m_selected_ability.get_shield_buff();

  shared_ptr<Player> p_this(this);
  if (m_selected_ability.get_shield_buff() != 0) {
    // player_other shielded player_this
    // player_this shilded self
    cout
        << m_name
        << " shilded "
        << (m_target == p_this ? "self" : m_target->m_name)
        << " for "
        << m_selected_ability.get_shield_buff();
  } else {
    cout
      << m_name
      << " attacks " 
      << (m_target == p_this ? "self" : m_target->m_name)
      << " for "
      << m_selected_ability.get_damage();
  }

  m_selected_ability.use();

}

void Player::update () {

  bool had_shield = m_shield > 0;
  m_shield -= m_incoming_damage;

  if (m_shield < 0 && had_shield) {
    // player had a shield and it absorbed some of the damage
    cout
      << m_name << "'s shield absorbed "
      << (m_shield + m_incoming_damage)
      << " damage,\n but it broke and let "
      << m_shield << " damage through."
      << endl;

    m_hp -= m_shield;
  } else if (had_shield) {
    // player had a shield and it absorbed all the damage
    cout << m_name << "'s shield absobed all incoming damage.";
  } else {
    // player did not have a shield and takes all incoming damage
    cout << m_name << " took " << m_incoming_damage << " damage";
    m_hp -= m_incoming_damage;
  }

  m_selected_ability.update();

  // reset shield, incoming damage and target.
  m_shield = 0;
  m_incoming_damage = 0;
  m_target.reset();

}
