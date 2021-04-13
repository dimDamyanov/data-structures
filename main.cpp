#include <iostream>
#include "ArrayList.h"


int main() {
    int a = 45;
    ArrayList<int> arrayList;
    for (int i = 0; i < 100; i++) {
        arrayList.push_back(i);
    }
    arrayList.insert(4, a);
    for (int i = 0; i < arrayList.size(); i++)
        std::cout << *arrayList.get(i) << (i < (arrayList.size() - 1) ? " " : "\n");
    std::cout << std::boolalpha << arrayList.contains(a) << std::endl;
    arrayList.remove(4);
    std::cout << std::boolalpha << arrayList.contains(a) << std::endl;
    for (int i = 0; i < arrayList.size(); i++)
        std::cout << *arrayList.get(i) << (i < (arrayList.size() - 1) ? " " : "\n");
    std::cout << std::boolalpha << arrayList.isEmpty() << std::endl;
    arrayList.clear();
    std::cout << std::boolalpha << arrayList.isEmpty() << std::endl;
    for (int i = 0; i < arrayList.size(); i++)
        std::cout << *arrayList.get(i) << (i < (arrayList.size() - 1) ? " " : "\n");

    return 0;
}
