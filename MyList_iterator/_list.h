//#include"_list_iterator.h"
//#include"_list_node.h"
#include<iostream>
template<class T>
class list {
public:
	//		         head->Node1->Node2->......Noden->tail
	//		  		 next ->  next  ->  next  ->......  next  ->tail->NULL
	//NULL<-  prev<-  prev  <- prev   <-...... prev  
	struct  Node
	{
		Node* next;
		Node* prev;
		T data;
		Node(T s = 0, Node* n = NULL, Node* p = NULL) :data(s), next(n), prev(p) {};
	};
	//iterator
	class iterator {
	private:
		Node* cur; //ָ�룬ָ��link�Ľ��
	public:
		friend class list;   //��list����Ϊiterator����Ԫ��ʹlist���Է���iterator��private
		explicit iterator(Node* p=0) {cur = p; }
		bool operator ==(iterator& x) { return (*this).cur == x.cur; }
		bool operator !=(iterator& x) { return (*this).cur != x.cur; }
		T operator*() { return cur->data; }
		//�����д��һ�������ǿ���ʹ�ñ�д����ȫ�ֺ���
		//ostream operator<<(ostream& os,const iterator& it)
		//��ʵ��display()�еġ�cout<<*iterator;��
		iterator& operator++() {  //ǰ׺++
			cur = cur->next;
			return *this;
		}
		iterator operator++(int) { //��׺++
			iterator temp = *this;
			++(*this);
			return temp;
		}
		iterator& operator--() {
			cur = cur->prev;
			return *this;
		}
		iterator operator--(int) {
			iterator temp = *this;
			--(*this);
			return temp;
		}
		Node* operator->() {
			return cur;
		}
	};
	//_list�ĵ�����
private:
	Node * head,*tail;
	int _size;
	void createlist() {
		_size = 0;
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
public:
	list() {
		createlist();
	}
	~list() {
		while (!empty()) {
			pop_front();
		}
		delete head;
		delete tail;
	}
	bool empty()const { return _size == 0; };
	iterator begin() {
		return iterator(head->next);
	}
	iterator end() {
		return iterator(tail);
	}
	iterator insert(iterator pos, const T& value) { 
		//const T& value ��const ��ֹ�������ñ��޸ģ����ô����൱�ڴ���ָ�룬8�ֽ� 
		//��ֵ���ݻ���ø��ƹ��캯����ռ���ڴ��
		Node* p = new Node(value, pos.cur, pos.cur->prev);
		_size++;
		p->prev->next = p;
		pos.cur->prev = p;
		return iterator(p);
		//dalaoд��: return iterator(p->prev = p->prev->next = new Node(val, p, p->prev));
	}
	iterator erase(iterator pos) {
		Node* p = pos.cur;
		iterator newite(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		_size--;
		return newite;
	}
	void push_back(const T& value) {
		insert(end(), value);
	}
	void push_front(const T& value) {
		insert(begin(), value);
	}
	void pop_front() {
		erase(begin());
	}
	void pop_back() {
		erase(--end());
	}
};