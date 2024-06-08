#include <iostream>
#include <numeric>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int numerator = a*d + c*b;
    int denominator = b*d;
    int GCD = gcd(numerator, denominator);
    cout << numerator / GCD << ' ' << denominator / GCD;
    return 0;
}