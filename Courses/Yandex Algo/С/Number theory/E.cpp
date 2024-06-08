#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long m, n;
    bool flag = true;
    cin >> m >> n;
    vector<bool> a(n + 1, true);
    a[0] = a[1] = false;
    for (long long i = 2; i <= n; i++){
        if (a[i]){
            for (long long j = i*i; j <= n; j += i)
                a[j] = false;
        }
    }
    for (long long i = m; i <= n; ++i) {
        if (a[i]) {
            cout << i << endl;
            flag = false;
        }
    }
    if (flag)
        cout << -1;
}