#include<iostream>
#include <string> 
#include <cstdlib> // random numbers
#include <ctime>


using namespace std;

void rules();

int main()
{
    string player_Name;
    int balance,betting_value,dice,guess;
    char choice;
    srand(time(0));
    cout<<"************************ WELCOME TO SHYAM'S CASINO ******************************"<<endl;
    cout<<"Enter your Name "<<endl;
    getline(cin,player_Name);
    cout<<"Enter the Amount you want to play "<<endl;
    cin>>balance;
    do
    {
        system("cls");
        rules();
        cout<<"Your current Balance is "<<balance<<" $"<<endl;
        do
        {
            cout<<"Please Enter The Amount You want To Bet "<<player_Name<<endl;
            cin>>betting_value;
            if(betting_value > balance)
            {
                cout<<"Betting Balance is more than your current balance"<<endl<<"\nRe-enter balance\n ";

            }
        }while(betting_value > balance);
        do
        {

            cout<<"Guess The Number Between 1 to 10 "<<endl;
            cin>>guess;
            if(guess>10||guess<0)
            {
                cout<<"Guess amount must be between 1 to 10 "<<endl<<"Re-enter balance"<<endl;
            }

        } while(guess>10||guess<0);
        dice = rand()%10+1;
        if(guess==dice)
        {
            cout<<"**congratulations** You Had Won "<<betting_value*2<<" $"<<endl;
            balance = balance + betting_value * 2;
        }
        else
        {
            cout<<"You Lost!!!  Better Luck Next Time"<<endl<<"You lost "<<betting_value<<" $"<<endl;
            balance = balance - betting_value;
        }
        cout<<"The Winning Number is "<<dice<<endl;
        cout<<player_Name<<"You have balance of " << balance << "$"<<endl;
        if(balance == 0)
        {
            cout << "You Do Not Have Sufficient balance to Play "<<endl;
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice; 
    } while(choice =='Y'|| choice=='y');

    cout<<endl<<endl<<endl;
    cout <<"Thankyou for Playing this game. Your balance is " << balance << " $"<<endl;
    return 0;
}

void rules()
{
    system("cls");
    cout<<"Rules For Playing This game"<<endl;
    cout << "\t1. Choose a number between 1 to 10"<<endl;
    cout << "\t2. Winner get Twice of money he/she Bets"<<endl;
    cout << "\t3. Wrong bet, and you lose the amount you Bet"<<endl;
}
