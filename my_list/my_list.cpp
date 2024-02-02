#include "my_list.h"

using namespace my_list;

// Definición de Node

template <class T>
Node<T> *Node<T>::get_next() const { return next; }

template <class T>
void Node<T>::set_next(Node<T> *nxt) { next = nxt; }

template<class T>
Node<T> *Node<T>::get_prev() const { return prev; }

template<class T>
void Node<T>::set_prev(Node<T> *prv) { prev = prv; }

template <class T>
T Node<T>::get_data() const { return *data; }

template <class T>
void Node<T>::set_data(const T &value) { *data = value; }

template <class T>
Node<T>& Node<T>::operator=(Node<T> n) {
  data = n.data;
  next = n.next;
  prev = n.previ;
  return *this;
}

template <class T>
bool Node<T>::operator==(Node<T> n) const { return next == n.next; }

template <class T>
bool Node<T>::operator!=(Node<T> n) const { return next != n.next; }

template <class T>
typename Node<T>::Node_Iterator Node<T>::operator++(){ return next; }

template <class T>
T Node<T>::operator*() {return *data;}

// Fin de definición de Node

// Comienzo de definición de string_list

template <class T>
T List<T>::front() const { return head->get_data(); }

template <class T>
T List<T>::back() const { return tail->get_data(); }

template<class T>
typename List<T>::List_Iterator List<T>::begin() const { return head; }

template<class T>
typename List<T>::List_Iterator List<T>::end() const { return nullptr; }

template<class T>
bool List<T>::empty() const { return head == nullptr; }

template<class T>
size_t List<T>::size() const { return sz; }

template<class T>
void List<T>::clear() {
  while (head) {
    Node<T> *temp = head;
    head = head->get_next();
    delete temp;
  }
  sz = 0;
}

template<class T>
void List<T>::push_back(const T &value) {
  auto *new_node = new Node<T>(value);
  new_node->set_next(nullptr);
  if (tail == nullptr) {
    tail = new_node;
    head = new_node;
  } else {
    Node<T> *aux = tail;
    tail = new_node;
    tail->set_prev(aux);
    aux->set_next(tail);
  }
  sz++;
}

template<class T>
void List<T>::push_front(const T &value) {
    auto *new_node = new Node<T>(value);
  new_node->set_next(head);
  if (tail == nullptr) {
    head = new_node;
    tail = new_node;
  } else {
    Node<T> *aux = head;
    head = new_node;
    head->set_next(aux);
    aux->set_prev(head);
  }
  sz++;
}