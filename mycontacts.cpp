#include<iostream>
#include<iomanip>
using namespace std;
class contacts
{
public:
    char name[50],mobile[50],email[50],insta[50],twit[50];
public:
    void accept()
    {
        cout<<"enter name ";
        cin>>name;
        cout<<endl<<"enter mobile ";
        cin>>mobile;
        cout<<endl<<"enter email id ";
        cin>>email;
        cout<<endl<<"enter insta id ";
        cin>>insta;
        cout<<endl<<"enter twit id ";
        cin>>twit;
    };

    void display()
    {
        cout<<endl;
        cout<<left;
        cout<<setw(30);
        cout<<name;
        cout<<setw(15);
        cout<<mobile;
        cout<<setw(35);
        cout<<email;
        cout<<setw(20);
        cout<<insta;
        cout<<setw(20);
        cout<<twit;
    }
    friend void remove_contact();
    friend void update_contact();
     friend void add_contact();
     friend void search_name();
    friend void search_mobile();
    friend void search_email();

};
void remove_contact();
void update_contact();
void search_name();
void search_mobile();
void search_email();
void add_contact();

