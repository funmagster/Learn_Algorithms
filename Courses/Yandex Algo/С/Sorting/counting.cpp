#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, elem;
    cin >> n;

    vector<int> a(101, 0);
    for (int i = 0; i < n; i++){
        cin >> elem;
        a[elem]++;
    }
    for (int i = 0; i < 101; i++){
        while (a[i] > 0){
            cout << i << ' ';
            a[i]--;
        }
    }
}
