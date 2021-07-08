#include<iostream>
#include<conio.h>
#include <ctime>4
using namespace std;
int s_day(int &year)
{
	int d;
	d = (((year-1)*365)+((year-1)/4)-((year-1)/100)+((year-1)/400)+1)%7;
    cout<<"day = "<<d<<endl;
	return d;
}
main()
{
	
	int year,week=0,s_date,m,choice;
	cout<<"\n\n\n\n Enter the Year : ";
	cin>>year;
	cout<<"\n Enter the Month : ";
	cin>>m;
	while(true)
	{
        system("cls");	
        string month[]={"JANUARY","FEBUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
        int monthdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(year%4 == 0 && year%100 != 0 || year%400 ==0)
        monthdays[1]=29;
        s_date=s_day(year);
        cout<<"s_date = "<<s_date<<endl;
        for(int i=0;i<12;i++)
        {
            for(week=0;week<s_date;week++){cout<<" ";}
            if((m-1) == i)
            {
            
            cout<<"\n\n\t\t\t\t   "<<year;
            cout<<"\n\t ________________________"<<month[i]<<"_______________________";
            cout<<"\n\n\t    SUN    MON    TUE    WED    THR    FRI    SAT\n\t";
            for(week=0;week<s_date;week++)
            {
                cout<<"       ";
                
            }
            for(int j=1;j<=monthdays[i];j++)
            {
                if(j < 10)
                {
                cout<<"      "<<j;	
                }
                else
                {
                    cout<<"     "<<j;
                }
                if(++week>6)
                {
                    cout<<"\n\t";
                    week=0;
                }
                s_date=week;
            }
            }
            else{
            for(int j=1;j<=monthdays[i];j++)
            {
                if(++week>6)
                {
                    week=0;
                }
                s_date=week;
            }
            }
        }
        k:
        cout<<"\n\n 1 : Next Month\n 2 : Previous Month\n 3 : Next Year\n 4 : Previous Year\n 5 : Exit";
        cout<<"\n\n Your Choice : ";
        cin>>choice;
        if(choice == 1)
        {
            m++;
            if(m > 12)
            {
                m=1;
                year++;
            }
        }
        else if(choice == 2)
        {
            m--;
            if(m < 1)
            {
                m=12;
                year--;
            }
        }
        else if(choice == 3)
            year++;
        else if(choice == 4)
            year--;
        else if(choice == 5)
        {
            exit(0);
        }
        else
        {
            cout<<"\n\n Invalid Key...Please Try Again....";
            goto k;
        }
    }
}
