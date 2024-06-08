#include <iostream>

using namespace std;


bool ok(long long d, long long w, long long h, long long a, long long b, long long n){
    return (h / (b + 2*d)) * (w / (a + 2*d)) >= n;
}

int main(){
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    if (w > h)
        swap(w, h);
    if (a > b)
        swap(a, b);

    long long l = 0, r = 1e18, mid;
    while (r - l > 1){
        mid = (r + l) / 2;
        if (ok(mid, w, h, a, b, n) || ok(mid, w, h, b, a, n))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}