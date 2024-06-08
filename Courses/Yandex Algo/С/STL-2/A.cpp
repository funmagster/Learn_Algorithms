#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    multiset<int> min_elem;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < k; i++){
        min_elem.insert(a[i]);
    }
    cout << *min_elem.begin() << endl;
    for (int i = 1; i <= n - k; i++){
        min_elem.insert(a[k + i - 1]);
        min_elem.erase(min_elem.find(a[i - 1]));
        cout << *min_elem.begin() << endl;
    }
    return 0;
}
