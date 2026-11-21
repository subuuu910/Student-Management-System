#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string course;
};

Student s[100];
int count = 0;

void loadStudents()
{
    count = 0;

    ifstream file("students.txt");

    while (count < 100 &&
           file >> s[count].id
                >> s[count].name
                >> s[count].age
                >> s[count].course)
    {
        count++;
    }

    file.close();
}

void saveStudents()
{
    ofstream file("students.txt");

    for (int i = 0; i < count; i++)
    {
        file << s[i].id << " "
             << s[i].name << " "
             << s[i].age << " "
             << s[i].course << endl;
    }

    file.close();
}

void addStudent()
{
    if (count >= 100)
    {
        cout << "\nStudent Limit Reached!\n";
        return;
    }

    Student temp;

    cout << "\nEnter Student ID: ";
    cin >> temp.id;

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == temp.id)
        {
            cout << "\nStudent ID Already Exists!\n";
            return;
        }
    }

    cout << "Enter Student Name: ";
    cin >> temp.name;

    cout << "Enter Age: ";
    cin >> temp.age;

    cout << "Enter Course: ";
    cin >> temp.course;

    s[count] = temp;
    count++;

    saveStudents();

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    if (count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n========== STUDENT DETAILS ==========\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nStudent ID: " << s[i].id;
        cout << "\nStudent Name: " << s[i].name;
        cout << "\nAge: " << s[i].age;
        cout << "\nCourse: " << s[i].course;
        cout << "\n-------------------------------------\n";
    }
}

void updateStudent()
{
    int id;
    bool found = false;

    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            cout << "\nEnter New Name: ";
            cin >> s[i].name;

            cout << "Enter New Age: ";
            cin >> s[i].age;

            cout << "Enter New Course: ";
            cin >> s[i].course;

            found = true;

            saveStudents();

            cout << "\nStudent Updated Successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent ID Not Found!\n";
    }
}

void deleteStudent()
{
    int id;
    bool found = false;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            count--;
            found = true;

            saveStudents();

            cout << "\nStudent Deleted Successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent ID Not Found!\n";
    }
}

int main()
{
    loadStudents();

    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n       STUDENT MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Student";
        cout << "\n2. Update Student";
        cout << "\n3. Delete Student";
        cout << "\n4. Display Students";
        cout << "\n5. Exit";
        cout << "\n====================================";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                updateStudent();
                break;

            case 3:
                deleteStudent();
                break;

            case 4:
                displayStudents();
                break;

            case 5:
                cout << "\nThank You for Using Student Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}