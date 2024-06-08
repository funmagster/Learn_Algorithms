#include <iostream>
#include <vector>
using namespace std;


int lower_bin_search(int elem, const vector<int>& a) {
    int l = 0, r = a.size() - 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (a[mid] < elem)
            l = mid + 1;
        else
            r = mid;
    }
    if (a[l] == elem)
        return l;
    return -1;
}


int upper_bin_search(int elem, const vector<int>& a) {
    int l = 0, r = a.size() - 1, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (a[mid] > elem)
            r = mid - 1;
        else
            l = mid;
    }
    if (a[l] == elem)
        return l;
    return -1;
}


int count_elem(int elem, const vector<int>&a){
    int l = lower_bin_search(elem, a);
    if (l == -1)
        return 0;
    int r = upper_bin_search(elem, a);
    return r - l + 1;
}

int main(){
    int n, k, elem;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < k; i++){
        cin >> elem;
        cout << count_elem(elem, a) << endl;
    }
    return 0;
}