#include"_list_Node.h"
template<class T>
struct iterator {
private:
	_list_node* node; //指针，指向link的结点
public:
	//constructor
	iterator() {}
	iterator(_list_node ite){node = ite;}

	bool operator ==(iterator x) { return node == x.node; }
	bool operator !=(iterator x) { return node != x.node; }
	T operator*()const { return node->data; }
	T operator->()const { return&operator*() };
	iterator& operator++() {
		link_type temp = link_type((*node).next);
		return *this;
	}
	iterator operator++(int) {
		link_type temp = node;
		++(*this);
		return temp;
	}
	iterator& operator--() {
		link_type temp = link_type((*node).prev);
		return *this;
	}
	iterator operator--(int) {
		link_type temp = link_type((*node).prev);
		--(*this);
		return 
	}
};