#include <iostream>
#include <fstream>

using namespace std;

template<typename Type>
class Stack {
private:
    //parameter
    const int blockArr = 10; //Кол-во блоков для выделения новой памяти
    //
    Type* arr;
    int arrsize;
    int allocsize; //Выделенный обьем памяти
public:
    //a
    Stack();
    Stack(const Stack& ST);
    Stack(Type* tarr, int tarrsize);
    Stack(Stack&& ST);
    ~Stack() = default;
    //b
    Stack<Type> operator=(Stack<Type> st);
    //c
    void push(Type t) noexcept;
    Type pop();
    Type check_pop() const;
    //d
    void operator<< (int n);
    void operator>> (Type t) noexcept;
    //e
    template<typename X>
    friend std::ostream& operator<< (std::ostream& out, const Stack<X>& Stack) noexcept;
    //g
    bool empty() const noexcept;
    //h
    int size() const noexcept;
    //i
    void clear() noexcept;
    //j
    template<typename X>
    friend bool operator== (Stack<X>& St1, Stack<X>& St2) noexcept;
    template<typename X>
    friend bool operator!= (Stack<X>& St1, Stack<X>& St2) noexcept;
    //k
    void top(Type t);
    //l
    void swap(Type& t);

};


template<typename Type>
Stack<Type>::Stack(const Stack& ST) {
    arr = ST.arr;
    arrsize = ST.arrsize;
    allocsize = ST.allocsize;
}

template<typename Type>
Stack<Type>::Stack(Stack&& ST) {
    this->arr = ST.arr;
    this->arrsize = ST.arrsize;
    this->allocsize = ST.allocsize;
}

template<typename Type>
Stack<Type>::Stack() {
    if (blockArr < 1)
        throw "Error blockArr";

    arrsize = 0;
    allocsize = 0;
    arr = new Type[allocsize];
}

template<typename Type>
Stack<Type>::Stack(Type* tarr, int tarrsize) {
    if (blockArr < 1)
        throw "Error blockArr";

    arrsize = tarrsize;
    allocsize = arrsize;
    arr = new Type[allocsize];
    arr = tarr;
}


template<typename Type>
Stack<Type> Stack<Type>::operator=(Stack<Type> st) {
    arr = st.arr;
    arrsize = st.arrsize;
    allocsize = st.allocsize;
    return *this;
}

//Память пачкой по 10 выделять resize условный
template<typename Type>
void Stack<Type>::push(Type t) noexcept {
    if (arrsize >= allocsize) {
        Type* arrtemp = new Type[(allocsize + blockArr)];
        for (int i = 0; i < arrsize; i++)
            arrtemp[i] = arr[i];
        arrtemp[arrsize] = t;
        arr = new Type[(allocsize + blockArr)];
        arr = arrtemp;
        allocsize += blockArr;
    }
    else
        arr[arrsize] = t;
    arrsize += 1;
}

template<typename Type>
Type Stack<Type>::pop() {
    if (arrsize > 0) {
        Type elem = arr[arrsize - 1];

        arrsize -= 1;
        Type* arrtemp = new Type[allocsize];
        for (int i = 0; i < arrsize; i++)
            arrtemp[i] = arr[i];

        if (allocsize - blockArr >= arrsize)
            allocsize -= blockArr;
        arr = new Type[allocsize];
        arr = arrtemp;
        return elem;
    }
    else
        throw "pop(): error - array size is 0";
}

template<typename Type>
Type Stack<Type>::check_pop() const {
    if (arrsize > 0)
        return arr[arrsize - 1];
    else
        throw "check_pop(): error - array size is 0";
}

template<typename Type>
void Stack<Type>::operator<< (int n) {
    for (int i = 0; i < n; i++)
        pop();
}

template<typename Type>
void Stack<Type>::operator>> (Type t) noexcept {
    push(t);
}

template<typename X>
std::ostream& operator<< (std::ostream& out, const Stack<X>& Stack) noexcept {
    for (int i = 0; i < Stack.arrsize; i++)
        out << Stack.arr[i] << std::endl;
    return out;
}

template<typename Type>
bool Stack<Type>::empty() const noexcept {
    return (arrsize == 0);
}

template<typename Type>
int Stack<Type>::size() const noexcept {
    return arrsize;
}

template<typename Type>
void Stack<Type>::clear() noexcept {
    arrsize = 0;
    allocsize = 0;
    delete[] arr;
    arr = new Type[allocsize];
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

template<typename Type>
void Stack<Type>::top(Type t) {
    if (arrsize > 0)
        arr[arrsize - 1] = t;
    else
        throw "top(): error - array size is 0";
}

//Заменить передаваемую переменную на вершину стека, а вершину стека на передаваемую переменную (поменять местами)
template<typename Type>
void Stack<Type>::swap(Type& t) {
    if (arrsize > 0) {
        Type temp = arr[arrsize - 1];
        arr[arrsize - 1] = t;
        t = temp;
    }
    else
        throw "swap(): error - array size is 0";
}

int main() {
    try {
        //tests
    }
    catch (const char* msg) {
        cout << msg;
    }
}