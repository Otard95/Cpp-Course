#include "Headers/AbilityFactory.h"

vector<Ability> AbilityFactory::Create(int c_class) {

	vector<Ability> abilities;

	switch (c_class)
	{

	case static_cast<int>(CharacterClass::Wizard):
		abilities = {
			{"Fire Ball", 15, 0, 1},
			{"Arcane Comet", 40, 0, 4},
			{"Magical Barrier", 0, 20, 4}
		};
		break;

	case static_cast<int>(CharacterClass::Fighter):
		abilities = {
			{"Heavy Swing", 10, 0, 1},
			{"Call To Arms", 30, 0, 4},
			{"Shiled Wall", 0, 15, 4}
		};
		break;

	case static_cast<int>(CharacterClass::Druid):
		abilities = {
			{"Overgrowth", 10, 0, 1},
			{"Herbal Healing", -10, 0, 4},
			{"Healing Aura", -30, 0, 4}
		};
		break;

	default:
		abort(); // Input error
	}

	return abilities;
	
}