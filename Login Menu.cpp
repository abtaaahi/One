#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();
int main()
{
    int c;
    cout<<"\nMENU:\n\nPress 1 to Sign in\nPress 2 to Sign Up\nPress 3 if you Forgot Password\nPress 4 to Exit\n\nEnter your choice: ";
    cin>>c;
    cout<<endl;
    switch(c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"Thank You!"<<endl;
        break;
    default:
        system("cls");
        cout<<"Please select from Menu."<<endl;
        main();
    }
}
void login()
{
    int count;
    string userID,password,id,pass;
    system("cls");
    cout<<"Enter Username & password: "<<endl;
    cout<<"Username: "<<endl;
    cin>>userID;
    cout<<"Password: "<<endl;
    cin>>password;
    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==userID && pass==password)
            count=1;
        system("cls");
    }
    input.close();
    if(count==1)
       {
           cout<<userID<<"\nLog in Successful."<<endl;
           main();
       }
    else
       {
           cout<<"Log in Error."<<endl;
       }
}
void registration()
{
    string ruserID,rpassword,rid,rpass;
    system("cls");
    cout<<"Enter the Username: "<<endl;
    cin>>ruserID;
    cout<<"Enter the password: "<<endl;
    cin>>rpassword;
    ofstream f1("records.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"Sign Up Successful."<<endl;
    main();
}
void forgot()
{
    int count=0;
    string suserID,sID,spass;
    system("cls");
    cout<<"Enter your Username: "<<endl;
    cin>>suserID;
    ifstream f2("records.txt");
    while(f2>>sID>>spass)
    {
        if(sID==suserID)
        {
            count=1;
        }
    }
    f2.close();
    if(count==1)
    {
        cout<<"Your Password is: "<<spass;
        main();
    }
    else{
        cout<<"Your Account Not Found."<<endl;
        main();
    }
}
