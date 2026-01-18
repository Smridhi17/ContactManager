#include<iostream>
#include<fstream>
#include "mycontacts.cpp"
#include<string.h>
using namespace std;
contacts obj;

void update_contact()
{
    char name[50];
    cout<<endl<<"enter name";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    int p=0;
    rd.seekg(0,ios::beg);

    for (int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"record matched"<<endl;
            obj.accept();
            p=1;
        }

        wr.write((char *)&obj,sizeof(obj));

    }
    if(p==0)
    {
       cout<<endl<<"Contact Not Available"<<endl;
    }
    else{
            cout<<endl<<"Contact Updated"<<endl;

    }
    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt","mydatafile.txt");
}


void search_name()
{
    char name[50];
    cout<<endl<<"Enter Name to be searched"<<endl;
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    fstream wr;
    wr.open("temp.txt",ios::app);
    rd.seekg(0,ios::beg);
    int p=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<"----------------------------------------------------------------------------------------------------------------------";
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"Full Name ";
            cout<<setw(20);
            cout<<"Mobile Number ";
            cout<<setw(30);
            cout<<"EMail ID ";
            cout<<setw(20);
            cout<<"Instagram ";
            cout<<setw(20);
            cout<<"Twitter ";
            cout<<endl<<"----------------------------------------------------------------------------------------------------------------------";
            obj.display();
            cout<<endl;
            cout<<endl<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
            p=1;
        }
    }
    if(p==0)
    {
        cout<<endl<<"No Such data found"<<endl;
    }
    rd.close();
    wr.close();
}



void remove_contact()
{
    char name[50];
    cout<<endl<<"enter name";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    rd.seekg(0,ios::beg);
    int x=1;
    for (int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            x=0;
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));
        }
    }
        if(x==0)
        {
            cout<<endl<<"Contact Removed"<<endl;

        }
        else{
            cout<<endl<<"Contact Not Available"<<endl;

        }



    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt","mydatafile.txt");

}
void search_mobile()
{
    char mobile[50];
    cout<<endl<<"Enter Mobile Number to be searched"<<endl;
    cin>>mobile;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    fstream wr;
    wr.open("temp.txt",ios::app);
    rd.seekg(0,ios::beg);
    int p=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.mobile,mobile)==0)
        {
            cout<<"----------------------------------------------------------------------------------------------------------------------";
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"Full Name ";
            cout<<setw(20);
            cout<<"Mobile Number ";
            cout<<setw(30);
            cout<<"EMail ID ";
            cout<<setw(20);
            cout<<"Instagram ";
            cout<<setw(20);
            cout<<"Twitter ";
            cout<<endl<<"----------------------------------------------------------------------------------------------------------------------";
            obj.display();
            cout<<endl;
            cout<<endl<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
            p=1;
        }
    }
    if(p==0)
    {
        cout<<endl<<"No Such data found"<<endl;
    }
    rd.close();
    wr.close();
}


void read_data()
{
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    cout<<endl;
    cout<<left;
    cout<<setw(30);
    cout<<"Full Name";
    cout<<setw(15);
    cout<<"Mobile no.";
    cout<<setw(35);
    cout<<"Email ID";
    cout<<setw(20);
    cout<<"Instagram";
    cout<<setw(20);
    cout<<"Twitter";
    cout<<"---------------------------------------------------------------------------------------------------------------------";

    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=s;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        obj.display();
    }
    cout<<"---------------------------------------------------------------------------------------------------------------------";
};
void add_contact()
{
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    int p=0;
    rd.seekg(0,ios::beg);
    for(int i=1;i<=s;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            cout<<endl<<"Contact already present"<<endl;
            p=1;
            break;
        }
    }

    if(p==0)
    {
    obj.accept();
    strcpy(obj.name,name);
    fstream wr;
    wr.open("mydatafile.txt",ios::app);

    wr.write((char *)&obj,sizeof(obj));
    wr.close();
    cout<<endl<<"FILE WRITTEN"<<endl;
    }
rd.close();
}



void search_email()
{
    char email[50];
    cout<<endl<<"Enter EMail ID to be searched"<<endl;
    cin>>email;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    fstream wr;
    wr.open("temp.txt",ios::app);
    rd.seekg(0,ios::beg);
    int p=0;
    for(int i=1;i<=s;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.email,email)==0)
        {
            cout<<"----------------------------------------------------------------------------------------------------------------------";
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"Full Name ";
            cout<<setw(20);
            cout<<"Mobile Number ";
            cout<<setw(30);
            cout<<"EMail ID ";
            cout<<setw(20);
            cout<<"Instagram ";
            cout<<setw(20);
            cout<<"Twitter ";
            cout<<endl<<"----------------------------------------------------------------------------------------------------------------------";
            obj.display();
            cout<<endl;
            cout<<endl<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
            p=1;
        }
    }
    if(p==0)
    {
        cout<<endl<<"No Such data found"<<endl;
    }
    rd.close();
    wr.close();
}

int main()
{
    int e=0;
    int choice;
    while(e==0)
    {

        cout<<endl<<"Press 1 to add contacts";
        cout<<endl<<"Press 2 to read contacts";
        cout<<endl<<"press 3 to remove contact";
        cout<<endl<<"Press 4 to update contact";
        cout<<endl<<"Press 5 to search email";
        cout<<endl<<"Press 6 to search mobile";
        cout<<endl<<"Press 7 to search name";
        cout<<endl<<"Press 8 to exit";
        cout<<endl<<endl<<"enter choice";
        cin>>choice;
        if(choice==1)
        {
            add_contact();
        }
        else if(choice==2)
        {

            read_data();
        }
        else if(choice==3)
        {
            remove_contact();
        }
        else if (choice==4)
        {
            update_contact();
        }
        else if(choice==5)
        {

            search_email();
        }
        else if(choice==6)
        {

            search_mobile();
        }
        else if(choice==7)
        {
            search_name();
        }
        else{

        e=1;
        break;
        }

    }

}
