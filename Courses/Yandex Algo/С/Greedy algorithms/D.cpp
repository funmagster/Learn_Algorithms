#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    while (m >= 1 and n >= 2){
        cout << "GGB";
        m--;
        n -= 2;
    }
    for (int i = 0; i < n; i++)
        cout << 'G';
    for (int i = 0; i < m; i++)
        cout << 'B';
    return 0;
}