#include "Headers/Ability.h"
#include "Headers/Utils.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>

// Ability::Ability (string name, int damage, int shield_buff, int cooldown) {

// 	m_attack_name = name;
// 	m_damage = damage;
// 	m_shield_buff = shield_buff;
// 	m_cooldown = cooldown;
// 	m_current_cd = 0;

// }
Ability::Ability (string name, int damage, int shield_buff, int cooldown)
: m_attack_name(name)
, m_damage(damage)
, m_shield_buff(shield_buff)
, m_cooldown(cooldown)
, m_current_cd(0)
{ cout << "Ability Constructed" << endl; }

Ability::~Ability() {}

string Ability::get_info () const {

	stringstream ss_out;
	ss_out
		<< setw(16) << left << m_attack_name
		<< " | "
		<< setw(2) << abs(m_damage)
		<< " " << setw(7) << left << (m_damage < 0 ? "Healing" : "Damage")
		<< " | "
		<< (is_ready() ? "Ready" : m_current_cd + " turns til its ready.");

	return ss_out.str();

}

int Ability::get_cd () const { return m_current_cd; }

bool Ability::is_ready () const { return m_current_cd == 0; }

int Ability::get_damage () const { return m_damage; }

int Ability::get_shield_buff () const { return m_shield_buff; }

void Ability::use () { m_current_cd = m_cooldown; }

void Ability::update () {
	m_current_cd--;
	m_current_cd = Utils::clamp(m_current_cd, 0, INT32_MAX);
}
