
#pragma once
#include <iostream>
#include <iterator>

template <class T>
class Node{
    T data;
    Node* next;
};

template <class T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Node<T>;
    using pointer=  Node<T>*;
    using reference =  Node<T>&;
    ListIterator(Node<T>* node);
    ListIterator(pointer node):_node(node){};
    reference operator*()const{return *_node;};
    pointer operator->(){return _node;};
    ListIterator operator++(int){
        ListIterator tmp=*this;
        ++(*this);
        return tmp;
    };
    ListIterator& operator++(){
        _node = _node.next;
        return *this;
    }
    friend bool operator==(const ListIterator& a,const ListIterator& b){
        return a._node==b._node;
    }
    friend bool operator!=(const ListIterator& a,const ListIterator& b){
        return a._node!=b._node;
    }
private:
    pointer _node;
};

template <class T>
class MyForwardList{
private:
    Node<T> _head;
public:
    MyForwardList(T elem){
        _head = {data = elem, next = nullptr};
    }

    void Add(Node<T> new_node){
        Node<T> tmp = _head;
        while(tmp -> next != nullptr){
            tmp.next++;
        }
        tmp.next = new_node;
    }

    void Delete(Node<T> node){
        Node<T> tmp = _head;
        while (*tmp.next != node){
            tmp.node++;
        }
        tmp.next = node.next;
        
    }

};