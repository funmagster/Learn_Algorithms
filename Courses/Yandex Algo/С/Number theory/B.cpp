#include <iostream>

using namespace std;

int main(){
    unsigned int n;
    cin >> n;

    int i = 2;
    while (n > 1 and i*i <= n){
        while (n % i == 0){
            n /= i;
            cout << i << ' ';
        }
        i++;
    }
    if (n > 1)
        cout << n;
    return 0;
}