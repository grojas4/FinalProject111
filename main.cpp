#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"account.h"

using namespace std;


 int main()
{
  char answer;
  vector<account> list;
  vector<account> plist;
  char decision;
  int pin;
  string name;
  cout << "Welcome to Gerardo's Atm. Prime Banking Management" << endl;
  cout << "Do you have an account with me? [y] or [n]? " << endl;
  cin >> answer;
  account user;
  if(answer == 'y')
  {
    cout << "Enter name and pin " <<endl;
    cin >> name;
    cin >> pin;
    user.pullFile(plist);

 
    // pull from a .txt file that i created with the info of the AccountNumber
    do 
    {
      cout << "What would you like to do today?" << endl;
      cout << "Would you like to Deposit? [d] " << endl;
      cout << "Would you like to Withdraw? [w] " << endl;
      cout << "Would you like to Check your account balance? [b] " << endl;
      cout << "Exit [e]" << endl;
      cin >> decision;
      if(decision == 'd')
      {
        user.addMoney();
      }
      else if(decision == 'w')
      {
        user.removeMoney();
     }
      else if(decision == 'b')
      { 
        float balance = user.readBalance();
        cout << "Your balance is: " <<balance <<endl;
         }
      else if(decision =='e')
      { 
        break;
      }
      else
      {
        cout << "Invalid input try again browski " << endl;
      }


    }
    while(decision != 'e' &&  decision != 'E');
  }
    if(answer == 'n')
    {
      char response;
      string name;
      cout << "Would you like to make an account? [y] or [n] " <<endl;
      cin >> response;
      if(response == 'y')
      {
     string l=   user.addName();
       int k = user.addPin();
       user.setName(l);
       user.setPin(k);
       float p = 0.0;
       user.setBalance(p);
       plist.push_back(user);
        user.saveFile(plist);

      }
      else 
      {
        cout <<"Have a nice day then. we dont need your money" <<endl;
    }
    }

    return 0;
    
}


