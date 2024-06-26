#include <iostream>
#include <bitset>
using namespace std;

int main(){
    unsigned int A;
    cin >> A;
    bitset<8> bits(A);
    cout << bits << endl;
    return 0;
}