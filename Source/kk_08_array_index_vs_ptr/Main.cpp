#include <iostream>

int array_max_ptr(int* array, unsigned int len) {
  int current_max = *array;

  for (int i = 1; i < len; ++i) {
    if (*(array + i) > current_max) {
      current_max = *(array + i);
    }
  }

  return current_max;
}

// array index operator used on pointers
int array_max_idx(int* array, unsigned int len) {
  int current_max = array[0];

  for (int i = 1; i < len; ++i) {
    if (array[i] > current_max) {
      current_max = array[i];
    }
  }

  return current_max;
}

int main(int argc, char* argv[]) {
  int array[]{11, 22, 145, 8, 9, 53};
  unsigned int array_size = sizeof(array) / sizeof(int);

  std::cout << "array_max_ptr: " << array_max_ptr(array, array_size) << std::endl;
  std::cout << "array_max_idx: " << array_max_idx(array, array_size) << std::endl;

  return 0;
}
