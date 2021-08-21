#pragma once
template <typename T>
class Node
{
public:
    T info;
    Node<T> *next;

    Node() : next(nullptr) {}

    Node(Node<T> info, Node<T> *next) : info(info), next(next) {}
};

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
        HEAD = nullptr;
        TAIL = nullptr;
    }
    ~LinkedList()
    {
        delete TAIL;
    }

    bool isEmpty() const
    {
        return HEAD == nullptr && TAIL == nullptr;
    }
    void addToHead(const T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->info = data;
        newNode->next = this->HEAD;
        this->HEAD = newNode;
        if (this->TAIL == nullptr)
        {
            this->TAIL = this->HEAD;
        }
    }
    void traverse(const char separator) const
    {
        if (isEmpty())
        {
            std::cout << "List is empty!" << std::endl;
        }
        else
        {
            std::cout << "List contains: " << std::endl;
            Node<T> *tempNode = HEAD;
            while (tempNode != nullptr)
            {
                std::cout << tempNode->info << separator;
                tempNode = tempNode->next;
            }
            std::cout << std::endl;
        }
    }
    T peekFromHead() const
    {
        if (!isEmpty())
        {
            return this->HEAD->info;
        }
        else
        {
            throw "The list is empty";
        }
    }

    T removeFromHead()
    {

        T data;
        if (!isEmpty())
        {
            Node<T> *nodeToDelete = this->HEAD;
            data = nodeToDelete->info;
            this->HEAD = this->HEAD->next;

            if (this->HEAD == nullptr)
            {
                this->TAIL = nullptr;
            }

            delete nodeToDelete;
        }
        else
        {
            throw "List is empty";
        }
        return data;
    }

private:
    Node<T> *HEAD;
    Node<T> *TAIL;
};
