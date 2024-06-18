#include <iostream>

using namespace std;

unsigned long long factorial(long long n){
    if (n < 2){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    long long n;
    cin >> n;
    cout << factorial(n);
    return 0;
}