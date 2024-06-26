#include <iostream>
#include <bitset>
using namespace std;

int main(){
    unsigned int A, n;
    cin >> A >> n;
    cout << (A & ((1 << n) - 1)) << endl;
    return 0;
}