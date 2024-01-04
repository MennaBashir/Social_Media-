#include <iostream>
#include"Activity.h"
#include<windows.h>//For color out
#include<unistd.h>//For sleep()
#include<stdlib.h>//For clear
using namespace std;
int main()
{
    system("Color 74");
    Activity avl;
    cout<<"\n\t\t\x03 Social media activities \x03\n";
    cout<<"\t\t___________________________\n";
    cout<<"\nWelcome to the program to record the latest updates on social media activities\n";
    int num;
    do
    {
        system("Color 74");

        cout<<"\n  Which section do you want to go to?\n\n";
        cout<<"\t1.Add a new user and his data\n";
        cout<<"\t2.Update on specific user data\n";
        cout<<"\t3.Search for specific user data\n";
        cout<<"\t4.Permanently delete a user and his data\n";
        cout<<"\t5.View all users and their latest activities\n";
        cout<<"\t0.Exit Program\n";
        cin>>num;
        system("cls");
        if(num==1)
        {
            system("Color 72");
            int act,com,lik;
            cout<<"Enter the current month's updates\n";
            cout<<"\n  First, the number of activities: ";
            cin>>act;
            cout<<"\n  Secondly, the number of comments: ";
            cin>>com;
            cout<<"\n  Third, the number of likes: ";
            cin>>lik;
            cout<<endl;
            avl.Insert({act,com,lik});
            Sleep(1000);
            system("cls");
        }
        else if(num==2)
        {
            system("Color 75");
            int x,y,z,x1,y1,z1;
            cout<<"First, enter the data you want to update(activities,comments,likes): ";
            cin>>x>>y>>z;
            cout<<"\nThen enter the updated data(activities,comments,likes): ";
            cin>>x1>>y1>>z1;
            cout<<endl;
            avl.Update({x,y,z}, {x1,y1,z1});
            Sleep(1000);
            system("cls");
        }
        else if(num==3)
        {
            system("Color 71");
            int a,b,c;
            cout<<"Enter the information you want to verify[Activities,Comments,Likes]\n";
            cin>>a>>b>>c;
            bool check=avl.Search(avl.root, {a,b,c});
            if(check)
                cout<<"\n\tInformation has already been found\x03\n";
            else
                cout<<"\n No information similar to this was found. \n Please, verify the validity of the data again\n";
            Sleep(3000);
            system("cls");
        }
        else if(num==4)
        {
            system("Color 75");
            int d,e,f;
            cout<<"\nEnter the data of the user you want to delete[Activities,Comments,Likes]: ";
            cin>>d>>e>>f;
            avl.Delete({d,e,f});
            Sleep(1000);
            system("cls");
        }
        else if(num==5)
        {
            system("Color 71");
            int i=0;
            cout<<"(Activities Comments Likes)\n\n";
            avl.In_Order(avl.root);
            Sleep(5000);
            system("cls");
        }
        else if(num==0)
        {
            cout<<"\n\tSee you later\x02";
            Sleep(1000);
            system("cls");
        }
    }
    while(num!=0);


    return 0;
}
