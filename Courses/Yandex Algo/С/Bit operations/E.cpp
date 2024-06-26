#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int x, y, c;
    cin >> x >> y;
    cout << (x^y) << endl;
    cin >> x >> c;
    cout << (x^c);
    return 0;
}