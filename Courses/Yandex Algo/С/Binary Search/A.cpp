#include <iostream>
#include <vector>
#include <string>

using namespace std;

string bin_search(int n, const vector<int>& a){
    int l = 0, mid;
    int r = a.size() - 1;
    while (r - l > 1){
        mid = (l + r) / 2;
        if (a[mid] >= n)
            r = mid;
        else
            l = mid;
    }
    if (a[l] == n or a[r] == n)
        return "YES";
    return "NO";
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
        cout << bin_search(elem, a) << endl;
    }
    return 0;
}