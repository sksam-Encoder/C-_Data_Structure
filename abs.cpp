#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class person{
	private:
	char name[30];
	int age;
	char add[100];
	public:
	 virtual void setdata(char *nme,int ag,char *address) = 0 ;   // pure virtual function abstract class
	 virtual void show() = 0;  // virtual keyword is needed for declaring pure virtual function.

	
};


class student : public person{

//	 this is also an abstract cls  untill all derived method overrided

      public:
	  void disp()
	  	{
	  	
	  	cout<<"in student class";
	  	
		}	



};







int main(int argc, char** argv) {
	
//	person obj;   we cannot create obj of an abstract class..
	student obj;
	return 0;
}
