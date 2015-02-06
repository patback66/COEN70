#ifndef	_PRIOQUEUE_H_
#define	_PRIOQUEUE_H_

template <class T>
class PriorityQueue {
	protected:
		class node {
			public:
				node(const T& d = T(), int priority = 0, node* n = NULL) : _data(d), _priority(priority), _next(n) {};
				T _data;
				int _priority;
				node* _next;
		};
		node* _head;
		node* _tail;
		long _size;
	public:
		PriorityQueue(){
			_size = 0;
			//Create a dummy node
			_head = new node(0);
			_tail = _head;
		};
		~PriorityQueue(){
			node* p = _head;
			while (p != NULL) {
				node* t = p;
				p = p -> _next;
				delete t;
			}
			_head = NULL;
			_tail = NULL;
		};
		
		virtual void push(const T& value, int priority) {
			node* target = _head;
			if (_size > 0)
			{
				while(target -> _next != NULL) {
					if (target -> _next -> _priority < priority)
					{
						break;
					}
					target = target -> _next;
				}
			}
			node* p = new node(value, priority, target -> _next);
			target -> _next = p;
			_size ++;
			if (target == _tail)
			{
				_tail = p;
			}
		};
		virtual T pop() {
			node *p = _head -> _next;
			
			if (p == NULL) {
				throw "Empty Header";
			}

			if (p == _tail)
			{
				_tail = _head;
			}

			//Adjust the list
			_head -> _next = p -> _next;
			
			T value = p -> _data;
			
			//Since the p is no longer needed, free it.
			delete p;
			
			//Update Size.
			_size --;
			
			return value;
		};
		virtual long size() {
			return _size;
		};
};

#endif