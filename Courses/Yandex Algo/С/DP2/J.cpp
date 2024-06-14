#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, ind;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);
    vector<int> prev(n, -1);
    vector<int> pos(n + 1, 0);
    int length = 0;

    for (int i = 0; i < n; i++) {
        int l = 1, r = length;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[pos[mid]] < a[i])
                l = mid + 1;
            else
                r = mid - 1;
        }

        int newLength = l;
        prev[i] = pos[newLength - 1];
        pos[newLength] = i;

        if (newLength > length)
            length = newLength;
    }

    vector<int> lis(length);
    int k = pos[length];
    for (int i = length - 1; i >= 0; i--) {
        lis[i] = a[k];
        k = prev[k];
    }

    cout << length << endl;
    for (int i = 0; i < length; i++) {
        cout << lis[i] << " ";
    }

    return 0;
}