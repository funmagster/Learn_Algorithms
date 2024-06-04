#include <iostream>
#include <vector>

using namespace std;
int main(){
    long long n, res;
    cin >> n;
    long long a = 1, b = 1;
    long long i = 1, j = 1, k = 0;

    while (k < n + 1) {
        if (a <= b) {
            res = a;
            i++;
            a = i*i;
            if (a != b)
                k++;
        } else {
            res = b;
            j++;
            b = j*j*j;
            k++;
        }
    }
    cout << res;
}