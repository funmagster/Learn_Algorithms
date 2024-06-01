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
        int min_elem_ind = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min_elem_ind]){
                min_elem_ind = j;
            }
        }
        swap(a[i], a[min_elem_ind]);
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

}