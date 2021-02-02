#include<iostream>//standard c++ library
#include<conio.h>//to get a single character as input
#include<fstream>//for filing
#include<string>//for taking user name input
#include<iomanip>
using namespace std;



//structure for NAME
struct Name
{	
	//For storing first name of the User
	string Fname;
	//For storing Password 
	string Password;
	//For storing the number of students
	int NO_of_students;
	//For PASSword and admin data
	int NO_of_Admins;
};

//structure for Attendance
struct Attendance
{	
	//For storing the Number of presents 
	int present;
	//For storing the Number of Absents
	int absents;
	//For storing the Number of Days
	int Total_days;
	//for storing roll number
	int roll;
	//For storing the section
	char section;
};

//structure for Course's 
struct Course
{
 //Name of registered courses
 string registered;
 //Name of unregisterd courses
 string unregistered;
 //for credit hours
 int credit_hours;	
};

void file_create();


int Admin(string,int);
int Password(string,int);

int main()
{	file_create();
	system("color 17");
	ifstream in;
	ofstream out;
	
	Name N;
	
	Attendance A;
	int size=10;
	int Passsize=10;
	
	
	/*for geting the total number of students*/
	in.open("Data.txt",ios::app);
	in>>N.NO_of_students;
	in.close();

	if(N.NO_of_students<0)
	{N.NO_of_students=0;}

 
	int *Roll;
	Roll=new int[N.NO_of_students];
 
	in.open("RollNO.txt",ios::app);
	for(int i=0;i<N.NO_of_students;i++)
	{
		in>>*(Roll+i);
		out<<endl;
	}
	in.close();



	string *Name;
	Name=new string[N.NO_of_students];
 
	in.open("Name.txt",ios::app);
	for(int i=0;i<N.NO_of_students;i++)
	{
		in>>*(Name+i);
		out<<endl;

	}
	in.close();


	int *present;
	present=new int[N.NO_of_students];
	
	in.open("Presents.txt",ios::app);
	for(int i=0;i<N.NO_of_students;i++)
	{
		in>>*(present+i);
		out<<endl;
	}
	in.close();

	int *absents;
	absents=new int [N.NO_of_students];
 
	in.open("absents.txt",ios::app);
	for(int i=0;i<N.NO_of_students;i++)
	{
		in>>*(absents+i);
		out<<endl;
	}
	in.close();

	static int result3=0;
	cout<<"\t\tWELCOME to Student Management System "<<endl;
	cout<<"________________________________________________________________________________"<<endl;
	
	cout<<"Enter UserName: ";
	getline(cin,N.Fname);
	
	//for total no of user and passwords manually given They are 3 in number
	N.NO_of_Admins=3;

	//Ysing int variable to match the user name w.r.t password
	int result=-2;
	result=Admin(N.Fname,N.NO_of_Admins);
	
	cout<<"Enter Password: ";
	char pass[5]={' '};
	
	for(int i=0;i<4;i++)
	{
	pass[i]=getch();
	cout<<"*";
	}
	N.Password=pass;
	getch();
	system("CLS");
	int result2=-1;
	result2=Password(N.Password,N.NO_of_Admins);

	//if condition if username and password are correct
	if(result==result2)
	{   
		char button=' ';
		while(button!='e')
		{
				in.open("RollNO.txt",ios::app);
				for(int i=0;i<N.NO_of_students;i++)
				{
					in>>*(Roll+i);
					out<<endl;
				}
				in.close();

				in.open("Name.txt",ios::app);
				for(int i=0;i<N.NO_of_students;i++)
				{
					getline(in,*(Name+i));
			
					//for maintaining the size of the string to be 10
					string h=*(Name+i);
			
					if(h.length()>15)
					{
						string v=*(Name+i);
						string f;
						v.resize (15);
						*(Name+i)=v;
					}
				 out<<endl;
				}
				in.close();

				in.open("Presents.txt",ios::app);
				for(int i=0;i<N.NO_of_students;i++)
				{
					in>>*(present+i);
					if(*(present+i)==0)
					{*(present+i)=0;}
					out<<endl;
				}
				in.close();

				in.open("absents.txt",ios::app);
				for(int i=0;i<N.NO_of_students;i++)
				{
					in>>*(absents+i);
					out<<endl;
				}
				in.close();
				
				cout<<"______________________________________________"<<endl;
				cout<<"\t\t\1 WELCOME TO MAIN-MENU \1"<<endl;
				cout<<"______________________________________________"<<endl;
				cout<<"Press 1 to see the student attendance list"<<endl;
				cout<<"Press 2 for the Teacher Panel"<<endl;
				cout<<"Press 3 for course Registration Panel"<<endl;
				cout<<"Press e to exit"<<endl;
				cout<<"______________________________________________"<<endl;

				button=getch();
				
				//For Adding a New Data
		if(button=='3')
		{
			
			
			delete []Name;
			delete [] Roll;
			delete [] present;
			delete [] absents;

			N.NO_of_students++;

			Name=new string[N.NO_of_students];
			
			in.open("Name.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(Name+i);
					out<<endl;	
			}
			in.close();

			
			char combine[30]={' '};
			char first[20]={' '};
			char second [20]={' '};
			cout<<"Enter the first Name : "<<endl;
			cin>>first;
			cout<<"Enter the Second Name : "<<endl;
			cin>>second;

			strcat(combine,first);
			strcat(combine," ");
			strcat(combine, second);

			*(Name+N.NO_of_students-1)=combine;
			
			out.open("Name.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					out<<*(Name+i);
					out<<endl;
			}
			out.close();

			in.open("Name.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(Name+i);
					out<<endl;
					
			}
			in.close();

			

			Roll=new int[N.NO_of_students];

			in.open("RollNO.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(Roll+i);
					out<<endl;
					
			}
			in.close();


			

			int check=0;
			while(check+1!=N.NO_of_students)
			{
				cout<<"Enter the Roll Number : "<<endl;
				cin>>*(Roll+N.NO_of_students-1);
				
				check=0;
				for(int i=0;i<N.NO_of_students;i++)
				{
					if(*(Roll+i)==*(Roll+N.NO_of_students-1))
					{
						check=0;
						cout<<"Your Entered Roll Number, Already exists."<<endl;
						break;
					}
					
				}

				for(int i=0;i<N.NO_of_students;i++)
				{
					if(*(Roll+i)!=*(Roll+N.NO_of_students-1))
					{check++;}
				}
			}




			out.open("RollNO.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					out<<*(Roll+i);
					out<<endl;
			}
			out.close();

			in.open("RollNO.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(Roll+i);
					out<<endl;
					
			}
			in.close();

			

			present=new int[N.NO_of_students];

			
			in.open("Presents.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(present+i);
					out<<endl;
			}
			in.close();

			
			*(present+N.NO_of_students-1)=0;

			out.open("Presents.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					out<<*(present+i);
					out<<endl;
			}
			out.close();

			in.open("Presents.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(present+i);
					out<<endl;
					
			}
			in.close();

		

			absents=new int [N.NO_of_students];
			
			in.open("absentstxt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(absents+i);
					out<<endl;
			}
			in.close();


			*(absents+N.NO_of_students-1)=0;

			out.open("absentstxt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					out<<*(absents+i);
					out<<endl;
			}
			out.close();

			in.open("absents.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
					in>>*(absents+i);
					out<<endl;
					
			}
			in.close();

			out.open("Data.txt");
			out<<N.NO_of_students;
			out.close();


		}//ifcondition for '4' ending

			
			if(button=='1')
			{		
			cout<<"___________________________________________________________________"<<endl;
			cout<<"NO#|Roll NUmber |NAME \t        | Presents | Absents  | Total DAys |"<<endl;
			cout<<"===================================================================="<<endl;
	
			if(N.NO_of_students==0)
			{
				cout<<"THERE IS NO DATA Available!!"<<endl;
			}

			for(int i=0;i<N.NO_of_students;i++)
			{	
				if(*(present+i)<0)
				{*(present+i)=0;}

				if(*(absents+i)<0)
				{*(absents+i)=0;}

				cout<<i+1<<") |"<<setw(12)<<*(Roll+i)<<"|"<<setw(15)<<*(Name+i)<<"|"<<setw(10)<<*(present+i)<<"|"<<setw(10)<<*(absents+i)<<"|"<<setw(10)<<*(present+i)+*(absents+i)<<"  |"<<endl;
			
			}
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			getch();
			}
		
				
			if(button=='2')//Teacher panel
			{

				char button2=' ';

				while(button2!='e')
				{
									system("CLS");
				cout<<"______________________________________________"<<endl;
				cout<<"\t\t\3 WELCOME TO TEACHER PANEL \3"<<endl;
				cout<<"______________________________________________"<<endl;
				cout<<"Press 1 to see the student attendance list"<<endl;
				cout<<"PRess 2 For updating the record "<<endl;
				cout<<"Press 3 For deleting the record "<<endl;
				cout<<"Press 4 to Search for a record"<<endl;
				cout<<"Press e to return to Main-Menu"<<endl;
				cout<<"______________________________________________"<<endl;
				
				
				button2=getch();

			if(button2=='1')
			{		
			cout<<"___________________________________________________________________"<<endl;
			cout<<"NO#|Roll NUmber |NAME \t        | Presents | Absents  | Total DAys |"<<endl;
			cout<<"===================================================================="<<endl;
	
			if(N.NO_of_students==0)
			{
				cout<<"THERE IS NO DATA Available!!"<<endl;
			}

			for(int i=0;i<N.NO_of_students;i++)
			{	
				if(*(present+i)<0)
				{*(present+i)=0;}

				if(*(absents+i)<0)
				{*(absents+i)=0;}

				cout<<i+1<<") |"<<setw(12)<<*(Roll+i)<<"|"<<setw(15)<<*(Name+i)<<"|"<<setw(10)<<*(present+i)<<"|"<<setw(10)<<*(absents+i)<<"|"<<setw(10)<<*(present+i)+*(absents+i)<<"  |"<<endl;
			
			}
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			getch();
		}
		
			if(button2=='2')
			{
			char check1=' ';
			cout<<"Press 1 to see the list for help\nPress 2 update "<<endl;
			check1=getch();

			if(check1=='1')
			{
				
			cout<<"___________________________________________________________________"<<endl;
			cout<<"NO#|Roll NUmber |NAME \t        | Presents | Absents  | Total DAys |"<<endl;
			cout<<"===================================================================="<<endl;
			
			if(N.NO_of_students==0)
			{cout<<"THERE IS NO DATA Available!!"<<endl;}

			for(int i=0;i<N.NO_of_students;i++)
			{	
				if(*(present+i)<0)
				{*(present+i)=0;}

				if(*(absents+i)<0)
				{*(absents+i)=0;}

				cout<<i+1<<") |"<<setw(12)<<*(Roll+i)<<"|"<<setw(15)<<*(Name+i)<<"|"<<setw(10)<<*(present+i)<<"|"<<setw(10)<<*(absents+i)<<"|"<<setw(10)<<*(present+i)+*(absents+i)<<"  |"<<endl;
			
			}
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
			
			
			}
			if(check1=='1')
			{
			check1='2';
			}
			if(check1=='2')
			{
				int h=-1;
				cout<<"Press Enter the Rollnumber of the Student : ";
				cin>>h;

			int updateNO=-1,check=0;
			for(int i=0;i<N.NO_of_students;i++)
			{
				if(*(Roll+i)==h)
				{
				updateNO=i;
				check=1;
				}
				
			}
			char update=' ';
			if(check==1)
			{
				cout<<"______________________________________________"<<endl;
				cout<<"\nSelect from the given below option to update"<<endl;
				cout<<"Press r to update Roll number"<<endl;
				cout<<"Press p to update Presents "<<endl;
				cout<<"Press a to update Absents "<<endl;
				cout<<"Press n to update Name "<<endl;
				update=getch();

				if(update=='r')
				{
				
							int check3=0;
							int rool=-1;
					while(check3!=N.NO_of_students)
					{
						cout<<N.NO_of_students<<endl;
						cout<<"Enter the Roll Number : "<<endl;
						cin>>rool;
				
						check3=0;
						for(int i=0;i<N.NO_of_students;i++)
						{
							if(*(Roll+i)==rool)
							{
								check3=0;
								cout<<"Your Entered Roll Number, Already exists."<<endl;
								getch();
								break;
							}
					
						}

						for(int i=0;i<N.NO_of_students;i++)
						{
						if(*(Roll+i)!=rool)
						{
							check3++;
							}
						}
					}
					if(check3==N.NO_of_students)
					{
						cout<<"Name UPdated \1"<<endl;
						getch();
					*(Roll+updateNO)=rool;
					}



				}

				switch(update)
				{
					case 'p':
						cout<<"Please enter the Presents : "<<endl;
					cin>>*(present+updateNO);
					break;
					case 'a':
					cout<<"Please enter the Absents : "<<endl;
					cin>>*(absents+updateNO);
					break;
					case 'n':
					cout<<"Please enter the Name : "<<endl;
					cin.ignore();
					getline(cin,*(Name+updateNO));
					break;
					case'r':
					break;
					default:
					cout<<"Wrong key pressed!!!"<<endl;
					break;
			}
				
			string k=*(Name+updateNO);
			
			if(k.length()>15)
			{string v=*(Name+updateNO);
			string f;
			v.resize (15);
			*(Name+updateNO)=v;
			}
	
				}
			}

			out.open("RollNO.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
			out<<*(Roll+i);
			out<<endl;
			}
			out.close();

			out.open("Name.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
			out<<*(Name+i);
			out<<endl;
			}
			out.close();

			out.open("Presents.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
				out<<*(present+i);
				out<<endl;
			}
			out.close();

			out.open("absents.txt");
			for(int i=0;i<N.NO_of_students;i++)
			{
				out<<*(absents+i);
				out<<endl;
			}
			out.close();
		}//update bracket ending


		if(button2=='3')
		{	
			char del=' ';
			cout<<"Press 1 to see the list for help"<<endl;
			cout<<"Press 2 to Enter the RollNUmber for delete"<<endl;
			char g=' ';
			g=getch();
			del=g;

			if(del=='1')
			{
				
			cout<<"___________________________________________________________________"<<endl;
			cout<<"NO#|Roll NUmber |NAME \t        | Presents | Absents  | Total DAys |"<<endl;
			cout<<"===================================================================="<<endl;
			
			if(N.NO_of_students==0)
			{cout<<"THERE IS NO DATA Available!!"<<endl;}

			for(int i=0;i<N.NO_of_students;i++)
			{	
				if(*(present+i)<0)
				{*(present+i)=0;}

				if(*(absents+i)<0)
				{*(absents+i)=0;}

				cout<<i+1<<") |"<<setw(12)<<*(Roll+i)<<"|"<<setw(15)<<*(Name+i)<<"|"<<setw(10)<<*(present+i)<<"|"<<setw(10)<<*(absents+i)<<"|"<<setw(10)<<*(present+i)+*(absents+i)<<"  |"<<endl;
			
			}
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			del='2';

			}
			if(N.NO_of_students==0)
			{	
				cout<<"\t\tWARNING"<<endl;
				cout<<"\t  ++++++++++++++++++++";
				cout<<"\n AS There is NO Data Available, So delete operation can't be performed."<<endl;
				getch();			
			}

			if(N.NO_of_students!=0)
			{
				if(del=='2')
				{	
					int m=-1;
					cout<<"Press Enter the RollNumber of the student for deleting : ";
					cin>>m;
					
					int del=-1,check=0;
				
					for(int i=0;i<N.NO_of_students;i++)
					{
						if(*(Roll+i)==m)
						{
						del=i;
						check=1;
						}
					}
					//delete
					
				
					out.open("RollNO.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						if(del!=i)
						{
							out<<*(Roll+i);
							out<<endl;
						}
					}
					out.close();

					out.open("Name.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						if(del!=i)
						{
							out<<*(Name+i);
							out<<endl;
						}
					}
					out.close();

					out.open("Presents.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						if(del!=i)
						{
							out<<*(present+i);
							out<<endl;
						}
					}
					out.close();


					out.open("absents.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						if(del!=i)
						{
							out<<*(absents+i);
							out<<endl;
						}
					}
					out.close();
					
					if(del>=0)
					{N.NO_of_students--;

					out.open("Data.txt");
					out<<N.NO_of_students<<endl;
					out.close();
					}
					
					in.open("Name.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						in>>*(Name+i);
						out<<endl;	
					}
					in.close();

					in.open("RollNO.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						in>>*(Roll+i);
						out<<endl;
					
					}
					in.close();

					in.open("Presents.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						in>>*(present+i);
						out<<endl;
					}
					in.close();

					in.open("absentstxt");
					for(int i=0;i<N.NO_of_students;i++)
					{
						in>>*(absents+i);
						out<<endl;
					}
					in.close();



					}//if del==2 bracket ending
			}//if N.studentnumber = 0, bracket ending 

		}//delete brackets 



		if(button2=='4')
		{
					if(N.NO_of_students==0)
					{
						cout<<"THERE IS NO DATA Available!!"<<endl;
						getch();
					}
					
					if(N.NO_of_students!=0)
					{
						int search;
						
						cout<<"Please Enter the ROLLnumber to be Searched : "<<endl;
						cin>>search;
					
					
						int check=-1;

						for(int i=0;i<N.NO_of_students;i++)
						{
							if(*(Roll+i)==search)
							{
								check=i;
							}
						
						}
						if(check!=-1)
						{
							cout<<"\tYour Searched Data is Given below"<<endl;
							cout<<" Name : "<<*(Name+check);
							cout<<"\n RollNumber : "<<*(Roll+check);
							cout<<"\n Presents : "<<*(present+check);
							cout<<"\n Absents : "<<*(absents+check);
							getch();
						
						}
						
					
					
					}
				
				}//if(button=='5') ending

		
		}

	}//teacher panel ending
				

	system("CLS");
	}//while

					out.open("RollNO.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
							out<<*(Roll+i);
							out<<endl;
					}
					out.close();

					out.open("Name.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
							out<<*(Name+i);
							out<<endl;
					}
					out.close();

					out.open("Presents.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
							out<<*(present+i);
							out<<endl;
					}
					out.close();


					out.open("absents.txt");
					for(int i=0;i<N.NO_of_students;i++)
					{
							out<<*(absents+i);
							out<<endl;
					}
					out.close();


					out.open("Data.txt");
					out<<N.NO_of_students<<endl;
					out.close();

delete [] Roll;
delete [] present;
delete [] Name;
delete [] absents;
}//password match 
else
{	if(result3<3)
	{
		cout<<"\n\t\tWARNING"<<endl;
		if(result==-2&&result2==-1)
		{cout<<"Your User Name and Password Both are invalid"<<endl;}
		else if(result==-2)
		{cout<<"Your User Name is incorrect\a\a"<<endl;}
		else if(result2==-1)
		{cout<<"Your Password is in correct\a\a"<<endl;}
		
		result3++;
		
		cout<<"\tNOTE: You Have "<<4-result3<<" Tries left"<<endl;
		getch();
		system("ClS");
		return main();
	}
	else
	{	system("color 47");
		cout<<"\n\n\t\tSYSTEM IS SHUTINGDOWN"<<endl;
		getch();}
	

}


system("pause");}

void file_create()
{
	ifstream in;
	ofstream out;

	in.open("Admin.txt",ios::app);
	in.close();

	in.open("Password.txt",ios::app);
	in.close();

	in.open("Data.txt",ios::app);
	in.close();

	in.open("absents.txt",ios::app);
	in.close();

	in.open("Presents.txt",ios::app);
	in.close();

	in.open("Name.txt",ios::app);
	in.close();

	in.open("RollNO.txt",ios::app);
	in.close();


}



int Admin(string N,int num)
{
ifstream in;
ofstream out;
string N2;
in.open("Admin.txt");
for(int i=0;i<=num;i++)
{
	in>>N2;
	out<<endl;
	
	if(N.compare(N2)==0)
	{
	return i;
	i=num+1;
	}
}
in.close();
return -2;
}


int Password(string N,int num)
{
	ifstream in;
	ofstream out;
	string N2;
	in.open("Password.txt");

	for(int i=0;i<4;i++)
	{
		switch(N[i])
		{
				case 'A':
				N[i]='F';
				break;
				case 'B':
				N[i]='G';
				break;
				case 'C':
				N[i]='H';
				break;
				case 'D':
				N[i]='I';
				break;
				case 'E':
				N[i]='J';
				break;
				case 'F':
				N[i]='K';
				break;
				case 'G':
				N[i]='L';
				break;
				case 'H':
				N[i]='M';
				break;
				case 'I':
				N[i]='N';
				break;
				case 'J':
				N[i]='O';
				break;
				case 'K':
				N[i]='P';
				break;
				case 'L':
				N[i]='Q';
				break;
				case 'M':
				N[i]='R';
				break;
				case 'N':
				N[i]='S';
				break;
				case 'O':
				N[i]='T';
				break;
				case 'P':
				N[i]='U';
				break;
				case 'Q':
				N[i]='V';
				break;
				case 'R':
				N[i]='W';
				break;
				case 'S':
				N[i]='X';
				break;
				case 'T':
				N[i]='Y';
				break;
				case 'U':
				N[i]='Z';
				break;
				case 'V':
				N[i]='A';
				break;
				case 'W':
				N[i]='B';
				break;
				case 'X':
				N[i]='C';
				break;
				case 'Y':
				N[i]='D';
				break;
				case 'Z':
				N[i]='E';
				break;
				case 'x':
				N[i]='a';
				break;
				case 'a':
				N[i]='b';
				break;
				case 'b':
				N[i]='c';
				break;
				case '1':
				N[i]='2';
				break;
				case'4':
				N[i]='3';
				break;
				default:
				N[i]=N[i];
				break;
		}
		
	}	
	for(int i=0;i<=num;i++)
	{
		in>>N2;
		out<<endl;
	if(N.compare(N2)==0)
	{
		return i;
		i=num+1;
	}
}
in.close();
return -1;
}