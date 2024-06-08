#include <iostream>

using namespace std;


long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    long long n, k;
    cin >> n >> k;

    cout << n / gcd(n, k) * k << endl;

    return 0;
}
