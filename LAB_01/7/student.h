#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stdlib.h>

#define clrscr system("cls")

using namespace std;

class Student
{
private:
    string name, ranking, raw_name;
    double math_score;
    double english_score;
    double literature_score;
    double average_score;
    static vector<Student> students;

public:
    // custom operator

    Student &operator=(const Student &student)
    {
        if (this == &student)
        {
            return *this;
        }
        this->name = student.name;
        this->raw_name = student.raw_name;
        this->math_score = student.math_score;
        this->english_score = student.english_score;
        this->literature_score = student.literature_score;
        this->average_score = student.average_score;
        this->ranking = student.ranking;
        return *this;
    }

    // constructor

    Student() :
        name("NULL"), raw_name("null"), math_score(0), english_score(0), literature_score(0), average_score(0) {};

    // deconstructor

    ~Student() {};

    // forward declaration
    void getInput();
    void printInfo(const string &text_to_display, bool clear_screen = true) const;
    void setRawName(const string &name);
    static void setStudents(const vector<Student> students_list);
    static Student getHighestAverageScore();
    static void findStudents(const string &name);
    static void getLowestMathScore();

};

void Student::getInput()
{
    clrscr;
    cin.ignore();
    cout << "Nhap ho va ten cua hoc sinh: ";
    getline(cin, this->name);
    setRawName(this->name);
    clrscr;
    cout << "Nhap diem toan: ";
    cin >> this->math_score;
    clrscr;
    cout << "Nhap diem tieng Anh: ";
    cin >> this->english_score;
    clrscr;
    cout << "Nhap diem van: ";
    cin >> this->literature_score;
    this->average_score = (2 * this->math_score + this->english_score + this->literature_score) / 4;
    if (this->average_score >= 9)
    {
        this->ranking = "Xuat sac";
    }
    else if (this->average_score >= 8)
    {
        this->ranking = "Gioi";
    }
    else if (this->average_score >= 6.5)
    {
        this->ranking = "Kha";
    }
    else if (this->average_score >= 5)
    {
        this->ranking = "Trung binh";
    }
    else
    {
        this->ranking = "Yeu";
    }
}
inline void Student::printInfo(const string &text_to_display, bool clear_screen) const
{
    if (clear_screen)
    {
        clrscr;
    }
    cout << text_to_display << '\n';
    cout << "Ho va ten: " << this->name << '\n';
    cout << "Diem toan: " << this->math_score << '\n';
    cout << "Diem tieng Anh: " << this->english_score << '\n';
    cout << "Diem van: " << this->literature_score << '\n';
    std::cout << "Diem trung binh: " << this->average_score << '\n';
    cout << "Xep loai: " << this->ranking << '\n';
    cout << "========================================\n";
}

inline void Student::setStudents(const vector<Student> students_list) { students = students_list; }

void Student::setRawName(const string &name)
{
    string raw_name = "";
    for (int i = 0; i < name.length(); i++)
    {
        if (name [i] != ' ')
        {
            raw_name += tolower(name [i]);
        }
    }
    this->raw_name = raw_name;
}

Student Student::getHighestAverageScore()
{
    double max = students [0].average_score;
    Student highest = students [0];
    for (int i = 1; i < students.size(); i++)
    {
        if (students [i].average_score > max)
        {
            max = students [i].average_score;
            highest = students [i];
        }
    }
    return highest;
}

void Student::findStudents(const string &name)
{
    vector<Student> elegible_students;
    for (int i = 0; i < students.size(); i++)
    {
        if (students [i].raw_name.find(name) < students [i].raw_name.length())
        {
            elegible_students.push_back(students [i]);
        }
    }
    if (elegible_students.size() == 0)
    {
        clrscr;
        cout << "Khong tim thay hoc sinh: " << name << '\n';
    }
    else
    {
        clrscr;
        cout << "Co " << elegible_students.size() << " hoc sinh co ten :" << name << '\n';
        for (int i = 0; i < elegible_students.size(); i++)
        {
            elegible_students [i].printInfo("========================================", false);
        }
    }
}

void Student::getLowestMathScore()
{
    double min = students [0].math_score;
    Student lowest = students [0];
    for (int i = 1; i < students.size(); i++)
    {
        if (students [i].math_score < min)
        {
            min = students [i].math_score;
            lowest = students [i];
        }
    }

    lowest.printInfo("Hoc sinh co diem thap nhat la: ");
}
