#include <iostream>

using namespace std;

int main(){
    int A, i;
    cin >> A >> i;
    cout << (A ^ (1 << i)) << endl;
    return 0;
}