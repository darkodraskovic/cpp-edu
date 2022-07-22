#include <iostream>

// pointer is incremented until '\0' so we don't need len arg
void print_name(char* name) {
  char* name_ptr = name;

  while (*name_ptr != '\0') {
    std::cout << *name_ptr;
    name_ptr++;
  }
  std::cout << "\n";

  // or simply

  std::cout << name << std::endl;
}

int main(int argc, char* argv[]) {
  // we must explicitly add '\0' at the end
  char first_name[] = {'d', 'a', 'r', 'k', 'o', '\0'};
  std::cout << first_name << std::endl;

  // compiler automatically adds '\0' at the array end when using quotes
  char last_name[] = "draskovic";
  std::cout << last_name << std::endl;

  for (int i = 0; i < sizeof(last_name) / sizeof(char) - 1; i++) {
    std::cout << "last_name[i]: " << last_name[i] << "\n";
  }

  int int_values[]{1, 2, 3};
  // the last value printed is garbage, since there is no null terminating char
  // automatically added
  for (int i = 0; i < sizeof(int_values) / sizeof(int) + 1; ++i) {
    std::cout << "int_values[i]: " << int_values[i] << "\n";
  }

  // this prints only array address
  std::cout << "int_values: " << int_values << std::endl;

  char name[]{"Darko Draskovic"};
  print_name(name);

  return 0;
}
