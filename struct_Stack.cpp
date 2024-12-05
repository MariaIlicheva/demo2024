#include <iostream>
#include <fstream>

template<typename T>
struct Stack {

    T * items;
    int count;
    int topIndex;

    void Resize() {
        count *= 2;
        T* new_items = new T[count]; 
        for (int i = 0; i <= topIndex; ++i) {
            new_items[i] = items[i];
        }
        delete[] items;
        items = new_items; //перенаправляем указатель 
    }

    Stack(int size = 10) 
        : count(size), topIndex(-1) {
        //конструктор
        items = new T[size];
    }
    ~Stack() {
        //деструктор
        delete[] items;
    }

    void push(T item) {
        if (topIndex + 1 == count) {
            Resize();
        }
        items[++topIndex] = item;
    }
    
    void pop() {
        if (is_empty()) {
            throw "out of range";
        }
        --topIndex;
    }
    
    T peek() {
        //выдать верхушку
        if (is_empty()) {
            throw "out of range";
        }
        return items[topIndex];
    }
    bool is_empty() {
        return topIndex == -1;
    }

    int get_size() {
        return topIndex + 1;
    }
};

int main() {
    Stack <int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.peek() << std::endl;
    std::cout << stack.get_size() << std::endl;
    stack.pop(); 
    std::cout << stack.peek() << std::endl;

    return 0;
}
