#include <iostream>

using namespace std;

int main(){
    int m, n, temp;
    cin >> m >> n;
    
    while (m != 0){
        if (m > n)
            swap(m, n);
        temp = m;
        m = n % m;
        n = temp;

    }
    cout << max(m, n);
}