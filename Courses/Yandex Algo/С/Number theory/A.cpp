#include <iostream>

using namespace std;

int main(){
    unsigned int n;
    bool flag = true;
    cin >> n;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            cout << "composite";
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "prime";

    return 0;
}