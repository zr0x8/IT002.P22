#include <iostream>
#include <string>
using namespace std;

void getInput(string position, double& a, int& b) {
    char slash;
    do {
        cout << "Vui long nhap phan so ban muon tinh (theo dinh dang x/y): ";
        cin >> a >> slash >> b;
        if (slash != '/' || b == 0) {
            cout << "\nDinh dang khong hop le\n";
        }
    } while (slash != '/' || b == 0);
    a /= b;
}

int main(void) {
    double first_numerator_or_fraction, second_numerator_or_fraction;
    int first_denominator, second_denominator;
    getInput("nhat", first_numerator_or_fraction, first_denominator);
    getInput("hai", second_numerator_or_fraction, second_denominator);
    cout << "Tong hai phan so la: " << first_numerator_or_fraction + second_numerator_or_fraction << "\n";
    cout << "Hieu hai phan so la: " << first_numerator_or_fraction - second_numerator_or_fraction << "\n";
    cout << "Tich hai phan so la: " << first_numerator_or_fraction * second_numerator_or_fraction << "\n";
    cout << "Thuong hai phan so la: " << first_numerator_or_fraction / second_numerator_or_fraction << "\n";
    
    return 0;
}