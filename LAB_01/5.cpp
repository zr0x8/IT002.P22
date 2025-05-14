#include <iostream>
using namespace std;

class Date
{
    private:
        int day, month, year;

    public:
        // constructors
        Date() : day(1), month(1), year(1970) {};

        // custom operator

        Date &operator=(const Date &date)
        {
            if (this == &date) { return *this; }
            this->day = date.day;
            this->month = date.month;
            this->year = date.year;
            return *this;
        }

        bool isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
        void getInput()
        {
            char first_slash{}, second_slash{};
            do {
                cout << "Vui long nhap ngay ban muon tinh (theo dinh dang DD/MM/YYYY): ";
                cin >> this->day >> first_slash >> this->month >> second_slash >> this->year;
                if (first_slash != '/' || second_slash != '/' || this->day < 1 || this->day > 31 || this->month < 1 ||
                    this->month > 12 || this->year < 1970)
                {
                    cout << "\nDinh dang khong hop le, vui long nhap lai!\n";
                }
            }
            while (first_slash != '/' || second_slash != '/' || this->day < 1 || this->day > 31 || this->month < 1 ||
                   this->month > 12 || this->year < 1970);
        }
        void nextDay()
        {
            Date result = *this;
            bool is_leap_year = isLeapYear(this->year);
            if (this->day == 31 &&
                (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 ||
                 this->month == 10))
            {
                result.day = 1;
                result.month++;
            }
            else if (this->day == 30 && this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
            {
                result.day = 1;
                result.month++;
            }
            else if (this->day == 31 && this->month == 12)
            {
                result.day = 1;
                result.month = 1;
                result.year++;
            }
            else if (result.month == 2 && ((this->day == 29 && is_leap_year) || (this->day == 28 && !is_leap_year)))
            {
                result.day = 1;
                result.month = 3;
            }
            else { result.day++; }
            cout << "Ngay tiep theo la: " << result.day << "/" << result.month << "/" << result.year << endl;
        }

        void previousDay()
        {
            Date result = *this;
            bool is_leap_year = isLeapYear(this->year);
            if (this->day == 1 && (this->month == 5 || this->month == 7 || this->month == 10 || this->month == 12))
            {
                result.day = 30;
                result.month--;
            }
            else if (this->day == 1 &&
                     (this->month == 2 || this->month == 4 || this->month == 6 || this->month == 8 ||
                      this->month == 9 || this->month == 11))
            {
                result.day = 31;
                result.month--;
            }
            else if (this->day == 1 && this->month == 1)
            {
                result.day = 31;
                result.month = 12;
                result.year--;
            }
            else if (this->day == 1 && result.month == 3)
            {
                is_leap_year ? result.day = 29 : result.day = 28;
                result.month = 2;
            }
            else { result.day--; }
            cout << "Ngay truoc do la: " << result.day << "/" << result.month << "/" << result.year << endl;
        }
        void positionInYear()
        {
            int position{this->day}; // cong ngay trong thang do truoc cho chac (vd: 2/1 thi la ngay thu 2 trong nam)
            switch (this->month - 1) //tinh them nhung ngay cua thang truoc
            {
            case 11: position += 30;
            case 10: position += 31;
            case 9: position += 30;
            case 8: position += 31;
            case 7: position += 31;
            case 6: position += 30;
            case 5: position += 31;
            case 4: position += 30;
            case 3: position += 31;
            case 2: position += isLeapYear(this->year) ? 29 : 28;
            case 1: position += 31;
            default: break; // thang 1 thi khoi cong gi them het cho met
            }

            cout << this->day << "/" << this->month << "/" << this->year << " la ngay thu " << position
                 << " trong nam\n";
        }
};

int main(void)
{
    Date today;
    today.getInput();
    today.nextDay();
    today.previousDay();
    today.positionInYear();
    return 0;
}
