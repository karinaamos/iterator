#pragma once
#include <iostream>
#include <iterator>

template <class T>
struct Node{
    T data; //Данные, которые хранит узел
    Node<T>* next=nullptr; // Указатель на следующий узел в списке
    // Конструктор, который принимает значение для 'data'
    Node(T data) : data(data) {}
};

template <class T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag; // Определяем категорию итератора: forward_iterator (однонаправленный)
    using difference_type = std::ptrdiff_t; // Определяем тип для разности между итераторами (обычно для вычисления расстояния)
    using value_type = Node<T>; // Определяем тип значения, на которое указывает итератор (узел списка)
    using pointer=  Node<T>*; // Определяем тип указателя на узел списка
    using reference =  Node<T>&; // Определяем тип ссылки на узел списка
    ListIterator(pointer node):_node(node){}; // Определяем конструктор итератора: принимает указатель на узел и инициализирует _node
    reference operator*()const{return *_node;}; // Перегружаем оператор * (разыменование): возвращает ссылку на узел, на который указывает итератор
    pointer operator->(){return _node;}; // Перегружаем оператор -> (доступ к члену): возвращает указатель на узел, на который указывает итератор
    ListIterator operator++(int){ // Перегружаем постфиксный оператор ++ (инкремент)
        ListIterator tmp=*this; // Создаем временную копию текущего итератора
        ++(*this); // Увеличиваем текущий итератор (вызываем префиксный инкремент)
        return tmp; // Возвращаем временную копию (старое значение итератора)
    };
    ListIterator& operator++(){ // Перегружаем префиксный оператор ++ (инкремент)
        _node = _node->next; // Перемещаем итератор на следующий узел в списке
        return *this; // Возвращаем ссылку на текущий итератор
    }
    friend bool operator==(const ListIterator& a,const ListIterator& b){ // Дружественная функция для перегрузки оператора == (равенство)
        return a._node==b._node; // Сравниваем указатели на узлы, на которые указывают итераторы
    }
    friend bool operator!=(const ListIterator& a,const ListIterator& b){ // Дружественная функция для перегрузки оператора != (неравенство)
        return a._node!=b._node; // Сравниваем указатели на узлы, на которые указывают итераторы
    }
private: // Объявляем приватные члены структуры (доступны только внутри структуры)
    pointer _node; // Указатель на текущий узел списка, на который указывает итератор
};

template <class T>
class MyForwardList{
private:
    Node<T>* _head = nullptr; // Указатель на первый элемент списка
    Node<T>* _tail = nullptr; // Указатель на последний элемент списка
public:
    MyForwardList() = default; // Добавлен конструктор по умолчанию
    MyForwardList(T elem){
        _head = new Node<T>(elem); //первый узел
        _tail = _head; //первый узел является и началом и концом
    }

    void Add(Node<T>* new_node){
        if (new_node == nullptr) { // Проверяем, не является ли указатель на новый узел нулевым
            return; // Если указатель нулевой, выходим из функции (ничего не добавляем)
        }

        new_node->next = nullptr; // Устанавливаем указатель next нового узла в nullptr (чтобы он стал последним в списке)

        if (_head == nullptr) { // Если список пуст
            _head = new_node; // Новый узел становится головой списка
            _tail = new_node; // Новый узел становится хвостом списка
        } 
        else { // Если список не пуст
            _tail->next = new_node; // Добавляем новый узел в конец списка (указатель next текущего хвоста указывает на новый узел)
            _tail = new_node; // Обновляем указатель на хвост (новый узел становится хвостом)
        }
    }

    void Delete(Node<T>* node){
        if (_head == nullptr || node == nullptr) { // Проверяем, пуст ли список или является ли указатель на удаляемый узел нулевым
            return; // Если список пуст или указатель нулевой, выходим из функции (ничего не удаляем)
        }

        if (_head == node) {
            _head = _head->next;
            if (_head == nullptr) {
                _tail = nullptr;
            }
            delete node;
            return;
        }

        Node<T>* current = _head;
        while (current->next != nullptr && current->next != node) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return;
        }

        current->next = node->next;

        if (_tail == node) {
            _tail = current;
        }

        delete node;
    }

    ListIterator<T> begin(){
        return ListIterator<T>(_head);
    }

    ListIterator<T> end(){
        return ListIterator<T>(nullptr);
    }

    ~MyForwardList() {
        Node<T>* current = _head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        _head = nullptr;
        _tail = nullptr;
    }

    void printList() {
        for (ListIterator<T> it = begin(); it != end(); ++it) {
            std::cout << it->data << " ";
        }
        std::cout << std::endl;
    }
};