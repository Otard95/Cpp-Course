#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <string>

using namespace std;

class Utils {

  public:
    static int get_int ();                        // gets any integer from user and returns it
    static int get_int (string);                  // get any int from the user and returns it.
                                                  // also accepts a string to tell the user what to enter
    static int get_int_range (int, int);          // get an int in the spesified range
    static int get_int_range(int, int, string);   // get an int in the spesified range
                                                  // also accepts a string to tell the user what to enter
    template <typename T>
    static T clamp (T val, T min, T max) {
      return (val < min ? min : (val > max ? max : val));
    }
    
};

#endif