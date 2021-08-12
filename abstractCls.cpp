#include <iostream>
#include <string>
#include<cstring>

using namespace std;
//All the member of the base class are part of the derived class.
// However, the derived class can only access members that are 
// public or protected.
class person{
	protected:
	char name[30];
	int age;
	char add[100];
	public:
	 virtual void setdata(const char *nme,int ag, const char *address) = 0 ;   // pure virtual function abstract class
	 virtual void show() = 0;  // virtual keyword is needed for declaring pure virtual function.

	
};


class student : public person{

//	 this is also an abstract cls  untill all derived method overrided

      public:
	  void setdata( const char *nme,int ag,const char *address)
	  	{
			
			strcpy(name,nme);
			age = ag;
			strcpy(add,address);
				  	
		}	
		
		void show()
		{
			
		cout<<"name = "<<name;
		cout<<"age = "<<age;
		cout<<"address = "<<add;



			
		}



};



class employee : public person{

//	 this is also an abstract cls  untill all derived method overrided
		protected:
		int	id;
		char dept[30];
		
		
      public:
      	
//      	common charterised properties
	  void setdata( const char *nme,int ag,const char *address)
	  	{
			
			strcpy(name,nme);
			age = ag;
			strcpy(add,address);
				  	
		}
//      	common charterised properties		
		
		void setEmp(int i,const char *de)
		{
		
			id = i;
			strcpy(dept,de);	
			
			
		}	 
		
			//      	common charterised properties

		void show()
		{
			
		cout<<"name = "<<name<<endl;
		cout<<"age = "<<age<<endl;
		cout<<"address = "<<add<<endl;
		cout<<"id = "<<id<<endl;
		cout<<"dept = "<<dept<<endl;
		}

	//      	common charterised properties



};






int main() {
	
//	person obj;   we cannot create obj of an abstract class..
	student obj;
	obj.setdata("sam",22,"champdani");
	obj.show();
	employee emp;
	emp.setdata("sam seikh",22,"baidyabti");
	emp.setEmp(1234,"web");
	emp.show();
	return 0;
}
