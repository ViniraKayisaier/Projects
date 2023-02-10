
#include <iostream>
template<typename T>
class Node {
public:
	Node(T iData) : m_iData(iData), mp_nodeNext(nullptr) { }
	~Node() { }
public:
	T m_iData;
	Node<T>* mp_nodeNext;

public:

	static void displayList(Node<T>* p_nodeHead)
	{
		Node<T>* p_node = p_nodeHead;

    while(p_node != nullptr)
		{
      std::cout<<p_node->m_iData<<std::endl;
      p_node = p_node->mp_nodeNext;
		}
		return;
	}
};

int main()
{
  {

    Node<int>* p_node1 = new Node<int>(10);
    Node<int>* p_node2 = new Node<int>(20);
    Node<int>* p_node3 = new Node<int>(30);


    Node<int>* p_nodeHead = p_node1;
    p_node1->mp_nodeNext = p_node2; // append p_node2 to the list of Node objects after p_node1.
    p_node2->mp_nodeNext = p_node3; // append p_node3 to the list of Node objects after p_node2.
    p_node3->mp_nodeNext = nullptr;

    Node<int>::displayList(p_nodeHead);  // display the list of nodes to standard output.
  }

  {
    Node<double>* p_node1 = new Node<double>(10.1);
    Node<double>* p_node2 = new Node<double>(20.1);
    Node<double>* p_node3 = new Node<double>(30.1);


    Node<double>* p_nodeHead = p_node1;
    p_node1->mp_nodeNext = p_node2; // append p_node2 to the list of Node objects after p_node1.
    p_node2->mp_nodeNext = p_node3; // append p_node3 to the list of Node objects after p_node2.
    p_node3->mp_nodeNext = nullptr;  

    Node<double>::displayList(p_nodeHead);  // display the list of nodes to standard output.
  }
}
