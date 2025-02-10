#include <iostream>

class IntArr{
private: 
    int _data[99];
public: 
    struct Iterator{
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;        
    private:
        pointer _ptr;
    public:
        Iterator(pointer ptr):_ptr(ptr){}
        reference operator*() const;
        pointer operator->();
        Iterator operator++(int);
        Iterator& operator++();
        friend bool operator==(const Iterator& a, const Iterator& b);
        friend bool operator!=(const Iterator& a, const Iterator& b);
    };
    
};