#include "student.h"

vector<Student> Student::students;

int main()
{
    int n{},choice{0};
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    vector<Student> student_list(n);

    for (int i = 0; i < n; i++)
    {
        student_list [i].getInput();
    }
    Student::setStudents(student_list);
    do
    {
        clrscr;
        cout << "Chon chuc nang can dung: \n"
                "[1] Xem lai danh sach hoc sinh.\n"
                "[2] Tim kiem hoc sinh.\n"
                "[3] Hoc sinh co diem trung binh cao nhat.\n"
                "[4] Danh sach hoc sinh co diem toan thap nhat\n\n"
                "Bam phim [0] de thoat chuong trinh.\n\n"
                "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                clrscr;
                for (int i = 0; i < n; i++)
                {
                    student_list [i].printInfo("==============================", false);
                }
                cout << "Bam phim bat ky de tiep tuc...";
                cin.ignore();
                cin.get();
                break;
            }
        case 2:
            {
                clrscr;
                string name;
                cout << "Nhap ten hoc sinh can tim: ";
                cin.ignore();
                getline(cin, name);
                Student::findStudents(name);
                cout << "Bam phim bat ky de tiep tuc...";
                cin.ignore();
                cin.get();
                break;
            }
        case 3:
            {
                clrscr;
                Student highest = Student::getHighestAverageScore();
                highest.printInfo("Hoc sinh co diem trung binh cao nhat la: ", false);
                cout << "Bam phim bat ky de tiep tuc...";
                cin.ignore();
                cin.get();
                break;
            }
        case 4:
            {
                clrscr;
                Student::getLowestMathScore();
                cout << "Bam phim bat ky de tiep tuc...";
                cin.ignore();
                cin.get();
                break;
            }
        default:
            {
                clrscr;
                cout << "Chuc nang khong ton tai. Vui long chon lai.\n"
                        "Bam phim bat ki de tiep tuc.";
                cin.ignore();
                cin.get();
                break;
            }
        }
    }
    while (choice != 0);
    return 0;
}
