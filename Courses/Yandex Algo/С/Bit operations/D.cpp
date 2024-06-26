#include <iostream>
#include <bitset>

using namespace std;

int solve(int a){
    return 1 << bitset<32>(a).count();
}
int main(){
    int t, a;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}