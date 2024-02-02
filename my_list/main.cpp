#include "my_list.h"
#include "my_list.cpp"
#include <iostream>

using namespace std;

int main() {
    my_list::List<string> mi_lista;
    mi_lista.push_back("hola");
    mi_lista.push_back("mundo");
    mi_lista.push_back("!");

    cout << mi_lista.front() << endl;
    cout << mi_lista.back() << endl;

    my_list::List<string>::List_Iterator it = mi_lista.begin();

    while (it != mi_lista.end()) {
        cout << it->get_data() << endl;
         it = it->get_next();
    }

    cout << mi_lista.size() << endl;
    cout << mi_lista.empty() << endl;
    mi_lista.clear();
    cout << mi_lista.size() << endl;
    cout << mi_lista.empty() << endl;
}