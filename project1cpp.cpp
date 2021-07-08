
//This  project uses Luhn’s algorithm to validate a user's credit card

#include <bits/stdc++.h>
using namespace std;

void validOrNot(string CCN);

int main()
{
    string CCN;
    cout<<"Please Enter Your 16 digit credit card number "<<endl;
    cin>>CCN;
    int len = CCN.length();
    cout<<len<<endl;
    if(len < 16 || len > 16)
    {
        cout<<"Invalid Number Please Try Again "<<endl;
        return 0;
    }
    else
    {
        cout<<"Your Card Number is :";
        for(int i=0;i<len;i++)
        {
            cout<<CCN[i];
        }
        cout<<endl;
    }
    //Function to check the entered card number is valid or not

    validOrNot(CCN);  
    return 0;
}

void validOrNot(string CCN)
{
   int digit = CCN.length();
   int sum = 0;
   bool Second_digit = false; // to check for every second variable
   for(int i = digit - 1 ; i >= 0; i--)
   {
       int digit = CCN[i] - '0';
       if(Second_digit == true) digit = digit * 2;
        //Step 2 – If doubling of a number results in a two digit number i.e greater than 9
        // then add the digits of the product to get a single digit number. 
        // e.g., 12: 1 + 2 = 3
        sum += digit / 10; // Now take the sum of all the digits
        sum += digit % 10;

        Second_digit = !Second_digit;
   }
   //If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid 
   //according to the Luhn formula; else it is not valid.

   cout<<((sum%10==0)?"Valid😊😊":"Not Valid😥😥!")<<endl;
}



  //  "4137894711755904" for test case;