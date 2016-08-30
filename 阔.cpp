#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T _data;
	Node* next;
	Node(const T& d)
		:_data(d)
		,next(NULL)
	{}
};

template <class T>
class LinkList
{
public:
	LinkList()
		:_head(NULL)
		,_tail(NULL)
	{}

	~LinkList()
	{
		if(_head == NULL)
	{}
	else if((_head == _tail)&&(_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node<T>* cur = _head;
		Node<T>* del = _head;
		while(cur)
		{
			del = cur;
			cur = cur->next ;
			delete del;
		}
	}
	}

public:
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	void Display();
	int ListLen();
	void Insert(const int& pos,const T& d);
	void Del_Insert(const int& pos);


private:
	Node<T>* _head;
	Node<T>* _tail;
};

template <class T>
void LinkList<T>::PushBack (const T& d)
{
	if(_head == NULL)
	{
		Node<T>* cur = new Node<T>(d);
		_head = cur;
		_tail = cur;
	}
	else
	{
		Node<T>* cur = new Node<T>(d);
		Node<T>* tmp = _head;

		while(tmp->next )
		{
			tmp = tmp->next ;
		}
		tmp->next = cur;
		_tail = cur;
	}

}


template <class T>
void LinkList<T>::PopBack ()
{
	if(_head == NULL)
	{
		return ;
	}
	else if((_head == _tail)&&(_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		/*delete _tail;   
		_tail = NULL;    //只是转移了_tail的指向，使其指向了NULL，并没有改变链表最后一个节点为NULL
		Node<T>* cur = _head;
		while(cur->next)
		{
			cur = cur->next;
		}
		_tail = cur;*/
		Node<T>* cur = _head;
		while(cur->next)
		{
			_tail = cur;
			cur = cur->next;
		}
		delete cur;
		_tail->next = NULL;
		
	}
}

template <class T>
void LinkList<T>::PushFront(const T& d)
{
	if(_head == NULL)
	{
		Node<T>* cur = new Node<T>(d);
		_head = cur;
		_tail = cur;
	}
	else 
	{
		Node<T>* cur = new Node<T>(d);
		cur->next = _head;
		_head = cur;
	}
}

template <class T>
void LinkList<T>::PopFront ()
{
		if(_head == NULL)
	{
		return ;
	}
	else if((_head == _tail)&&(_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node<T>* cur = _head;
		_head = _head->next ;
		delete cur;
	}
}

template <class T>
void LinkList<T>::Display()
{
	Node<T>* cur = _head;
	while(cur )
	{
		cout<<cur->_data <<" ";
		cur = cur->next ;
	}
	cout<<endl;
}
template <class T>
int LinkList<T>::ListLen()
{
	int count = 0;
	Node<T>* cur = _head;
	while(cur)
	{
		count++;
		cur= cur->next ;
	}
	return count;
}


template <class T>
void LinkList<T>:: Insert(const int& pos,const T& d)
{
	int num  = pos;
	if(num > ListLen()+1 )
	{
		cout<<"NULL 链表"<<endl;
		return ;
	}
	else
	{
		Node<T>* cur = new Node<T>(d);
		if(num == 1)
		{
			cur->next = _head;
			_head = cur;
		}
		else
		{
			Node<T>* tmp1 = _head;
			Node<T>* tmp2 = _head;
			while(--num)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next ;
				
			}
			cur->next = tmp1;
			tmp2->next = cur;
			//_head->next = cur;  应该是tmp的上一个节点指向cur
		}
	}

}
template <class T>
void LinkList<T>::Del_Insert(const int& pos)
{
	int num  = pos;
	if(_head == NULL)
	{
		cout<<"NULL 链表"<<endl;
		return ;
	}
	else if((_head == _tail)&& (_head != NULL))
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node<T>*  cur = _head ;
		if(num == 1)
		{
			_head= _head ->next ;
			delete cur;
		}
		else 
		{
			Node<T>* tmp1 = _head;
			Node<T>* tmp2 = _head;
			while(--num)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next ;
			}
			tmp2->next = tmp1->next ;
			delete tmp1;

		}

	}
}

void test()
{
	LinkList<int> l1;
	l1.PushBack (1);
	l1.PushBack (2);
	l1.PushBack (3);
	l1.PushBack (4);
    l1.PushBack (5);
	l1.PopBack ();
	l1.PushFront (0);
	l1.PopFront ();
	l1.Display ();
	l1.PushFront (5);
	l1.Display ();
	cout<<"Listlen:"<<l1.ListLen ()<<endl;
	
	l1.Insert (1,6);
	l1.Display ();
	l1.Insert (2,7);
	l1.Display ();
	l1.Insert (8,8);
	l1.Display ();
	cout<<"Listlen:"<<l1.ListLen ()<<endl;
	
	l1.Del_Insert (1);
	l1.Display ();
	cout<<"Listlen:"<<l1.ListLen ()<<endl;

}

int main()
{

	test();
	return 0;

}