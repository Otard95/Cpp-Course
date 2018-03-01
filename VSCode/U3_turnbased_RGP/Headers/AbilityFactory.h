#include "Ability.h"
#include "CharacterClass.h"
#include <vector>

using namespace std;

class AbilityFactory {

	public:
		static vector<Ability> Create(int c_class);

};