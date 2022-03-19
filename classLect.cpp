#include <iostream>
#include <list>
namespace whoamifk_tree {
    template<class T>
    struct node {
        T _data;
        node* _left;
        node* _right;
        node(T data, node* left = nullptr, node* right = nullptr)
            : _data(data), _left(left), _right(right) {}
    };
    template<class T>
    class Tree {
    private:
        node<T>* _root;
        int _count;
        void destroy(node<T>*& parent) {
            if (parent == nullptr)
                return;
            destroy(parent->_left);
            destroy(parent->_right);
            delete parent;
            _count--;
            parent = nullptr;
        }
        void insert(const T& val, node<T>*& parent) {
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
        void push(std::list<T>& mylist, node<T>* parent) {
            if (parent == nullptr)
                return;
            mylist.push_front(parent->_data);
            push(mylist, parent->_left);
            push(mylist, parent->_right);
        }
        void erase(const T& val, node<T>*& parent) {
            if (parent == nullptr) {
                throw std::invalid_argument("Such value does not exists.");
                return;
            }
            if (val == parent->_data) {
                std::list<T> mylist;
                push(mylist, parent->_left);
                push(mylist, parent->_right);
                destroy(parent);
                for (auto it = mylist.begin(); it != mylist.end(); ++it)
                    insert(*it, parent);
            }
            else if (val < parent->_data)
                erase(val, parent->_left);
            else erase(val, parent->_right);
        }
        bool search(const T& val, node<T>* parent) const
        {
            if (parent == nullptr)
                return false;
            if (val == parent->_data)
                return true;
            if (val > parent->_data)
                return search(val, parent->_right);
            if (val < parent->_data)
                return search(val, parent->_left);
        }
    public:
        Tree() : _root(nullptr), _count(0) {}
        ~Tree() {
            destroy(_root);
        }
        void insert(const T& val) {
            insert(val, _root);
        }
        void erase(const T& val) {
            erase(val, _root);
        }
        bool search(const T& val) const
        {
            return search(val, _root);
        }
        int size() const {
            return _count;
        }
        bool empty() const {
            return _count == 0;
        }
    };

}
int main()
{
    try {
        // Your code
    }
    catch (std::exception e) {
        std::cout << "\n\n" << e.what() << std::endl;
    }
    return 0;
}
