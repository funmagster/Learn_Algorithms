#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 2;
        return 0;
    }

    vector<int> a(n), b(n), c(n);
    a[0] = b[0] = 1;
    c[0] = 0;

    for (int i = 1; i < n; i++){
        a[i] = a[i - 1] + b[i - 1] + c[i - 1];
        b[i] = a[i - 1];
        c[i] = b[i - 1];
    }
    cout << a[n - 1] + b[n - 1] + c[n - 1];
    return 0;
}
