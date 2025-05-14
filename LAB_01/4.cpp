#include <cmath>
#include <iostream>

#define PRECISION 1e-4

using namespace std;

double sinx(const double &x)
{
    double sin{x}, term{x};
    for (int i = 3; fabs(term) >= PRECISION; i += 2)
    {
        term *= -( x * x / (i * (i - 1))) ;
        sin += term;
    }

    return sin;
}

int main()
{
    double x{};
    cout << "Nhap gia tri x ma ban muon tinh sin(x): ";
    cin >> x;
    cout << "sin(" << x << ") = " << sinx(x) << endl;
    return 0;
}