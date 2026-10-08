#include <iostream>
#include <vector>

using namespace std;

class StudentInfo
{
private:
    string _FirstName;
    string _LastName;
    int _ID;
    int _Age;
    double _GPA;

public:
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string GetFirstName()
    {
        return _FirstName;
    }
    /*===========================================*/
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    string GetLastName()
    {
        return _LastName;
    }
    /*================================================*/

    void SetID(int ID)
    {
        _ID = ID;
    }
    int GetID()
    {
        return _ID;
    }

    /*==============================================*/
    void SetGPA(double GPA)
    {
        if (GPA >= 0 && GPA <= 4)
        {
            _GPA = GPA;
        }
    }
    double GetGPA()
    {
        return _GPA;
    }
    /*=================================================*/
    void SetAge(int Age)
    {
        if (Age >= 17 && Age <= 30)
        {
            _Age = Age;
        }
    }
    int GetAge()
    {
        return _Age;
    }
    /*===================================================*/
    void PrintInfo()
    {
        cout << "FirstName: " << _FirstName << endl;
        cout << "LastName : " << _LastName << endl;
        cout << "GPA: " << _GPA;
        cout << "\nAge: " << _Age;
        cout << "\nID: ";
        cout << _ID;
    }
};
void PrintAllStudentsInfo(vector<StudentInfo> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        cout << "Student " << i + 1 << endl;
        students[i].PrintInfo();
        cout << endl
             << endl;
    }
}
int EnterID()
{
    int ID;
    cout << "Enter Your ID : " << endl;
    cin >> ID;
    return ID;
}

void FindStudentByID(int ID, vector<StudentInfo> &students)
{
    int found = 0;
    for (int i = 0; i < students.size(); i++)
    {
        if (ID == students[i].GetID())
        {
            students[i].PrintInfo();
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Student Not Found !" << endl;
    }
}
void AddStudent(vector<StudentInfo> &students)
{
    StudentInfo student;
    cout << "Enter Student First Name : ";
    string FirstName;
    cin >> FirstName;
    student.SetFirstName(FirstName);
    cout << "Enter Student Last Name : ";
    string LastName;
    cin >> LastName;
    student.SetLastName(LastName);
    cout << "Enter Student GPA : ";
    double GPA;
    cin >> GPA;
    while (GPA < 0 || GPA > 4)
    {
        cout << "Enter  a correct Student GPA : ";
        cin >> GPA;
    }

    student.SetGPA(GPA);
    cout << "Enter Student Age : ";
    int Age;
    cin >> Age;
    student.SetAge(Age);
    cout << "Enter Student ID : ";
    int ID;
    cin >> ID;
    student.SetID(ID);
    students.push_back(student);
}
void DeleteStudentByID(vector<StudentInfo> &students)
{
    cout << " Enter ID for the Student you want delete :";
    int ID;
    cin>>ID;
    int found = 0;
    for (int i = 0; i < students.size(); i++)
    {
        if (ID==students[i].GetID())
        {
            students.erase(students.begin() + i);
            cout<<"Student Deleted Successfully !"<<endl;
            found = 1;
            break;
        }
        
    }
    if (found == 0)
    {
        cout << "Student Not Found !" << endl;
    }
    
}

int main()
{
    vector<StudentInfo> students;
    StudentInfo student1, student2, student3;

    student1.SetFirstName("Ali");
    student1.SetLastName("Osama");
    student1.SetGPA(3.5);
    student1.SetAge(20);
    student1.SetID(1001);

    student2.SetFirstName("Ahmed");
    student2.SetLastName("Mohamed");
    student2.SetGPA(3.8);
    student2.SetAge(22);
    student2.SetID(1002);

    student3.SetFirstName("Omar");
    student3.SetLastName("Hassan");
    student3.SetGPA(3.2);
    student3.SetAge(19);
    student3.SetID(1003);

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

    PrintAllStudentsInfo(students);
    cout << "==========================================\n";
    cout << "student.Info for One Student :\n";
    int ID = EnterID();
    FindStudentByID(ID, students);
    cout << "==========================================\n";
    int Num;
    cout << "How Many Students You Want To Add : ";
    cin >> Num;
    for (int i = 0; i < Num; i++)
    {
        AddStudent(students);
        cout << "Your Student Added Successfully !\n";
    }
    cout << "==========================================\n";
    cout<<"How Many Students You Want To Delete : ";
    int NumDelete;
    cin>>NumDelete;
    for(int i=0;i<NumDelete;i++)
    {
        DeleteStudentByID(students);
    }

    return 0;
    
}