#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, long long> lengthMemo;


long long lengthOfSequence(int k) {
    if (lengthMemo.find(k) != lengthMemo.end()) {
        return lengthMemo[k];
    }

    if (k == 0) {
        lengthMemo[k] = 3;
    } else {
        lengthMemo[k] = 2 * lengthOfSequence(k - 1) + k + 3;
    }

    return lengthMemo[k];
}

char findCharAtPosition(long long n, int k) {
    if (k == 0) {
        return n == 1 ? 'm' : 'o';
    }

    long long len_k_minus_1 = lengthOfSequence(k - 1);
    long long middle_part_length = k + 3;

    if (n <= len_k_minus_1) {
        // left side
        return findCharAtPosition(n, k - 1);
    } else if (n > len_k_minus_1 && n <= len_k_minus_1 + middle_part_length) {
        // middle side
        if (n == len_k_minus_1 + 1) {
            return 'm';
        } else {
            return 'o';
        }
    } else {
        // right side
        return findCharAtPosition(n - len_k_minus_1 - middle_part_length, k - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    int k = 0;
    while (lengthOfSequence(k) < n) {
        k++;
    }

    cout << findCharAtPosition(n, k) << endl;

    return 0;
}
