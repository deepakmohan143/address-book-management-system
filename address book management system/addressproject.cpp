#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>



using namespace std;
class customer
{
public:
 char name[20],streetname[25],city[20],post[20],district[20],state[20],country[20];
 int pincode,doornumber,age;
 long int mobile;
   
 //inputing address
 void input()
 {
 	
 	cout<<"Enter Name "<<endl;
 	gets(name);
  	cout<<"Enter Street Name "<<endl;
 	gets(streetname);
 	cout<<"Enter City "<<endl;
 	gets(city);
 	cout<<"Enter Post "<<endl;
 	gets(post);
 	cout<<"Enter District "<<endl;
 	gets(district);
 	cout<<"Enter State "<<endl;
 	gets(state);
 	cout<<"Enter Country "<<endl;
 	gets(country);
 	cout<<"Enter Age "<<endl;
 	cin>>age;
 	cout<<"Enter Mobile Number "<<endl;
 	cin>>mobile; 	
 	cout<<"Enter Door Number "<<endl;
 	cin>>doornumber;
	 cout<<"Enter pincode "<<endl;
 	cin>>pincode;
 		
 }
  
  void output()
  {
  	cout<<"Enter Name "<<endl;
 	puts(name);
 	
 	cout<<"Enter Street Name "<<endl;
 	puts(streetname);
 	cout<<"Enter City "<<endl;
 	puts(city);
 	cout<<"Enter Post "<<endl;
 	puts(post);
 	cout<<"Enter District "<<endl;
 	puts(district);
 	cout<<"Enter State "<<endl;
 	puts(state);
 	cout<<"Enter Country "<<endl;
 	puts(country);
 	cout<<"Enter Age "<<endl;
 	cout<<age;
 	cout<<"Enter Mobile Number "<<endl;
 	cout<<mobile; 	
 	cout<<"Enter Door Number "<<endl;
 	cout<<doornumber;
	 cout<<"Enter pincode "<<endl;
 	cout<<pincode;
  	
  }
 
 
// creating file

void writefile()
{    customer ob2;
	ofstream f1;
  	f1.open("address.txt",ios::app);
     
     ob2.input();
      f1.write((char*)&ob2,sizeof(ob2));
      f1.close();
	
}
// to read file
void readfile()
{
	customer ob2;
	ifstream f1;
	f1.open("address.txt",ios::in);
	f1.read((char*)&ob2,sizeof(ob2));
	ob2.output();
	
}


};

class admin:public customer
{
public:

char password[10]="adminpass";
char username[6]="admin" ;
char user[20],pass[20];

	
  void adminpass()
  {
  	
  	cout<<" ";
     gets(user);
  	
  	cout<<"ENTER PASSWORD ";
  	gets(pass);
  	
   	if(strcmp(pass,password)==0)
   	{
   	 
		cout<<"\t DETAILS OF USERS"<<endl;
		 readfile();
		 	
   		
	   }
	   else 
	   {
	   	
	   	cout<<"\t Invalid Username Or Password"<<endl;
	   }
        	 
	  	  }	
	
	
};

	

    int main()
    {
    	admin ob1;
    	int n;
    	char ch,username2[20],password2[20],password1[20];
          for(int i=0;i<sizeof(password2);i++)
          {
          	
          	
          	password2[i]='\0';
		  }
          
          
    	cout<<endl<<"\t1.Customer\n\t2.Admin"<<endl;
    	cin>>n;
    	switch(n)
    	{
    		case 1: cout<<"Are You An Existing Customer(y/n)?";
			       cin>>ch;
			       
			       	
				
				
			       	 
			       	//ob1.customerlogin creation();
			       	
				
				   if(ch=='n')
				   {
				   	ofstream f3,f4;
					   cout<<"\tACCOUNT CREATION"<<endl;
					   f3.open("PASSWORD.txt",ios::out);
					   f4.open("address.txt",ios::out);
					   if(f3)
					   {
					   	cout<<"file opened";
					   }
					   else
					   {exit(1);
					   }
					   cout<<"Enter User Name"<<endl;
					   cin>>username2;
					   gets(username2);
					  //f3.write((char*)&username2,sizeof(username2));
                       	cout<<"Enter password\n";			   
					   gets(password2);
					    f3.write((char*)&password2,sizeof(password2));
					     ob1.input();
					     f4.write((char*)&ob1,sizeof(ob1));
					     f4.close();
					   	f3.close();
								
				   }
				   if(ch=='y')
			       {      //customer login;
			       
			       
			       	 cout<<"Enter the user name "<<endl;
			       	 cin>>username2;
			       	 gets(username2);
			       	 cout<<"Enter password\n"<<endl;
			       	 gets(password1);
			       	 if(strcmp(password1,password2)==0)
   	                {
   	 
		             cout<<"\t DETAILS OF USERS"<<endl;
		             ob1.readfile();
		 	
			       
			        }
	               	break;
	        case 2:
	               		
    	           ob1.adminpass()	;
		}
    	
    	
    
		   	
    }
    	return 0;
    }