#include "account.h"
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
account::account()
{
  string name = " ";
  int pin = 0;
  float balance = 0.0;
  string address = " ";
}
void account::addMoney()
{
  float add;
  cout << "How much money would you like to deposit? " << endl;
  cin >> add;
  balance = balance + add;
}
void account::removeMoney()
{
  float subtract;
  cout << "How much money would you like to withdrawl? " << endl;
  cin >> subtract;
  subtract = subtract *1.0;
  balance = balance - subtract;
}
float account::readBalance()
{
  return balance;
}
string account::addName()
{
  string accountHolder;
  cout << "What is the name of the new account holder? " << endl;
  cin >> accountHolder;
  name = accountHolder;
  return accountHolder;
}
int  account::addPin()
{
  int pinCode;
  int pinCode2;
  bool pinMatch;
  do
  {
    pinMatch=true;
    cout << "Enter a 4 digit pin for your account. " << endl;
    cin >> pinCode;
    cout << "re-enter your pin " << endl;
    cin >> pinCode2;
    if (pinCode != pinCode2)
    {
      cout << "The pins did not match. try again " << endl;
      pinMatch = false;
    }
    return pinCode;
  }
  while(pinMatch == false);
  pin = pinCode;
}
void account::setName(string nombre)
{
  name = nombre;
}
void account::setPin(int password)
{
  pin = password;
}
void account::setBalance(float money)
{
  balance = money;
}
string account::getName()
{
  return name;
}
int account::getPin()
{
  return pin;
}
float account::getBalance()
{
  return balance;
}
void account::pullFile(vector<account>& plist)
{
  ifstream accounts;
  accounts.open("accounts.csv");
  string fileList;
  string nombre;
  int password;
  float money;
  char coma = ',';
  while(getline(accounts, fileList))
  {
    istringstream ss(fileList);
    getline(ss, nombre, ',');
    ss>>password>> coma;
    ss>>money;
    account holder;
    holder.setName(nombre);
    holder.setPin(password);
    holder.setBalance(money);
    plist.push_back(holder);
  }
  accounts.close();
}
void account::saveFile(vector<account> plist)
{
  ofstream my_ofile;
  stringstream stream;
  stream << fixed << setprecision(2) << balance;
  string s = stream.str();
  my_ofile.open("account.txt",std::ios_base::app);
  for(int i=0; i<plist.size(); i++)
  {
    my_ofile<<plist[i].getName()<<",";
    my_ofile<<plist[i].getBalance()<<",";
    my_ofile<<plist[i].getPin()<<"\n";
  }
  my_ofile.close();

}



