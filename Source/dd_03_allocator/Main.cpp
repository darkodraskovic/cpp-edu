// source for this example: https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed

#include <iostream>
#include <list>
#include <set>
#include <vector>

#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#include "Allocator.h"

// test() has a single template parameter, ContainerT, itself is a template type
// test() has a template class with 2 parameters specifier
template <template <typename T, typename AllocT> typename ContainerT>
void test() {
  // the name of the function in a pretty format, including the template parameters
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "Memory usage before: " << Allocator::g_memory_used.load() << std::endl;
  ContainerT<int, Allocator::Allocator<int>> container;
  for (int i = 0; i < 1000; ++i) {
    container.insert(std::end(container), i);
  }
  std::cout << "Memory usage after: " << Allocator::g_memory_used.load() << std::endl;
}

template <typename T, typename AllocT>
using SetWithDefaultComparator = std::set<T, std::less<>, AllocT>;

int main(int argc, char *argv[]) {
  test<std::vector>();
  test<std::list>();
  test<SetWithDefaultComparator>();

  return 0;
}
