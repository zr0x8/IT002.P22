#include <iostream>
#include <string>

using namespace std;

int greatestCommonDivisor(int a, int b) { //tim UCLN
    if (a == 0) {
        return b;
    }
    return greatestCommonDivisor(b % a, a);
}

string minimizeFraction(int &numerator, int &denominator) {
    if (numerator == 0) {
        return "0"; //tu so bang 0 thi ca phan so bang 0
    } else if (numerator == denominator) {
        return "1"; //tu so bang mau so thi phan so bang 1
    }
    int gcd = greatestCommonDivisor(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    return to_string(numerator) + "/" + to_string(denominator); //tra ve phan so toi gian duoi dang chuoi ki tu
}

int main(void) {
    int numerator{}, denominator{}; // numerator: tu so, denominator: mau so
    char slash{}; // ky tu '/'
    do {
        cout << "Nhap vao mot phan so (dinh dang x/y) [y khac 0]: ";
        cin >> numerator >> slash >> denominator;
        if (slash != '/' || denominator == 0) {
            cout << "Dinh dang khong hop le, vui long nhap lai.\n";
        }
    } while (slash != '/' || denominator == 0); // neu ki tu phan chia tu so va mau so khong phai la '/' hoac mau so bang 0 thi nhap lai
    
    cout << numerator << "/" << denominator << " sau khi toi gian la: ";
    cout << minimizeFraction(numerator, denominator) << "\n";
    return 0;
}