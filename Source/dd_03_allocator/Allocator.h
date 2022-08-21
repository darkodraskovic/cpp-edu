#include <atomic>
#include <memory>

namespace Allocator {

extern std::atomic_int g_memory_used;

template <typename T>
class Allocator : public std::allocator<T> {
 private:
  using Base = std::allocator<T>;
  using Pointer = typename std::allocator_traits<Base>::pointer;
  using SizeType = typename std::allocator_traits<Base>::size_type;

 public:
  Allocator() = default;

  // allocators are rebindable family types
  template <typename U>
  Allocator(const Allocator<U>& other) : Base(other) {}

  template <typename U>
  struct rebind {
    using other = Allocator<U>;
  };

  // shadow allocate() in Base
  Pointer allocate(SizeType n) {
    g_memory_used.fetch_add(n * sizeof(T));
    return Base::allocate(n);
  }

  // shadow deallocate() in Base
  void deallocate(Pointer p, SizeType n) {
    g_memory_used.fetch_sub(n * sizeof(T));
    Base::deallocate(p, n);
  }
};

}  // namespace Allocator
