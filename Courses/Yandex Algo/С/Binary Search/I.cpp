#include <iostream>

using namespace std;

bool ok(long long w, long long h, long long n, long long sizes){
    return (sizes / h) * (sizes / w) >= n;
}

int main(){
    long long w, h, n;
    cin >> w >> h >> n;

    long long l = 0, r = max(w, h) * n, mid;
    while (r - l > 1){
        mid = (r + l) / 2;
        if (ok(w, h, n, mid))
            r = mid;
        else
            l = mid;
    }
    cout << r;
    return 0;
}