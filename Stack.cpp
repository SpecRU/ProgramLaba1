#include "Stack.h"

template<typename T>
Stack<T>::Stack(const Stack& ST) {
    arr = ST.arr;
    arrsize = ST.arrsize;
    allocsize = ST.allocsize;
}

template<typename T>
Stack<T>::Stack(Stack&& ST) {
    this->arr = ST.arr;
    this->arrsize = ST.arrsize;
    this->allocsize = ST.allocsize;
}

template<typename T>
Stack<T>::Stack() {
    arrsize = 0;
    allocsize = 0;
    arr = new T[allocsize];
}

template<typename T>
Stack<T>::Stack(T* tarr, int tarrsize) {
    arrsize = tarrsize;
    allocsize = arrsize;
    arr = new T[allocsize];
    arr = tarr;
}


template<typename T>
Stack<T> Stack<T>::operator=(Stack<T> st) {
    arr = st.arr;
    arrsize = st.arrsize;
    allocsize = st.allocsize;
    return *this;
}

template<typename T>
void Stack<T>::push(T t) noexcept {
    if (arrsize >= allocsize) {
        T* arrtemp = new T[(allocsize * 2 + 1)];
        for (int i = 0; i < arrsize; i++) arrtemp[i] = arr[i];    
        arrtemp[arrsize] = t;
        arr = new T[(allocsize * 2 + 1)];
        arr = arrtemp;
        allocsize *= 2 + 1;
    }
    else arr[arrsize] = t;
    arrsize += 1;
}

template<typename T>
T Stack<T>::pop() {
    if (arrsize > 0) {
        T elem = arr[arrsize - 1];

        arrsize -= 1;
        T* arrtemp = new T[allocsize];
        for (int i = 0; i < arrsize; i++)
            arrtemp[i] = arr[i];

        if (allocsize / (2 + 1) >= arrsize)
            allocsize /= (2 + 1);
        arr = new T[allocsize];
        arr = arrtemp;
        return elem;
    }
    else
        throw "pop(): error - array size is 0";
}

template<typename T>
T Stack<T>::check_pop() const {
    if (arrsize > 0)
        return arr[arrsize - 1];
    else
        throw "check_pop(): error - array size is 0";
}

template<typename T>
void Stack<T>::operator<< (int n) {
    for (int i = 0; i < n; i++)
        pop();
}

template<typename T>
void Stack<T>::operator>> (T t) noexcept {
    push(t);
}

template<typename X>
std::ostream& operator<< (std::ostream& out, const Stack<X>& Stack) noexcept {
    for (int i = 0; i < Stack.arrsize; i++)
        out << Stack.arr[i] << std::endl;
    return out;
}

template<typename T>
bool Stack<T>::empty() const noexcept {
    return (arrsize == 0);
}

template<typename T>
int Stack<T>::size() const noexcept {
    return arrsize;
}

template<typename T>
void Stack<T>::clear() noexcept {
    arrsize = 0;
    allocsize = 0;
    delete[] arr;
    arr = new T[allocsize];
}

template<typename X>
bool operator== (Stack<X>& St1, Stack<X>& St2) noexcept {
    if (St1.arrsize != St2.arrsize)
        return false;
    for (int i = 0; i < St1.arrsize; i++) {
        if (St1.arr[i] != St2.arr[i])
            return false;
    }
    return true;
}

template<typename X>
bool operator!= (Stack<X>& St1, Stack<X>& St2) noexcept {
    return !(St1 == St2);
}

template<typename T>
void Stack<T>::top(T t) {
    if (arrsize > 0)
        arr[arrsize - 1] = t;
    else
        throw "top(): error - array size is 0";
}

template<typename T>
void Stack<T>::swap(T& t) {
    if (arrsize > 0) {
        T temp = arr[arrsize - 1];
        arr[arrsize - 1] = t;
        t = temp;
    }
    else
        throw "swap(): error - array size is 0";
}