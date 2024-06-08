#include <iostream>

using namespace std;

int main(){
    unsigned int n, cnt = 0;
    cin >> n;
    if (n == 1)
        cout << 1;
    else{
        int i = 2;
        while (i*i < n){
            if (n % i == 0)
                cnt += 2;
            i++;
        }
        if (n % i == 0)
            cnt += 1;
        cout << cnt + 2;
    }
    return 0;
}