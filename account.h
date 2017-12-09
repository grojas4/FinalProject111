#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

class account
{
  private:
    string name;
    int pin;
    float balance;
  
  public:
    account();
    void addMoney();
    void removeMoney();
    float readBalance();
    string addName();
    int addPin();
    bool verifyPin(int);  
    void saveFile(vector<account> plist);
    void pullFile(vector<account>& plist);
    void setName(string);
    void setPin(int);
    void setBalance(float);
    string getName();
    int getPin();
    float getBalance();

};
#endif
