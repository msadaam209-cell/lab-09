#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    // Task 2: Constructor for Person class
    Person(string n = "", int a = 0) : name(n), age(a) {}
    
    // Virtual function to allow polymorphism
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    
    // Getter for name
    string getName() const { return name; }
    
    // Getter for age
    int getAge() const { return age; }
};

// Derived class Student from Person
class Student : public Person {
private:
    int studentID;
    float gpa;

public:
    // Task 2: Constructor using Person constructor
    Student(string n = "", int a = 0, int id = 0, float g = 0.0) 
        : Person(n, a), studentID(id), gpa(g) {}
    
    // Task 1: display() function for Student
    void display() override {
        Person::display(); // Call base class display
        cout << "Student ID: " << studentID << endl;
        cout << "GPA: " << gpa << endl;
        cout << "------------------------" << endl;
    }
    
    // Setters and getters
    void setStudentID(int id) { studentID = id; }
    void setGPA(float g) { gpa = g; }
    int getStudentID() const { return studentID; }
    float getGPA() const { return gpa; }
};

// Task 3: Derived class Teacher from Person
class Teacher : public Person {
private:
    string subject;
    double salary;

public:
    // Constructor for Teacher
    Teacher(string n = "", int a = 0, string sub = "", double sal = 0.0)
        : Person(n, a), subject(sub), salary(sal) {}
    
    // Display function for Teacher
    void display() override {
        Person::display(); // Call base class display
        cout << "Subject: " << subject << endl;
        cout << "Salary: $" << salary << endl;
        cout << "------------------------" << endl;
    }
    
    // Setters and getters
    void setSubject(string sub) { subject = sub; }
    void setSalary(double sal) { salary = sal; }
    string getSubject() const { return subject; }
    double getSalary() const { return salary; }
};

int main() {
    // Task 4: Create at least two Student objects
    Student student1("Alice Johnson", 20, 1001, 3.8);
    Student student2("Bob Smith", 21, 1002, 3.5);
    
    // Display data for both students
    cout << "STUDENT INFORMATION:" << endl;
    cout << "====================" << endl;
    
    // Task 1: Call display() function
    student1.display();
    student2.display();
    
    // Task 3: Create Teacher objects
    Teacher teacher1("Dr. Williams", 45, "Computer Science", 75000);
    Teacher teacher2("Ms. Davis", 38, "Mathematics", 68000);
    
    // Display teacher information
    cout << "TEACHER INFORMATION:" << endl;
    cout << "====================" << endl;
    teacher1.display();
    teacher2.display();
    
    // Optional: Demonstrate array of Person pointers (polymorphism)
    cout << "POLYMORPHISM DEMONSTRATION:" << endl;
    cout << "============================" << endl;
    
    Person* people[4];
    people[0] = &student1;
    people[1] = &student2;
    people[2] = &teacher1;
    people[3] = &teacher2;
    
    for (int i = 0; i < 4; i++) {
        people[i]->display();
    }
    
    return 0;
}
