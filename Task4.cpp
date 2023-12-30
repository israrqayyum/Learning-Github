#include <iostream>
#include <string>
using namespace std;
class Employee{
protected:
    string name,jobTitle;
    int day,month,year;
public:
    Employee(string name, string jobTitle, int day, int month, int year)
    :name(name),jobTitle(jobTitle),day(day),month(month),year(year){}
    virtual void display() {
        cout<<"Name:"<<name<<"\nJob Title:"<<jobTitle<<"\nDate: "<<day<<"-"<< month<<"-"<<year<<endl;
    }
};
class Manager:public Employee{
private:
    string exp;
public:
    Manager(string name, string jobTitle,int day,int month,int year,string exp)
        :Employee(name,jobTitle,day,month,year),exp(exp){}
    void display() 
    override{
        Employee::display();
        cout<<"Experience: "<<exp<<endl;
    }
};
class Teacher:public Employee{
private:
    string quali;
public:
    Teacher(string name,string jobTitle,int day,int month,int year,string quali)
        :Employee(name,jobTitle,day,month,year),quali(quali){}
    void display()
    override{
        Employee::display();
        cout<<"Qualification: "<<quali<<endl;
    }
};

class RegularlyTeacher:public Teacher{
private:
    double monthlySalary;
public:
    RegularlyTeacher(string name,string jobTitle,int day,int month,int year,string quali,double monthlySalary)
        :Teacher(name,jobTitle,day,month,year,quali),monthlySalary(monthlySalary){}
    void display()
    override{
        Teacher::display();
        cout<<"Monthly Salary: "<<monthlySalary<<endl;
    }
};

class VisitingTeacher:public Teacher{
private:
    double payRate;
    int hours;
public:
    VisitingTeacher(string name,string jobTitle,int day,int month,int year,string quali,double payRate,int hours)
        :Teacher(name,jobTitle,day,month,year,quali),payRate(payRate),hours(hours){}
    void display() 
    override{
        Teacher::display();
        cout<<"Pay Rate: "<<payRate<<"\nHours: "<<hours<<endl;
    }
};
int main(){
    while (true){
        cout<<"Choose an option:" << endl;
        cout<<"1.Enter Employee Data"<<endl;
        cout<<"2.Enter Manager Data"<<endl;
        cout<<"3.Enter Teacher Data"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
        case 1:{
            cout<<"\nEnter Employee Data"<<endl;
            cout<<"Name: ";
            string empName;
            cin.ignore();
            getline(cin,empName);
            cout<<"Job Title: ";
            string empJobTitle;
            getline(cin,empJobTitle);
            cout<<"Day of Birth: ";
            int empDay;
            cin>>empDay;
            cout<<"Month of Birth: ";
            int empMonth;
            cin>>empMonth;
            cout<<"Year of Birth: ";
            int empYear;
            cin>>empYear;
            Employee e(empName,empJobTitle,empDay,empMonth,empYear);
            e.display();
            break;
        }
        case 2:{
            cout<<"\nEnter Manager Data"<<endl;
            cout<<"Name: ";
            string mgrName;
            cin.ignore();
            getline(cin,mgrName);
            cout<<"Job Title: ";
            string mgrJobTitle;
            getline(cin,mgrJobTitle);
            cout<<"Day of Birth: ";
            int mgrDay;
            cin>>mgrDay;
            cout<<"Month of Birth: ";
            int mgrMonth;
            cin>>mgrMonth;
            cout<<"Year of Birth: ";
            int mgrYear;
            cin>>mgrYear;
            cin.ignore();
            cout<<"Experience: ";
            string mgrExp;
            getline(cin,mgrExp);
            Manager m(mgrName,mgrJobTitle,mgrDay,mgrMonth,mgrYear,mgrExp);
            m.display();
            break;
        }
        case 3:{
            cout<<"\nEnter Teacher Data"<<endl;
            cout<<"Name: ";
            string teacherName;
            cin.ignore();
            getline(cin,teacherName);
            cout<<"Job Title: ";
            string teacherJobTitle;
            getline(cin,teacherJobTitle);
            cout<<"Day of Birth: ";
            int teacherDay;
            cin>>teacherDay;
            cout<<"Month of Birth: ";
            int teacherMonth;
            cin>>teacherMonth;
            cout<<"Year of Birth: ";
            int teacherYear;
            cin>>teacherYear;
            cin.ignore();
            cout<<"Qualification: ";
            string teacherQuali;
            getline(cin,teacherQuali);
            cout<<"Enter type of Teacher (1 - Regular, 2 - Visiting): ";
            int teacherType;
            cin>>teacherType;
            if(teacherType==1){
                cout<<"Monthly Salary: ";
                double teacherMonthlySalary;
                cin>>teacherMonthlySalary;
                RegularlyTeacher r(teacherName,teacherJobTitle,teacherDay,teacherMonth,teacherYear,teacherQuali,teacherMonthlySalary);
                r.display();
            } 
            else if(teacherType==2){
                cout << "Pay Rate: ";
                double teacherPayRate;
                cin>>teacherPayRate;
                cout<<"Hours: ";
                int teacherHours;
                cin>>teacherHours;
                VisitingTeacher v(teacherName,teacherJobTitle,teacherDay,teacherMonth,teacherYear,teacherQuali,teacherPayRate,teacherHours);
                v.display();
            }
            break;
        }
        case 4:
            exit(0);
        default:
            cout<<"Invalid choice."<<endl;
        }
    }
    return 0;
}