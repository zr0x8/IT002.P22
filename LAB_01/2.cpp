#include <iostream>
#include <string>
using namespace std;

struct MyFraction {
    string fraction; //bien luu phan so duoi dang chuoi ki tu
    double value; //bien luu gia tri phan so (dung de so sanh)
};

void getInput(string position, int& a, int& b) { //ham nhap phan so
    /* position: nhap phan so thu may? (nhat, hai)
     * a: tu so
     * b: mau so
     */
    char slash{};
    do {
        cout << "Nhap phan so thu " << position << " (theo dinh dang a/b): ";
        cin >> a >> slash >> b;
        if (slash != '/' || b == 0) {
            cout << "\nDinh dang khong hop le\n";
        }
    } while (slash != '/' || b == 0);
}

MyFraction fraction(int &numerator, int& denominator) { //doi gia tri phan so
    MyFraction result;
    result.fraction = to_string(numerator) + "/" + to_string(denominator); //gom phan so goc
    result.value = static_cast<double>(numerator) / denominator; //gom gia tri cua phan so
    return result;
}

int main(void) {
    int first_numerator, first_denominator, second_numerator, second_denominator;
    getInput("nhat", first_numerator, first_denominator);
    getInput("hai", second_numerator, second_denominator);
    MyFraction first_fraction( fraction(first_numerator, first_denominator) ); //khoi tao phan so thu nhat voi gia tri tra ve cua ham fraction
    MyFraction second_fraction( fraction(second_numerator, second_denominator) ); //khoi tao phan so thu hai voi gia tri tra ve cua ham fraction
    cout << (first_fraction.value > second_fraction.value ? first_fraction.fraction : second_fraction.fraction); //so sanh gia tri cua hai phan so va in ra phan so co gia tri lon hon
}