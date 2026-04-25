
#include <bits/stdc++.h>
using namespace std;

int extendedgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedgcd(b, a % b, x1, y1);
    cout<<
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int main() {
    int a, b;
    cin >> a >> b;
    int x, y;

    int gcd = extendedgcd(a, b, x, y);


    cout << "GCD: " << gcd << endl;
    cout << "x: " << x << ", y: " << y << endl;
}
