#include <iostream>

#include "Animal.h"

int main(int argc, char *argv[]) {
  { Animal a("fish"); }

  std::cout << ""
            << "\n";

  { Dog d("Alfredo"); }

  return 0;
}
