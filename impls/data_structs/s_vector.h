#ifndef LAMG_S_VECTOR_H
#define LAMG_S_VECTOR_H

#include <array>
#include <optional>
#include <vector>

namespace iustus {

template <typename T, std::size_t Capacity = 5> class s_vector {
private:
  std::array<T, Capacity> arr;
  std::size_t size = 0;

public:
  std::optional<T> peek() const {
    if (size < 1) {
      return std::nullopt;
    }
    return arr[0];
  }

  std::optional<T> peek(std::size_t idx) const {
    if (idx >= size) {
      return std::nullopt;
    }
    return arr[idx];
  }

  bool is_empty() const { return size == 0; }

  std::size_t len() const { return size; }

  void push(const T &elt) {
    if (size >= Capacity) {
      return;
    }
    arr[size] = elt;
    size++;
  }

  void prepend(const T &elt) {
    if (size < Capacity) {
      std::copy_backward(arr.begin(), arr.begin() + size,
                         arr.begin() + size + 1);
      arr[0] = elt;
      size++;
    } else {
      std::array<T, Capacity> arr_c;
      std::copy(arr.begin(), arr.begin() + size, arr_c.begin() + 1);
      arr_c[0] = elt;
      arr = arr_c;
      size++;
    }
  }

  std::optional<T> pop() {
    if (size == 0) {
      return std::nullopt;
    }
    T elt = arr[size - 1];
    size--;
    return elt;
  }

  void insert(const T &elt, std::size_t idx) {
    if (idx > size) {
      return; // Invalid index, do nothing
    }
    if (size >= Capacity) {
      return; // Vector is full, do nothing
    }
    std::copy_backward(arr.begin() + idx, arr.begin() + size,
                       arr.begin() + size + 1);
    arr[idx] = elt;
    size++;
  }

  void set(std::size_t idx, const T &elt) {
    if (idx >= size) {
      return; // Invalid index, do nothing
    }
    arr[idx] = elt;
  }
};

} // namespace iustus

#endif // LAMG_S_VECTOR_H
