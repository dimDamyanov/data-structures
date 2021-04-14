#include <iostream>
#include "ArrayList.h"


int main() {
    float a = 45.25;
    ArrayList<float> arrayList;
    for (int i = 0; i < 10; i++) {
        auto push = static_cast<float >(i*  0.5);
        arrayList.push_back(push);
    }
    arrayList.insert(4, a);
    for (int i = 0; i < arrayList.size(); i++)
        std::cout << *arrayList.get(i) << (i < (arrayList.size() - 1) ? " " : "\n");
    std::cout << std::boolalpha << arrayList.contains(a) << std::endl;
    arrayList.remove(4);
    std::cout << std::boolalpha << arrayList.contains(a) << std::endl;
    for (int i = 0; i < arrayList.size(); i++)
        std::cout << *arrayList.get(i) << (i < (arrayList.size() - 1) ? " " : "\n");
    std::cout << arrayList << std::endl;
    std::cout << std::boolalpha << arrayList.isEmpty() << std::endl;
    arrayList.clear();
    std::cout << std::boolalpha << arrayList.isEmpty() << std::endl;
    return 0;
}
