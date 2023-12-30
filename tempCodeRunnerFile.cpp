#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
  Employee(string name, string job, int day, int month, int year)
    : name(name), job(job), day(day), month(month), year(year) {}

  virtual void display() {
    cout << "Employee: " << name << " | Job: " << job << " | Date of Birth: " << day << "/" << month << "/" << year << endl;
  }

protected:
  string name, job;
  int day, month, year;
};

class Manager : public Employee {
public:
  Manager(string name, string job, int day, int month, int year, string totalExp)
    : Employee(name, job, day, month, year), totalExp(totalExp) {}

  void display() override {
    Employee::display();
    cout << "Total Experience: " << totalExp << endl;
  }

private:
  string totalExp;
};

class Teacher : public Employee {
public:
  Teacher(string name, string job, int day, int month, int year, string qualifi)
    : Employee(name, job, day, month, year), qualifi(qualifi) {}

  void display() override {
    Employee::display();
    cout << "Qualification: " << qualifi << endl;
  }

protected:
  string qualifi;
};

class RegularlyTeacher : public Teacher {
public:
  RegularlyTeacher(string name, string job, int day, int month, int year, string qualifi, double salary)
    : Teacher(name, job, day, month, year, qualifi), monthlySalary(salary) {}

  void display() override {
    Teacher::display();
    cout << "Monthly Salary: " << monthlySalary << endl;
  }

private:
  double monthlySalary;
};

class VisitingTeacher : public Teacher {
public:
  VisitingTeacher(string name, string job, int day, int month, int year, string qualifi, double payRate, double hours)
    : Teacher(name, job, day, month, year, qualifi), payRate(payRate), hours(hours) {}

  void display() override {
    Teacher::display();
    cout << "Pay Rate: " << payRate << " | Hours: " << hours << endl;
  }

private:
  double payRate, hours;
};
int main() {
  Employee* employee = nullptr;

  do {
    cout << "1. Add Employee" << endl;
    cout << "2. Display" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    cin.ignore(); // Consume newline

    switch (choice) {
      case 1:
        if (employee != nullptr) {
          delete employee;
        }

        cout << "1. Manager" << endl;
        cout << "2. Regularly Teacher" << endl;
        cout << "3. Visiting Teacher" << endl;
        cout << "Enter employee type: ";

        int empType;
        cin >> empType;
        cin.ignore(); // Consume newline

        string name, job, qualifi, totalExp;
        int day, month, year;
        double monthlySalary, payRate, hours;

        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter job: ";
        getline(cin, job);
        cout << "Enter day of birth: ";
        cin >> day;
        cout << "Enter month of birth: ";
        cin >> month;
        cout << "Enter year of birth: ";
        cin >> year;

        switch (empType) {
          case 1:
            cout << "Enter total experience: ";
            getline(cin, totalExp);
            employee = new Manager(name, job, day, month, year, totalExp);
            break;
          case 2:
            cout << "Enter qualification: ";
            getline(cin, qualifi);
            cout << "Enter monthly salary: ";
            cin >> monthlySalary;
            cin.ignore(); // Consume newline
            employee = new RegularlyTeacher(name, job, day, month, year, qualifi, monthlySalary);
            break;
          case 3:
            cout << "Enter qualification: ";
            getline(cin, qualifi);
            cout << "Enter pay rate: ";
            cin >> payRate;
            cout << "Enter hours: ";
            cin >> hours;
            cin.ignore(); // Consume newline
            employee = new VisitingTeacher(name, job, day, month, year, qualifi, payRate, hours);
            break;
          default:
            cout << "Invalid employee type" << endl;
            break;
        }

        // Display the employee information if an employee has been added
        if (employee != nullptr) {
          employee->display();
        }
        break;
      case 2:
        if (employee != nullptr) {
          employee->display();
          cout << endl;
        } else {
          cout << "No employee to display. Add an employee first." << endl;
        }
        break;
      case 3:
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice. Please enter again." << endl;
    }
  } while (choice != 3);

  // Delete the employee object if it has been initialized
  if (employee != nullptr) {
    delete employee;
  }

  return 0;
}
