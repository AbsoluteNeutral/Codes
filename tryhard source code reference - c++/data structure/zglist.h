#ifndef _ZG_LIST_H
#define _ZG_LIST_H

namespace zg 
{
	//__________________________________________________ Class
	template<typename T>
	class ZG_API list
	{
		struct Node {
			T value;
			Node* next;
			Node* prev;
		};

		Node* newNode(int value_)
		{
			Node *pNode = new Node;
			pNode->value = value_;
			pNode->next = nullptr;
			pNode->prev = nullptr;
			++sz;            //count the size of list
		
			return pNode;
		}

	public:
		list	() noexcept
			:root(nullptr), sz(0)
		{}
		list(const list& rhs_) noexcept
			:root(nullptr), sz(0)
		{
			Node* tmp = rhs_.root;
		}
		list(list&& rhs_) noexcept
			:root(rhs_.root), sz(0)
		{
			rhs_.root = nullptr;
			rhs_.sz = 0;
		}
		~list()
		{
			clear();
		}

		list& operator=	(const list& rhs_);
		list& operator=	(list&& rhs_);

		void print() const
		{
			Node* tmp = root;

			while (tmp)
			{
				std::cout << tmp->value << "--> ";
				tmp = tmp->next;
			}
			std::cout << std::endl;
		}
		bool empty() const;
		unsigned size() const;

		//__________________________________________________ Modifiers:
		void clear()
		{
			while (root) 
			{
				Node* pNode = root;
				root = root->next;
				delete pNode;
			}
			sz = 0;
			root = nullptr;
		}
		void push_front(T value_)
		{
			Node* pNode = newNode(value_);	//allocate space for a Node
			pNode->next = root;				//point to the front of the list
			if (root)						//if a Node exist infront
				root->prev = pNode;			//point the previous list to the new list
			root = pNode;					//set the default to the front of the list/new list
		}
		void pop_front()
		{
			Node* toRemove = root;
			root = root ? root->next : nullptr;

			delete toRemove;            //free current Node
			--sz;						//minus size
		}
		void push_back(T value_)
		{
			Node* pNode = newNode(value_); //allocate space for a Node
		
			if (root)					    //if a Node exist
			{
				Node *tmp = root;			//a pointer to the front of the list
		
				while (tmp->next)           //while the tail is not NULL
					tmp = tmp->next;        //jump to the next list/last of the list
		
				tmp->next = pNode;            //anchor the last list to the new list
				pNode->prev = tmp;         //anchor the new list to the prev list
			}
			else
				root = pNode;           //reset the default to the front of the List
		}
		void pop_back()
		{
			Node* toremove = root;
			while (toremove->next)				//travel to last Node  
				toremove = toremove->next;

			if (toremove == root)
				root = nullptr;					//set to NULL
			else
				toremove->prev->next = nullptr; //set to NULL

			delete toremove;                //free Node
			--sz;                    //decrease size
		}
		void insert(unsigned pos, T value_) 
		{
			//if out of bound
			if (pos > sz) 
			{
				push_back(value_);
				return;
			}

			Node* pNewNode  = newNode(value_);   //new node to insert
			Node* pNextNode = root;          //a tmp Node to find the position

			while (pNextNode && pos--)
				pNextNode = pNextNode->next;       //point to next list

			if (pNextNode->next != nullptr)       //if the next pointer is not null
			{
				Node *pPrevNode = pNextNode->prev; //Get previous Node

				if (pPrevNode != nullptr)
				{
					pNextNode->prev = pNewNode;       //anchor last list to new node
					pPrevNode->next = pNewNode;       //anchor prev list to new node
					pNewNode->next = pNextNode;       //anchor new list to last node
					pNewNode->prev = pNextNode->prev; //anchor new list to prev node
				}
				else if (pPrevNode == nullptr)
				{
					the_list = pNewNode;           //Set defalut to front of the list
					pNextNode->prev = pNewNode;   //anchor last list to new node
					pNewNode->next = pNextNode;   //anchor new list to last node
				}
			}
			else if (pNextNode->next == nullptr)
			{
				pNewNode->prev = pNextNode;     //anchor new list to prev node
				pNextNode->next = pNewNode;     //anchor prev list to new node
			}
		}
		//__________________________________________________ Capacity


		//__________________________________________________ Element access
		T& front() const {
			return root->value;
		}
		T& front() {
			return root->value;
		}
		
	private:
		Node* root;
		unsigned sz;
		
		
	};

} // namespace zg



#endif //_UNITSTEST
