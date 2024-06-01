#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++){
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] >  a[j + 1]){
                swap(a[j + 1], a[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}