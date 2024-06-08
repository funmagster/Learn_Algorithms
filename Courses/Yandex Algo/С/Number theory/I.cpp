#include <iostream>
#include <numeric>

using namespace std;

int main(){
    int n, elem_1, elem_2;
    cin >> n;
    if (n == 1){
        cin >> elem_1;
        cout << elem_1;
    }
    else if (n == 2){
        cin >> elem_1 >> elem_2;
        cout << gcd(elem_1, elem_2);
    }
    else{
        cin >> elem_1 >> elem_2;
        elem_1 = gcd(elem_1, elem_2);
        for (int i = 2; i < n; i++){
            cin >> elem_2;
            elem_1 = gcd(elem_1, elem_2);
        }
        cout << elem_1;
    }
    return 0;
}