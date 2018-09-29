template<class T>
struct  _list_node
{
	typedef _list_node<T>* void_pointer;
	void_pointer next;
	void_pointer prev;
	T data;
};