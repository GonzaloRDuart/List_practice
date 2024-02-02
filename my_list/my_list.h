#ifndef LIST_H
#define LIST_H
#include <stdexcept>

namespace my_list {
template <class T> class Node {
public:
  typedef Node<T>* Node_Iterator;
  Node() : next(nullptr), prev(nullptr), data(nullptr) {};
  explicit Node(const T& value) : next(nullptr), prev(nullptr){
      data = alloc.allocate(1);
      alloc.construct(data, value);
  };
  ~Node() {
      if (data != nullptr) {
          alloc.destroy(data);   // Destruct the object
          alloc.deallocate(data, 1);  // Deallocate the memory
      }
  };
  Node_Iterator get_next() const;
  void set_next(Node_Iterator);
  Node_Iterator get_prev() const;
  void set_prev(Node_Iterator);
  T get_data() const;
  void set_data(const T&);
  Node& operator=(Node);
  bool operator==(Node) const;
  bool operator!=(Node) const;
  Node_Iterator operator++();
  T operator*();

private:
    std::allocator<T> alloc;
  Node_Iterator next;
  Node_Iterator prev;
  T* data;
};

template <class T> class List {
public:
  typedef Node<T> *List_Iterator;
  typedef const Node<T>* Const_iterator;
  typedef T value_type;

  List() : head(nullptr), tail(nullptr), sz(0){};
  List& operator=(const List&);
  T front() const;
  T back() const;
  List_Iterator begin() const;
  List_Iterator end() const;
  [[nodiscard]] bool empty() const;
  [[nodiscard]] size_t size() const;
  void clear();

  List_Iterator insert(List_Iterator, const T&);
  List_Iterator erase(List_Iterator);
  void push_back(const T&);
  void pop_back();
  void push_front(const T&);
  void pop_front();
  void merge(List<T>&);
  void splice(List_Iterator, List<T>&);
  void remove(T&);
  void remove_if(bool (*func)(T &));
  void reverse();
  void sort();

private:
  List_Iterator head;
  List_Iterator tail;
  std::allocator<T> alloc;
  size_t sz;
};
} // namespace my_list

#endif