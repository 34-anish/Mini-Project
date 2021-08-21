#pragma once
#include <LinkedList.h>

template <typename T>
class Stack
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(T element) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
};

template <typename T>
class LinkedStack : public Stack<T>
{
public:
    virtual bool isEmpty() const
    {
        return this->list.isEmpty();
    }
    virtual void push(T element)
    {
        std::cout << "Pushing " << element << std::endl;
        list.addToHead(element);
    }
    virtual T top() const
    {
        if (!isEmpty())
        {
            return list.peekFromHead();
        }
        else
        {
            throw "The expression is invalid";
        }
    }

    virtual T pop()
    {
        if (!isEmpty())
        {
            T data = this->list.removeFromHead();
            std::cout << "Popping " << data << std::endl;
            return data;
        }
        else
        {
            throw "The expression is really invalid";
        }
    }

private:
    LinkedList<T> list;
};