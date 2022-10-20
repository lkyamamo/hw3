#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> list;
};

template <typename T>
bool Stack<T>::empty() const{
    if(list.size() == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
size_t Stack<T>::size() const{
    return this -> list.size();
}

template <typename T>
void Stack<T>::push(const T& item){
    list.push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(list.size() == 0){
        throw std::underflow_error("underflow_error");
    }else{
        list.pop_back();
    }
    
}

template <typename T>
const T& Stack<T>::top() const{
    if(list.size() == 0){
        throw std::underflow_error("underflow_error");
    }else{
        return list.back();
    }
}

#endif