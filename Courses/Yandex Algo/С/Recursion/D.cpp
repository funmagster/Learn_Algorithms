#include <iostream>
#include <string>

using namespace std;

void generated(int n, string& s, string& alphabet, int start) {
    if (!s.empty()) {
        cout << s << endl;
    }
    for(int i = start; i < n; i++) {
        s.push_back(alphabet[i]);
        generated(n, s, alphabet, i + 1);
        s.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s, alphabet;
    cin >> n;
    for (char ch = 'a'; ch < 'a' + n; ++ch) {
        alphabet.push_back(ch);
    }
    generated(n, s, alphabet, 0);
    return 0;
}
