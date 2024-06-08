#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    float c;
    cin >> c;
    float l = 0.0, r = 1e7, mid;
    while (r - l > 1e-7) {
        mid = (l + r) / 2.0;
        if (mid * mid + sqrt(mid) >= c)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}
