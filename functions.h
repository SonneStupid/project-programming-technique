#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sys\stat.h>
#include <dirent.h>
#include <conio.h> //take getCh() from this library
#include <stdio.h>
#include <iomanip> //format into table data
using namespace std;

struct Student
{
    string no, ID, LastName, FirstName, Gender, DateOfBirth, SocialID, Password;
};

struct Node
{
    Student student;
    Node *next;
};

struct Staff
{
    string no, ID, LastName, FirstName, Gender, Email, Password;
};

struct StaffList
{
    Staff staff;
    StaffList *next;
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Course
{
    string id, name, teacherName, max, s1Time, s1Date, s2Time, s2Date;
    Date startDate, endDate;
    int numberOfCredits = 50;
};

struct CourseList
{
    Course course;
    CourseList *next;
};

void start();
void loginSection();
void openCSVFileFromUserInput();

// student
void StudentLoginSection();
void displayStudentInfo(string classAddress);
void changePassword();
void updatePasswordChangeToCSVFile(string classAddress);
void ExtractStudentInClass(Node *&pHead, string schoolYear, string className);
void writeCSVFile(string classAddress);

void findStudentInAClass(string curID, string address, bool &isStudentExist, string password);
bool findStudentWithID(string ID, string &classAddress, string password);

// staff
void AcademicStaffLoginSection();
void StaffMenu();
void viewStaffPersonalInfo(Staff staff, StaffList *&pHead);
bool validateStaff(string username, string password, StaffList *pHead, Staff &staff);
void ExtractStaffInfoAndTurnToSLL(StaffList *&pHead);
void writeChangesToStaffCSV(StaffList *pHead);
void changeStaffPassword(Staff &staff, StaffList *&pHead);
void viewSchoolYear();
void viewClassesInSchoolYear(string address, string schoolYear);
void viewStudentInClass(string address, string className, string schoolYear);
void createNewSchoolYear();
void viewSemesters(string address, string schoolYear);
void viewCourse(string address, string schoolYear, string term);
void CreateSemester(string address, string schoolYear);
void createNewCourse(string address, string schoolYear, string term);
bool checkDay(string day);
bool checkTime(string time);
bool checkdate(int d, int m, int y);
void viewCourseInfo(string address, string schoolYear, string term, string nameCourse);

// Files
void createNewDirectory(string url);
void ListAllFileNames(string address, bool isFile, string arr[], int &num);
string removeType(string s);

// format
template <class T>
void printElement(T t, const int &width);