#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<long long>& w, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<long long> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = w[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = w[mid + 1 + i];

    int i = 0, j = 0, k = l;
    long long inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            w[k] = L[i];
            i++;
        } else {
            w[k] = R[j];
            inv_count += (n1 - i);
            j++;
        }
        k++;
    }

    while (i < n1) {
        w[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        w[k] = R[j];
        j++;
        k++;
    }

    return inv_count;
}

long long count_inv(vector<long long>& w, int l, int r) {
    if (r <= l)
        return 0;

    int mid = l + (r - l) / 2;

    long long l_inv = count_inv(w, l, mid);
    long long r_inv = count_inv(w, mid + 1, r);
    long long split_inv = merge(w, l, mid, r);

    return l_inv + r_inv + split_inv;
}

int main() {
    int n, l, w_i;
    cin >> n >> l;
    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w_i;
        w[i] = static_cast<long long>(w_i) * l + i;
    }
    cout << count_inv(w, 0, n - 1);
    return 0;
}
