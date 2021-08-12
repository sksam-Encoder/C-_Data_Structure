#include <iostream>
#include<stdlib.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Dnode
{
private:
	Dnode *p1;
	Dnode *p2;
	int info;
	//	static Dnode *start;
public:
	Dnode()
	{
		p1 = NULL;
		p2 = NULL;
		info = 0;
	}

	/*	
			for static header pointer.
void insertLast(int item){
//		if (start == NULL)
//	{
//		
//	}
}*/

	//  normal d linklist code  insertBeg..

	void insertBeg(Dnode **head, int item)
	{
		Dnode last;
		last.info = item;

		if (*head == NULL)
		{
			last.p1 = NULL;
			last.p2 = NULL;
		}
		else
		{

			last.p2 = *head;
			last.p1 = NULL;
			*head = &last;
		}
	}
	//    insertBeg..
	// ----- InsertLast.....

	void insertLast(Dnode **head, int item)
	{
		//		Dnode node;
		// you can't have incomplete types as members,
		// only reference or pointers to them,
		//and that A is an incomplete type until the end of the class
		Dnode *node = new Dnode();

		node->info = item;

		if (*head == NULL)
		{
			node->p1 = NULL;
			node->p2 = NULL;
			*head = node;
			cout << "happens";
		}
		else
		{
			Dnode *temp;
			temp = *head;
			while (temp->p2 != NULL)
			{

				temp = temp->p2;
			}

			//got the add of last node

			temp->p2 = node;
			node->p1 = temp;
			node->p2 = NULL;
		}
	}

	// ---x-- insertLast...x..

	//  Traversing Node

	void dispNode(Dnode **head)
	{

		if (*head == NULL)
		{
			cout << "empty list";
		}
		else
		{

			Dnode *temp;
			temp = *head;
			while (temp->p2 != NULL)
			{

				cout << temp->info << "\n";
				temp = temp->p2;
			}

			cout << temp->info << "\n";
		}
	}
	//   traversing--------------Ends

	//Insert at Nth Position

	void insertNth(Dnode **head, int item)
	{
		int pos;
		Dnode *temp;
		temp = *head;
		Dnode *node = new Dnode();
		cout << "which position do we want to insert";
		cin >> pos;
		for (int i = 1; i <= pos - 2; i++)
		{

			temp = temp->p2;
		}

		node->p1 = temp;
		node->p2 = temp->p2;
		temp->p2 = node;
		node->info = item;
	}

	//---Delete Nth-----------------------------------------------------------------

	void DeleteNth(Dnode **Head)
	{

		if (*Head == NULL)
		{

			cout << "Error\n";
		}
		else
		{

			int pos;
			Dnode *temp;
			temp = *Head;
			cout << "which position do we want to Delete";
			cin >> pos;
			for (int i = 1; i <= pos - 1; i++)
			{

				temp = temp->p2;
			}

			Dnode *dele;
			dele = temp;

			temp->p1->p2 = temp->p2;
			temp->p2->p1 = dele->p1;
			free(temp);
		}
	}

	//---Delete Nth-----------------------------------------------------------------
};

int main()
{

	Dnode *head = NULL;
	Dnode lis;

	while (1)
	{

		int ch, item;
		cout << "0) Exit the Loop\n";
		cout << "1) insert At last\n";
		cout << "2) insert At Beg\n";
		cout << "3) Display list\n";
		cout << "4) insert At Nth\n";
		cout << "5) Delete nth Node\n";
		cout << "Enter ur Choise\n";
		cin>>ch;

		switch (ch)
		{
		case 1:
			cout << "enter a no at last";
			cin >> item;
			lis.insertLast(&head, item);
			break;

		case 2:
			cout << "enter a no at Beg";
			cin >> item;
			lis.insertBeg(&head, item);
			break;

		case 3:
			lis.dispNode(&head);
			break;

		case 4:
			cout << "enter a no ";
			cin >> item;
			lis.insertNth(&head, item);
			break;
		case 5:
			lis.DeleteNth(&head);
			break;
		case 0:
			exit(0);
			break;


		default:
			cout << "you entered wrong choise\n";
			break;
		}
	}
	return 0;
}
