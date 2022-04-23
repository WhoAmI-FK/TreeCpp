#pragma once
#include <iostream>
#include <new>
#include <memory>
namespace trees {
	namespace {
		template<typename T>
		struct node {
		public:
			T _data;
			node* _left;
			node* _right;
		};
	};
	template<typename T,class _Alloc = std::allocator<node<T>>>
	class BinaryTree
	{
	private:
	
		typedef node<T>* branch;
		typedef _Alloc allocator_type;
		branch _root;
		size_t _numOfBranches;
		void insert(const T& data, branch& _branch) {
			if (_branch == nullptr) {
				_branch = _Alloc().allocate(1);
				_numOfBranches++;
				return;
			}
			if (data > _branch->_data) {
				insert(data, _branch->_right);
			}
			if (data < _branch->_data) {
				insert(data, _branch->_left);
			}
		}
	public:
		explicit BinaryTree()
			: _root(nullptr),_numOfBranches(0)
		{

		}
		explicit BinaryTree(const T& data) 
		{
			_root = _Alloc().allocate(1);
			_root->_data = data;
			_root->_left = nullptr;
		}
		void insert(const T& data) {
			insert();
		}
	};
}

