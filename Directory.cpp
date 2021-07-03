#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void Exit();
void MainMenu();
void AddContact();
void ViewAllContact();
void View_Contact(char n[80]);
void Edit_Contact(char n[80]);
void Delete_Contact(char n[80]);

struct Contact{
	
	char name[80], email[80], address[100];
	int number;

};

int choice;

void Intro(){
	
	system("cls");
	cout<<endl<<endl;

    cout<<"\t          ____        ____  ____   _____   ____"<<endl;
    cout<<"\t |  |  | |     |     |     |    | |  |  | |    "<<endl;
    cout<<"\t |  |  | |____ |     |     |    | |  |  | |____"<<endl;
    cout<<"\t |  |  | |     |     |     |    | |  |  | |    "<<endl;
    cout<<"\t |__|__| |____ |____ |____ |____| |  |  | |____"<<endl<<endl<<endl;
    cout<<"___________________________________________________________________"<<endl<<endl;
    cout<<"\t\tTHIS IS PHONE BOOK DIRECTORY SYSTEM"<<endl;
    cout<<"___________________________________________________________________"<<endl;
    
    system("pause");
    
}

void HomePage(){
    do{
    system("cls");

    cout<<"====================PHONE BOOK DIRECTORY===================="<<endl<<endl<<endl;
    cout<<"\t1. MAIN MENU"<<endl<<endl;
    cout<<"\t2. EXIT"<<endl<<endl;
    
    cout<<"ENTER YOUR CHOICE :  ";
    cin>>choice;
   
	    switch(choice){
		   case 1:
		   {
		    MainMenu();
		    break;
		   }
		   case 2:
		   {
			Exit();
			break;
		   }    
		}
	}while(choice>3);
	
}

void MainMenu(){
	system("cls");

    cout<<endl<<endl;
    cout<<"----------------MAIN MENU----------------"<<endl<<endl;
    cout<<"\t1. CREATE A NEW CONTACT"<<endl;
    cout<<"\t2. VIEW ALL CONACTS"<<endl;
    cout<<"\t3. VIEW A CONTACT DETAILS"<<endl;
    cout<<"\t4. EDIT A CONTACT"<<endl;
    cout<<"\t5. DELETE A CONTACT"<<endl;
    cout<<"_________________________________________"<<endl<<endl;
    cout<<"\tENTER YOUR CHOICE.....[1-5]: ";
    cin>>choice;
    
    switch(choice){
	    case 1:
		{
	        AddContact();
	        break;
	    }
	    case 2:
		{
	        ViewAllContact();
	        break;
	    }
	    case 3:
	    {
	        char name[80];
			cout<<"ENTER NAME: ";
	        cin.ignore();
    		cin.getline(name,80);
	        View_Contact(name);
	        break;
	    }
	    case 4:
	    {
	        char name[80];
	        cout<<"ENTER NAME OF THE CONTACT TO BR MODIFIED: ";
	        cin.ignore();
    		cin.getline(name,80);
	        Edit_Contact(name);
	        break;
		}
	    case 5:
	    {
	        char name[80];
			cout<<"ENTER NAME: ";
	        cin.ignore();
    		cin.getline(name,80);
	        Delete_Contact(name);
	        break;
	    }
	}
}

void Exit(){
	
	cout<<"\tTHANK YOU FOR USING THIS SOFTWARE"<<endl<<endl<<endl;
	cout<<"\tProject:- PHONE DIRECTORY"<<endl;
	cout<<"\tGROUP MEMBERS:"<<endl<<endl;
	cout<<"\t     NAME                    Rollno."<<endl;
	cout<<"\t1. RISHABH PRAKASH         2K19/SE/098"<<endl;
	cout<<"\t2. RIYA ARORA              2K19/SE/100"<<endl;
		
}

void AddContact(){
	system("cls");
    Contact c;
    ofstream outfile;
    outfile.open("Directory.txt",ios::app|ios::binary);
    if(outfile.fail()){
        cout<<"\t[ERROR] PHONE DIRECTORY COULD NOT BE OPEN!!!";
        system("pause");
    }   
	    
	    cout<<"============NEW CONTACT============"<<endl<<endl;
	    cout<<"\tENTER FULL NAME: ";
	    cin.ignore();
    	cin.getline(c.name,80);
	    cout<<"\tENTER PHONE NUMBER: +91 ";
	    cin>>c.number;
	    cout<<"\tENTER EMAIL: ";
	    cin.ignore();
    	cin.get(c.email,80);
        cout<<"\tENTER ADDRESS: ";
	    cin.ignore();
    	cin.get(c.address,100);
	    
	    outfile.write(reinterpret_cast<char *> (&c), sizeof(Contact));
	    outfile.close();
	    
        cout<<endl<<"\t\t[CONTACT HAS BEEN SAVED SUCCESSFULLY]"<<endl<<endl;
	    system("pause");
}

void ViewAllContact(){
    system("cls");
    Contact c;
    ifstream infile;
    bool check=false;
    infile.open("Directory.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"\t[ERROR] PHONE DIRECTORY CAN NOT BE OPENED!!"<<endl<<endl;
        system("pause");
    }
    
    cout<<"----------------CONTACTS LIST----------------"<<endl<<endl<<endl;
    while(infile.read(reinterpret_cast<char*>(&s).sizeof(student)))
    {
        cout<<"\tNAME: "<<c.name<<endl;
        cout<<"\tPHONE NUMBER: "<<c.number<<endl;
        cout<<"\tEMAIL: "<<c.email<<endl;
        cout<<"\tADDRESS: "<<c.address<<endl;
        cout<<"_________________________________________________________________"<<endl<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t[EMPTY] NO CONTACT FOUND!!!"<<endl<<endl;
    system("pause");
}

void View_Contact(char n){
	system("cls");
    Contact c;
    ifstream infile;
    infile.open("Directory.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"\t[ERROR] PHONE DIRECTORY CANNOT BE OPENED!!"<<endl<<endl;
        system("pause");
    }
    bool equality=false;
    cout<<"----------------VIEW CONTACT----------------"<<endl<<endl;
    while(infile.read(reinterpret_cast<char*>(&c),sizeof(Contact)))
    {
        if(c.name == "n")
        {
        cout<<"\t Name: "<<c.name<<endl;
        cout<<"\t Number: "<<c.number<<endl;
        cout<<"\t Email: "<<c.email<<endl;
        cout<<"\t Address: "<<c.address<<endl;
        cout<<"______________________________________"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t[ERROR] CONTACT NOT FOUND!!"<<endl;
        
        system("pause");
}

void Edit_Contact(char n){
    
    system("cls");
    
    Contact c;
    fstream infile;
    infile.open("Directory.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"\t[ERROR] PHONE DIRECTORY COULD NOT BE OPENED!!!"<<endl<<endl;
        system("pause");
    }
    bool checker=false;
    cout<<"---------------EDIT A CONTACT---------------"<<endl<<endl;
    while(!infile.eof() && checker==false)
    {
    infile.read(reinterpret_cast<char*>(&c),sizeof(Contact));
    {
        if(c.name=="n")
        {
        cout<<"\tNAME: "<<c.name<<endl;
        cout<<"\tNUMBER: "<<c.number<<endl;
        cout<<"\tEMAIL: "<<c.email<<endl;
        cout<<"\tADDRESS: "<<c.address<<endl;
        cout<<"________________________________________________"<<endl<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"________________________________________________"<<endl<<endl;
        cout<<"\tENTER FULL NAME:";
        cin.ignore();
        cin.getline(c.name,80);
        cout<<"\tENTER PHONE NUMBER: ";
        cin>>c.roll;
        cout<<"\tENTER EMAIL: ";
        cin.ignore();
        cin.get(c.email,80);
        cout<<"\tENTER ADDRESS: ";
        cin.ignore();
        cin.get(c.address,100);
        int pos=(-1)*static_cast<int>(sizeof(Contact));
        infile.seekp(pos,ios::cur);
        infile.write(reinterpret_cast<char *> (&c), sizeof(Contact));
        cout<<endl<<endl;
        cout<<"\t\tTHE CONTACT HAS BEEN SUCCESSFULLY UPDATED"<<endl;
        checker=true;
        }
    }

    infile.close();
        if(checker==false)
        cout<<"\t[ERROR] CONTACT NOT FOUND!!"<<endl<<endl;
        system("cls");
    }
}

void Delete_Contact(char n){
    system("cls");
    
    Contact c;
    ifstream infile;
    infile.open("Direcctry.txt",ios::binary);
    if(!infile)
    {
        cout<<"[ERROR] PHONE DIRECTOY COULD NOT BE OPENED!!!"<<endl<<endl;
        system("pause");
    }
    ofstream outfile;
    outfile.open("Contact.txt",ios::binary);
    infile.seekg(0,ios::beg);
    cout<<"\t----------------DELETE A CONTACT----------------";
    while(infile.read(reinterpret_cast<char*>(&c),sizeof(Contact)))
    {
        if(c.name!="n")
        {
            outfile.write(reinterpret_cast<char*>(&c),sizeof(Contact));
        }
    }
    infile.close();
    outfile.close();  
    remove("Directory.txt");
    rename("Contact.txt","Directory.txt");
    cout<<endl;
    cout<<"\tCONTACT HAS BEEN SUCCESSFULLY DELETED"<<endl<<endl;
    system("pause");
}

int main(){
	
    system("cls");
    Intro();
	HomePage();
	
	return 0;
}
