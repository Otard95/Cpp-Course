#include "Headers/Utils.h"
#include <limits>

int Utils::get_int () {

  int x;
  while (!(cin >> x)) {

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Try again: ";

  }
  cin.clear();
  cin.ignore();

  return x;
}

int Utils::get_int (string hint) {

  cout << hint;
  return Utils::get_int();

}

int Utils::get_int_range (int min, int max) {

  int x;
  while (!(cin >> x) || x < min || x > max) {

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Try again: ";
    
  }
  cin.clear();
  cin.ignore();

  return x;

}

int  Utils::get_int_range (int min, int max, string hint) {

  cout << hint;
  return Utils::get_int_range(min, max);

}
