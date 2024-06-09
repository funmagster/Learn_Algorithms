#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    a[0] = 1;
    b[0] = 2;
    for (int i = 1; i < n; i++){
        a[i] = b[i - 1];
        b[i] = (a[i - 1] + b[i - 1]) * 2;
    }
    cout << a[n - 1] + b[n - 1];
    return 0;
}