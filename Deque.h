#pragma once
#include <fstream> 
#include <iostream>

#pragma warning(disable : 4996)


template<typename  T>
class Deque
{
public:
    Deque();
    Deque(const Deque<T>&);
    ~Deque();

    void push_back(const T&);
    void push_front(const T&);

    void pop_back();
    void pop_front();

    T back();
    T front();

    Deque<T>& operator=(const Deque<T>&);

    bool empty();

    void clear();

    void printNormal(std::ostream&);
    void printReverse(std::ostream&);

    int size();


private:

    void Clone(const Deque<T>&);


    struct Node
    {
        T val;
        Node* next;
        Node* prev;

        Node() : next(nullptr), prev(nullptr) {};
        Node(T v, Node* l, Node* r) : val(v), prev(l), next(r) {};
        Node(Node* l, Node* r) : prev(l), next(r) {};


    };

    Node* frontElement;
    Node* backElement;
    int size_;
};




template<typename T>
Deque<T>::Deque()
{
    frontElement = new Node();
    backElement = new Node();

    frontElement->next = backElement;
    backElement->prev = frontElement;
}


template<typename T>
Deque<T>::Deque(const Deque<T>& from) : Deque()
{
    Clone(from);
}


template<typename T>
Deque<T>::~Deque()
{
    clear();
    delete frontElement;
    delete backElement;
}


template<typename T>
void Deque<T>::push_back(const T& v)
{
    size_++;
    Node* newBackElement = new Node(backElement, nullptr);
    backElement->val = v;
    backElement->next = newBackElement;
    backElement = newBackElement;
}


template<typename T>
void Deque<T>::push_front(const T& v)
{
    size_++;
    Node* newFrontElement = new Node(nullptr, frontElement);
    frontElement->val = v;
    frontElement->prev = newFrontElement;
    frontElement = newFrontElement;
}


template<typename T>
T Deque<T>::back()
{
    if (empty()) throw std::exception("Impossible to execute back: deque is empty");
    return backElement->prev->val;

}


template<typename T>
T Deque<T>::front()
{
    if (empty()) throw std::exception("Impossible to execute front: deque is empty");
    return frontElement->next->val;
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& from) {
    clear();

    Clone(from);

    return*this;
}

template<typename T>
bool Deque<T>::empty()
{
    return (size_ == 0);
}

template<typename T>
void Deque<T>::clear()
{
    Node* actualElement = frontElement->next;

    while (actualElement->next != nullptr) {
        Node* NewActualElement = actualElement->next;
        delete actualElement;
        actualElement = NewActualElement;
    }

    frontElement->next = backElement;
    backElement->prev = frontElement;
    size_ = 0;
}




template<typename T>
void Deque<T>::printNormal(std::ostream& fout)
{
    Node* actualElement = frontElement->next;

    while (actualElement->next != nullptr) {
        fout << actualElement->val << ' ';
        actualElement = actualElement->next;
    }
    fout << '\n';
}

template<typename T>
void Deque<T>::printReverse(std::ostream& fout)
{
    Node* actualElement = backElement->prev;

    while (actualElement->prev != nullptr) {
        fout << actualElement->val << ' ';
        actualElement = actualElement->prev;
    }
    fout << '\n';
}


template<typename T>
void Deque<T>::pop_back()
{
    if (empty()) return;
    size_--;

    backElement->prev->prev->next = backElement;

    Node* newPrev = backElement->prev->prev;
    delete backElement->prev;
    backElement->prev = newPrev;
}

template<typename T>
void Deque<T>::pop_front()
{
    if (empty()) return;
    size_--;

    frontElement->next->next->prev = frontElement;

    Node* newNext = frontElement->next->next;
    delete frontElement->next;
    frontElement->next = newNext;
}

template<typename T>
int Deque<T>::size()
{
    return size_;
}

template<typename T>
void Deque<T>::Clone(const Deque<T>& from)
{
    Node* actualElement = from.frontElement->next;

    while (actualElement->next != nullptr) {
        push_back(actualElement->val);
        actualElement = actualElement->next;
    }
}


Deque<const char*>::Node::Node(const char* v, Node* l, Node* r) :prev(l), next(r)
{
    val = new char[strlen(v) + 1];
    strcpy((char*)val, v);
};



