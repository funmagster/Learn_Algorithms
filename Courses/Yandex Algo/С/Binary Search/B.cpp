#include <iostream>
#include <vector>

using namespace std;

int approximate_binary_search(long long elem, const vector<long long>& a){
    int l = 0, r = a.size() - 1;
    int mid;
    while (r - l > 1){
        mid = (l + r) / 2;
        if (a[mid] > elem)
            r = mid;
        else
            l = mid;
    }
    if (abs(elem - a[l]) <= abs(a[r] - elem))
        return a[l];
    return a[r];
}

int main(){
    int n, k;
    long long elem;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < k; i++){
        cin >> elem;
        cout << approximate_binary_search(elem, a) << endl;
    }
    return 0;
}