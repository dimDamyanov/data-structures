#pragma once

template<class T>
class ArrayList {
public:
    ArrayList();

    ~ArrayList();

    T *get(int index);

    int indexOf(T &e);

    void push_back(T &e);

    void insert(int index, T &e);

    void remove(int index);

    void clear();

    bool contains(T &e);

    bool isEmpty();

    inline int size() { return count; }

private:
    int listSize;
    int count;
    T **data;

    bool needsExpansion();

    void expand();

    bool isValidIndex(int index);
};

template<class T>
ArrayList<T>::ArrayList() {
    listSize = 2;
    count = 0;
    data = new T *[listSize];
}

template<class T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template<class T>
T *ArrayList<T>::get(int index) {
    if (!isValidIndex(index))
        return nullptr;
    T *new_obj_ptr = new T;
    *new_obj_ptr = *(data[index]);
    return new_obj_ptr;
}

template<class T>
int ArrayList<T>::indexOf(T &e) {
    for (int i = 0; i < size(); i++) {
        if (*get(i) == e)
            return i;
    }

    return -1;
}

template<class T>
void ArrayList<T>::push_back(T &e) {
    if (needsExpansion())
        expand();
    T *new_obj_ptr = new T;
    *new_obj_ptr = e;
    data[count++] = new_obj_ptr;
}

template<class T>
void ArrayList<T>::insert(int index, T &e) {
    if (needsExpansion())
        expand();
    if (!(index >= 0 && index <= size()))
        throw std::runtime_error("IndexError");
    for (int i = size() - 1; i >= index; i--)
        data[i+1] = data[i];

    T *new_obj_ptr = new T;
    *new_obj_ptr = e;
    data[index] = new_obj_ptr;
    count++;
}

template<class T>
void ArrayList<T>::remove(int index) {
    if (!isValidIndex(index))
        throw std::runtime_error("IndexError");
    for (int i = index + 1; i < size(); i++)
        data[i-1]=data[i];

    data[count--] = nullptr;
}

template<class T>
void ArrayList<T>::clear() {
    listSize = 2;
    count = 0;
    delete[] data;
    data = new T*[listSize];
}

template<class T>
bool ArrayList<T>::contains(T &e) {
    return indexOf(e) >= 0;
}

template<class T>
bool ArrayList<T>::isEmpty() {
    return size() == 0;
}

template<class T>
bool ArrayList<T>::needsExpansion() {
    return count == listSize;
}

template<class T>
void ArrayList<T>::expand() {
    listSize *= 2;
    T **new_data = new T*[listSize];
    for (int i = 0; i < size(); i++)
        new_data[i] = data[i];

    delete[] data;
    data = new_data;
}

template<class T>
bool ArrayList<T>::isValidIndex(int index) {
    return (index >= 0 && index < size());
}
