#include "Headers/GameManager.h"

int main () { 

  GameManager &gm = GameManager::Instance();

  gm.init();

  gm.run();

  system("pause");

  return EXIT_SUCCESS;
}