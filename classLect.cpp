#include <iostream>

template<class T>
class Tree {
private:
    struct node {
        T _data;
        node* _left;
        node* _right;
        node(T data,node* left = nullptr,node* right = nullptr)
            : _data(data),_left(left),_right(right) {}
    };
    node<T>* _root;
    int _count;
    void destroy(node<T>*& parent) {

    }
    void insert(const T& val, node*& parent) {
        if (parent == nullptr) {
            parent = new node<T>(val);
            _count++;
            return;
        }
        if (val > parent->_data) {
            insert(val, parent->_right);
        }
        if (val < parent->_data) {
            insert(val, parent->_left);
        }
    }

public:
    Tree() : _root(nullptr), _count(0) {}
    ~Tree() {
        destroy(_root);
    }
    void insert(const T& val) {

    }
};


int main()
{
    std::cout << "Hello World!\n";
}
