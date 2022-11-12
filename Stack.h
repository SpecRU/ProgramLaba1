#include <iostream>
#include <fstream>

template<typename T>

class Stack {
private:
    T* arr;
    int arrsize;
    int allocsize;
public:
    Stack();
    Stack(const Stack& A); //Копирование
    Stack(T* T_arr, int T_arrsize); //Список
    Stack(Stack&& A); //Перемеещение
    ~Stack() = default;
    Stack<T> operator=(Stack<T> A);
    void push(T t) noexcept;
    T pop();
    T check_pop() const;
    void operator<< (int n);
    void operator>> (T t) noexcept;
    template<typename X>
    friend std::ostream& operator<< (std::ostream& out, const Stack<X>& Stack) noexcept;
    bool empty() const noexcept;
    int size() const noexcept;
    void clear() noexcept;
    template<typename X>
    friend bool operator== (Stack<X>& St1, Stack<X>& St2) noexcept;
    template<typename X>
    friend bool operator!= (Stack<X>& St1, Stack<X>& St2) noexcept;
    void top(T t);
    void swap(T& t);
};