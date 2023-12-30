#include<iostream>
 using namespace std;
 int main(){
    int year;
    cout<<"Enter number of years:";
    cin>>year;
    int mincalc=(year*365*24*60);
    int seccalc=(year*365*24*3600);
    cout<<"No.of Minutes:"<<mincalc<<endl;
    cout<<"No.of Seconds:"<<seccalc<<endl;
    return 0;
 }