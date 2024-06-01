#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<long long> a;
    long long a_i;

    while (cin >> a_i && a_i != 0) {
        a.push_back(a_i);
    }

    cout << 0 << ' ';
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i] << ' ';
    }

    return 0;
}
