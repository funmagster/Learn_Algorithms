#include <iostream>
using namespace std;

unsigned long long fast_pow(unsigned long long a, unsigned long long n, unsigned long long mod) {
    unsigned long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    unsigned long long n;
    unsigned long long mod = 1e9 + 7;
    cin >> n;
    
    unsigned long long a = fast_pow(3, 3 * n, mod);
    unsigned long long b = fast_pow(7, n, mod);
    cout << (a - b + mod) % mod << endl;
    
    return 0;
}
    