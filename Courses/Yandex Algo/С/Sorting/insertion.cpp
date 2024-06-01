#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, j, elem;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        elem = a[i];
        j = i - 1;
        while (j >= 0 and a[j] > elem){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = elem;
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
