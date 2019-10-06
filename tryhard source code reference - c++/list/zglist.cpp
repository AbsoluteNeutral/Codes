#include "stdafx.h"
#include "zglist.h"

namespace zg
{
	//__________________________________________________ Capacity
	//template<typename T>
	//Node* list<T>::newNode(int value_)
	//{
	//	Node *pNode = new Node;
	//	pNode->value = value_;
	//	pNode->next = nullptr;
	//	pNode->prev = nullptr;
	//	++sz;            //count the size of list
	//
	//	return pNode;
	//}
	//
	////__________________________________________________ Class
	//template<typename T>
	//list<T>::list() noexcept
	//	:root(nullptr), sz(0)
	//{}
	//
	//template<typename T>
	//list<T>::list(const list<T>& rhs_)noexcept
	//	
	//{
	//	
	//}
	//
	//template<typename T>
	//list<T>::list(list<T>&& rhs_) noexcept
	//	
	//{
	//	
	//}
	//
	//template<typename T>
	//list<T>::~list()
	//{
	//
	//}
	//
	//template<typename T>
	//list<T>& list<T>::operator=(const list<T>& rhs_)
	//{
	//
	//	return *this;
	//}
	//template<typename T>
	//list<T>& list<T>::operator=(list<T>&& rhs_)
	//{
	//
	//	return *this;
	//}
	//
	//template<typename T>
	//void list<T>::push_front(int value_)
	//{
	//	Node* pNode = newNode(value_);	//allocate space for a Node
	//	pNode->next = root;				//point to the front of the list
	//
	//	if (root != nullptr)        //if a Node exist infront
	//		root->prev = pNode;     //point the previous list to the new list
	//
	//	root = pNode;				//set the default to the front of the list/new list
	//}
	//
	//template<typename T>
	//void list<T>::pop_front() 
	//{
	//	Node* pNodeToRemove = root;
	//	root = (list_size > 1) ? root->next : nullptr;
	//	delete pNodeToRemove;            //free current Node
	//	--list_size;                     //minus size
	//}
	//
	//template<typename T>
	//void list<T>::push_back(int value_)
	//{
	//	Node* pNode = newNode(value_); //allocate space for a Node
	//
	//	if (root)					    //if a Node exist
	//	{
	//		Node *tmp = root;			//a pointer to the front of the list
	//
	//		while (tmp->next)           //while the tail is not NULL
	//			tmp = tmp->next;        //jump to the next list/last of the list
	//
	//		tmp->next = pNode;            //anchor the last list to the new list
	//		pNode->prev = tmp;         //anchor the new list to the prev list
	//	}
	//	else
	//		the_list = pNode;           //reset the default to the front of the List
	//}
	//
	//template<typename T>
	//void list<T>::pop_back()
	//{
	//	Node* toremove = root;
	//
	//	while (toremove->next)           //travel to last Node  
	//		toremove = toremove->next;
	//
	//	if(toremove == root)
	//		root = nullptr;					//set to NULL
	//	else
	//		toremove->prev->next = nullptr; //set to NULL
	//	delete toremove;                //free Node
	//	--list_size;                    //decrease size
	//}
	//
	//template<typename T>
	//void list<T>::print() const
	//{
	//	Node* tmp = root;
	//	while (tmp)
	//	{
	//		std::cout << tmp->value << "    ";
	//		tmp = tmp->next;
	//	}
	//	std::cout << std::endl;
	//}
	//
	////__________________________________________________ Capacity
	//template<typename T>
	//bool list<T>::empty() const {
	//	return root == nullptr;
	//}
	//template<typename T>
	//unsigned list<T>::size() const {
	//	return sz;
	//}

	//__________________________________________________ Element access



} // namespace zg
