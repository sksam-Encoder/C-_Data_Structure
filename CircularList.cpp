#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{

private:
public:
	int D;
	int key;
	Node *n;

	Node()
	{

		key = 0;
		D = 0;
		n = NULL;
	}

	Node(int k, int d)
	{
		this->key = k;
		D = d;
		n = NULL;
	}
};

class CircularList
{

private:
	Node *head;

public:
	CircularList()
	{

		head = NULL;
	}
	//		 Check if a particluar list exist or not using key

	Node *isExist(int k)
	{
		Node *ptr, *temp = NULL;
		if (head == NULL)
		{
			return head;
		}
		else
		{
			ptr = head;

			do
			{

				if (ptr->key == k)
				{

					temp = ptr;
				}
				ptr = ptr->n;

			} while (ptr != head);
			return temp;
		}
	}

	void insertLast(Node *new_node)
	{

		if (isExist(new_node->key) != NULL)
		{

			cout << "node exists with a key value: "
				 << new_node->key
				 << "add another node with diffrent key"
				 << endl;
		}
		else
		{

			if (head == NULL)
			{

				head = new_node;
				new_node->n = head;
				cout << "node append at a head position"
					 << endl;
			}
			else

			{

				Node *ptr = head;
				while (ptr->n != head)
				{
					/* code */

					ptr = ptr->n;
				}

				ptr->n = new_node;
				new_node->n = head;
				cout << "node appended"
					 << endl;
			}
		}
	}
	// insertion node with specific key
	void insertAfter(int k, Node *new_node)
	{

		Node *ptr = isExist(k);

		if (isExist(new_node->key) != NULL)
		{
			cout << "node exists with a key value: "
				 << new_node->key
				 << "add another node with diffrent key"
				 << endl;
		}
		else
		{

			if (ptr->n == head)
			{

				ptr->n = new_node;
				new_node->n = head;
				cout << "Insertion happens at end" << endl;
			}
			else
			{

				new_node->n = ptr->n;

				ptr->n = new_node;

				cout << "Insertion happens at Between" << endl;
			}
		}
	}
	// Delete Node by unique key.

	void DeleteNode(int key)
	{

		Node *ptr = isExist(key);
		if (isExist(key) == NULL)
		{

			cout << "Node Does not Exist with key :"
				 << key << endl;
		}
		else
		{

			if (ptr == head)
			{

				if (head->n == head) // it means one node
				{

					Node *temp = head;

					head = NULL;
					free(temp);
					cout << "Node Deleted ...List Empty"
						 << endl;
				}

				else
				{
					Node *ptr1 = head;
					while (ptr1->n != NULL)
					{

						ptr1 = ptr1->n;
					}
					Node *temp = head;
					ptr1->n = head->n;
					head = head->n;
					free(temp);
					cout << "First Node is Deleted:"
						 << endl;
				}
			}
			else
			{
				//				delete  Other Node..

				Node *pre_ptr = head;
				Node *temp = NULL;
				Node *del_ptr = head->n;

				while (del_ptr != NULL)
				{

					if (del_ptr->key == key)
					{

						temp = del_ptr;
						del_ptr = NULL;
					}
					else
					{

						pre_ptr = pre_ptr->n;
						del_ptr = del_ptr->n;
					}
				}

				pre_ptr->n = temp->n;
				free(temp);
				cout << "node delete with key value:"
					 << key << endl;
			}
		}
	}

	//
	void UpdateNode(int k, int new_data)
	{
		Node *ptr = isExist(k);
		if (ptr == NULL)
		{

			cout << "Node doesnot exist with key "
				 << k << endl;
		}
		else
		{

			ptr->D = new_data;
			cout << "Data Updated Sucessfully in key :"
				 << ptr->key << endl;
		}
	}

	//		  print List

	void print_l()
	{

		if (head == NULL)
		{

			cout << "List Is Empty";
		}
		else
		{

			Node *temp = head;

			do 
			{

				cout << temp->D
					 << " "
					 << endl;

				temp = temp->n;	 
			}while (temp !=  head);
		}
	}

	void prependNode(int key, Node *node)
	{

		if (isExist(node->key) != NULL)
		{

			cout << "node exists with a key value: "
				 << node->key
				 << "add another node with diffrent key"
				 << endl;
		}
		else
		{

			if (head == NULL)
			{

				node->key = key;
				head = node;
				node->n = head;
			}
			else
			{

				Node *ptr = head;

				while (ptr->n != head)
				{

					ptr = ptr->n;
				}

				ptr->n = node;
				node->n = head;
				head = node;
			}
		}
	}
};

int main()
{

	CircularList obj; // methods contain and head pointer.
	int option;
	int key,k1, data;

	do
	{

		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl
			 << endl;

		cin >> option;

		Node *n1 = new Node; // Structure of node

		switch (option)
		{

		case 1:
			cout << "Enter the key of node: "
				 << endl;
			cin >> key;
			cout << "enter data for append: " << endl;
			cin >> data;
			n1->key = key;
			n1->D = data;
			obj.insertLast(n1);

			break;

		case 2:
			cout << "Enter the key of node: "
				 << endl;
			cin >> key;
			cout << "enter data for prepend: " << endl;
			cin >> data;
			n1->key = key;
			n1->D = data;
			obj.prependNode(key,n1);

			break;

		case 3:

			cout << "Enter the key of node: "
				 << endl;
			cout << "Enter key for after Insertion: "
				 << endl;
			cin>> k1;	 

			cin >> key;
			cout << "enter data for insert nth: " << endl;
			cin >> data;
			n1->key = key;
			n1->D = data;
			obj.insertAfter(k1,n1);

			break;


		case 4:
				cout << "Enter the key of node for deletion: "
				 << endl;
				cin>> key; 

				obj.DeleteNode(key);

		break;


		case 5:

			cout<<"enter key for updation & and new data "<< endl;
			cin>> key >>data ;
			
			obj.UpdateNode(key,data);	
			cout<<"value updated for key: "
			<<key
			<<endl;	

		break;

			case 6:

			obj.print_l();

			break;

			case 7:

			system("cls");	


		}

	} while (option != 0);

	return 0;
}
