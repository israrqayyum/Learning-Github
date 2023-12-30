#include<iostream>
 using namespace std;
 int main(){
    double amount,taxrate;
    cout<<"Enter amount: ";
    cin>>amount;
    cout<<"Enter the Tax Rate:";
    cin>>taxrate;
    double taxcalc=(amount*(taxrate/100));
    //calculation of tax
    cout<<"Tax is:"<<taxcalc;
    return 0;
 }