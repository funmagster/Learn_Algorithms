#include <iostream>

using namespace std;

int gcd_ext(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcd_ext(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main() {
    int a, b, c;
    int x, y;
    cin >> a >> b >> c;
    int gcd = gcd_ext(a, b, x, y);
    if (c % gcd != 0)
        cout << "Impossible";
    else{
        int k = c / gcd;
        x *= k;
        y *= k;
        cout << gcd << ' ' << x << ' ' << y;
    }
    return 0;
}
