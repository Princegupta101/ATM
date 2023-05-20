#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
using namespace std;
int a,i=0;
	
	long long int moblieNum;
	string text, password2, password1, password0, old, pass, name, age, user, word, word1;
	string creds[2], cp[2], email;


class data
{public :

void register1()
{   cout<<"**************************************************"<<endl;
	cout<<"**                   REGISTER                   **"<<endl;
	cout<<"**************************************************"<<endl<<endl;
	cout<<"please enter username:";
	cin>>name;
	cout<<"please enter passsword:";
	cin>>password0;
	cout<<"please enter moblienumber:";
	cin>>moblieNum;
	cout<<"please enter email:";
	cin>>email;

	ofstream of1;
	of1.open("file.txt");
	if(of1.is_open())
	{
	of1<<name;
	of1<<password0;
	of1<<moblieNum;
	of1<<email;
	cout<<"Registion sucessfull "<<endl;	;
	}
	chioce();
		}
void login()
{
	i=0;

	cout<<endl<<endl<<"**************************************************"<<endl;
	                        cout<<"**                   LOGIN                      **"<<endl;
	                        cout<<"**************************************************"<<endl<<endl;


	ifstream of2;
	of2.open("file.txt");
	cout<<"please enter username:";
	cin>>user;
	cout<<"please enter passsword:";
	cin>>pass;

		       if(of2.is_open())
		   {
			    while(!of2.eof())
			{
				while(getline(of2, text))
			    {
				istringstream iss(text);
				 iss>>word;
				 creds[i]=word;
				 i++;
							 }
				 if(user==creds[0] &&  pass==creds[1])
				 {
					cout<<"---------login successful----";
					cout<<endl<<endl;
					cout<<"Details:"<<endl;

					cout<<"username:"+name<<endl;
					cout<<"password:"+pass<<endl;
					cout<<"moblie number"+moblieNum<<endl;
					cout<<"email:"+email<<endl;
							 }
							 else{
								cout<<endl<<endl;
								cout<<"Incorrect Credentials"<<endl;
								chioce();
							 }

			}

		       }
		}

 string  changepassword()
    {
	i=0;
    ifstream of0;

	cout<<"----------changepassword------------------";
	of0.open("file.txt");
	cout<<"Enter the old password ";
	cin>>old;
	if(of0.is_open())
	{
		while(of0.eof())
		{
			while(getline(of0, text))
			{
				istringstream iss(text);
				iss>>word;
				cp[i]==word;
				i++;

				}
		if(old==cp[1])
		{
		    of0.close();
		    ofstream of1;

				if(of1.is_open())
				{
					cout<<"Enter your new  password ";
					cin>>password1;
					cout<<"Again enter your new password";
					cin>>password2;
					if(password1==password2)
					{
						of1<<cp[0]<<"\n";
						of1<<password1;
						cout<<"password change successfully "<<endl;
						login();

					}
					else
                    {
							of1<<cp[0]<<"\n";
						of1<<old;
						cout<<"password do not change "<<endl;
					}


				}
				else
				{
				  cout<<"please enter a vaild password"<<endl;
				  changepassword();
				}
			}


		}
	}
    return 0;
    }

void chioce()
{
		
data a1;

   

	 cout<<"                      1.Register"<<endl;
	 cout<<"                      2.Login"<<endl;
	 cout<<"                      3.Change password"<<endl;
	 cout<<"                      4.Exit program "<<endl<<endl<<endl;

	 cout<<"Enter your choice :"<<endl;
	 cin>>a;
	 switch(a)
	 {
		case 1:{
	   a1.register1();
			break;
		 }
		 case 2:{

		       a1.login();
			break;
		 }
		case 3:{
		      a1.changepassword();
			break;
		 }
			 case 4:{
				cout<<"_____________Thanyou!______________";
				break;
			 }
			 default:
				cout<<"Enter a vaild choice";

	 }
}
};

int main() {
	system("color b");
	
data a1;
	
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"::                                             ::"<<endl;
	cout<<"::                welcome                      ::"<<endl;
	cout<<"::                                             ::"<<endl;
	cout<<"::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<endl;

	a1.chioce();
     return 0
     ;}

