#pragma once

#include <iostream>
#include <string>

class Animal {
 public:
  Animal(const std::string& name) : name_(name) {
    std::cout << "Animal Constructor!"
              << "\n";
  }
  ~Animal() {
    std::cout << "Animal Destructor!"
              << "\n";
  }

 private:
  std::string name_;
};

class Dog : private Animal {
 public:
  Dog(const std::string& name) : Animal(name) {
    std::cout << "Dog Constructor!"
              << "\n";
  }
  ~Dog() {
    std::cout << "Dog Destructor!"
              << "\n";
  }
};
