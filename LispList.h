/*
 * LispList.h
 *
 *
 *      Author: where are you now baby, faded
 *
 */

#ifndef LISPLIST_H_
#define LISPLIST_H_
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
class LispList {
	T null;
protected:
	class Node {
	public:
		T x;
		Node *next;
		Node(T x0) {
			x = x0;
			next = NULL;
		}
	};
	Node *head;
	Node *tail;
	int n;

LispList<T>&copy(Node*);


public:

LispList<T>(const LispList&);
LispList<T>& operator=(const LispList&);
LispList<T> rest();
LispList<T> append(LispList&);
template<typename T2,typename T3,typename T4>
LispList<T2> map(function<T2(T3,T4)>,LispList<T3>,int);
void print();
T first();


	LispList() {
		//null = (T)NULL;
		n = 0;
		head = tail = NULL;
	}

	virtual ~LispList() {
		Node *u = head;
		while (u != NULL) {
			Node *w = u;
			u = u->next;
			//delete w;
		}
	}

	int size() {
		return n;
	}

	T peek() {
		return head->x;
	}

	bool add(T x) {
		Node *u = new Node(x);
		if (n == 0) {
			head = u;
		} else {
			tail->next = u;
		}
		tail = u;
		n++;
		return true;
	}

	T push(T x) {
		Node *u = new Node(x);
		u->next = head;
		head = u;
		if (n == 0)
			tail = u;
		n++;
		return x;
	}

	T remove() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	T pop() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}



};
/* this codymethod  take in a node pointer of n
 *creat a new node point point to where n point to
 *if cur is not empty ,get the data that n point to
 * and use add method to add in data
 */
 template<class T>
LispList<T>&LispList<T>::copy(Node *n)
{
	Node *cur = n;
	T value;
	if(cur==NULL)
	head=NULL;
	else
{
	while (cur != NULL)
	{
	value = cur->x;
	add(value);
	cur = cur->next;
	}
}
	return *this;

}
/* copy construtor
 *initalize n equal to 0;
 *initalize head and tail equal to NULL;
 *then call the copy method to copy from other obj's head;
 */
template<class T>
LispList<T>::LispList(const LispList &obj)
{
	n=0;
	head=tail=NULL;
	copy(obj.head);
}
/*operator =
 *obj pass by reference and when this obj is not empty clear out the data
 *then call the copy method to copy form obj's head
 */
template<class T>
LispList<T>& LispList<T>::operator =(const LispList<T> &obj)
{
	Node *temp=head;
	while(temp)
	{
		head=temp->next;
		delete temp;
		temp=head;
		n--;
	}
	return copy(obj.head);
}

/*
 *  return the data in the head;
 */
template<class T>
T LispList<T>::first()
{
	 return head->x;

}
/*rest function return a newlist;
 *it create a list and let the newlist. head pointering to the calling obj
 *the tail pointing to the calling obj's tail;
 *since we don't want the head, the newlist's size =calling obj's size -1;
 */
template<class T>
 LispList<T>LispList<T>::rest()
 {
	LispList newobj;
	newobj.head=head->next;
	newobj.tail=tail;
	newobj.n=n-1;
	 return newobj;
 }
 /*display function;
  *create a new point pointing to head;
	* cout out (  at the beginning;
	* for each ward, cout out "," in between;
	* at the end cout out );
	*/
 template<class T>
 void LispList<T>::print()
{
	 Node *ptr = head;
	 if (ptr==head)
	 cout<<"(";
	 while (ptr != NULL) {
		 cout << ptr->x ;
		 if(ptr==tail)
		{
			cout<< ")";
		}
		else
		cout<<" , ";

		 ptr = ptr->next;

	 }
}
/*append function
 *create a newlist;
 *copy the obj list;
 *link the obj.head after newlist's tail;
 *and adopt the obj's tail
 *adopt the obj's size and return the newlist
 */
template<class T>
LispList<T>LispList<T>::append(LispList &obj)
{
	LispList newobj;
	newobj.copy(head);
	newobj.tail->next=obj.head;
	newobj.tail=obj.tail;
	newobj.n= size() +obj.size();

	return newobj;

}
/* map function
 * typename def 3 different type(string,int, and the other one is either one)
 *create a new list and create a node pointer pointing to obj'shead
 *while the node pointer is not empty add in the data (accpet a gentic data, and a interger)
 * the interger is used to change the data size;
 * data is being changed by the function
 * at the end return the list;
 */
template<class T> template<typename T2,typename T3,typename T4>
LispList<T2> LispList<T>::map(function<T2(T3,T4)>func, LispList<T3> obj,int index)
{
	 LispList<T2> newobj;
		Node *newptr=obj.head;
		T3 data;
		while(newptr!=NULL)
		{
			data=newptr->x;
			newobj.add(func(data,index));
			newptr=newptr->next;

		}
		return newobj;

}

#endif
