#include <iostream>
using namespace std;
class Node {

private:
  int D;
  
public:
	int key;
	  Node *n;


	Node()
	{
		
		key=0;
		D=0;
		n=NULL;
		
		
	}
	
	Node (int k ,int d)
	{
		this->key =k ;
		D = d;
		n= NULL;
		
	}
	
	
    void insertLast(){
    	
    	
    	
    	
    	
    	
	}
	
	
	
	
};

class CircularList{
	
	private :
		Node* head;
	public:
		CircularList()
		{
			
			head = NULL;
			
		}
//		 Check if a particluar list exist or not using key
			
	Node*	isExist(int k)
	{
			Node * ptr,*temp=NULL;
		if(head==NULL)
		{
			return head;
		}
		else
		{
				ptr = head;
				
				do{
					
					if(ptr->key == k )
					{
						
						temp = ptr;
					}
					ptr = ptr->n;
					
				}while(ptr != head);
				return temp;
		}
		
	}
	
	void insertLast(Node *new_node)
	{
		
		if(isExist(new_node->key)!=NULL)
		{

				cout<<"node exists with a key value: "
					<< new_node->key
					<<"add another node with diffrent key"
					<< endl;

		}
		else
		{


		if(head == NULL)
		{

				head = new_node;
				new_node->n = head;
				cout<<"node append at a head position"
				<< endl;

		}
		else

		{

				Node *ptr = head;
			while (ptr->n !=head)
			{
				/* code */

				ptr= ptr->n;				

			}

			ptr->n = new_node;
			new_node->n = head;
			cout<<"node appended"
			<< endl;
			


		}



		}
		
	}
		
	
	
};

int main()
{

	Node n1(1,5);
	
	return 0;	
	
	
}
