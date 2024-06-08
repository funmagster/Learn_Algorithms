#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<bool> a(n + 1, true);
    a[0] = a[1] = false;
    for (long long i = 2; i <= n; i++){
        if (a[i]){
            for (long long j = i*i; j <= n; j += i)
                a[j] = false;
        }
    }
    for (long long i = 2; i <= n; i++){
        if (a[i] and a[n - i]){
            cout << i << ' ' << n - i;
            break;
        }
    }
    return 0;
}