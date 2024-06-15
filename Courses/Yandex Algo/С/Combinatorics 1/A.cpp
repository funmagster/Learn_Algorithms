#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    long long n, a, b, c;
    cin >> n;

    a = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    b = a * (n - 5) / 6;
    c = b * (n - 6) / 7;
    cout << a + c + b;
    return 0;
}