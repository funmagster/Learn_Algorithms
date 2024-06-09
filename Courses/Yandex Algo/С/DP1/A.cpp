#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a = 1, b = 1, n, c;
    cin >> n;
    if (n < 3)
        cout << 1;
    else{
        for (int i = 3; i <= n; i++){
            c = b;
            b += a;
            a = c;
        }
        cout << b;
    }
    return 0;
}