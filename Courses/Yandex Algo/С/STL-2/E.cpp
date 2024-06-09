#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

string encodeToString(const string &word) {
    string result;
    for (char symbol : word) {
        if (symbol == 'a' || symbol == 'b' || symbol == 'c')
            result += '2';
        else if (symbol == 'd' || symbol == 'e' || symbol == 'f')
            result += '3';
        else if (symbol == 'g' || symbol == 'h' || symbol == 'i')
            result += '4';
        else if (symbol == 'j' || symbol == 'k' || symbol == 'l')
            result += '5';
        else if (symbol == 'm' || symbol == 'n' || symbol == 'o')
            result += '6';
        else if (symbol == 'p' || symbol == 'q' || symbol == 'r' || symbol == 's')
            result += '7';
        else if (symbol == 't' || symbol == 'u' || symbol == 'v')
            result += '8';
        else if (symbol == 'w' || symbol == 'x' || symbol == 'y' || symbol == 'z')
            result += '9';
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    unordered_map<string, vector<string>> prefix_to_words;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        string encoded_word = encodeToString(word);
        for (int j = 1; j <= encoded_word.length(); ++j) {
            string prefix = encoded_word.substr(0, j);
            prefix_to_words[prefix].push_back(word);
        }
    }

    cin >> m;
    vector<int> inputs(m);
    for (int i = 0; i < m; ++i) {
        cin >> inputs[i];
    }

    string result = "";
    string current_sequence = "";
    string last_valid_word = "";

    for (int i = 0; i < m; ++i) {
        int num = inputs[i];

        if (num == 1) {
            if (!last_valid_word.empty()) {
                result += last_valid_word + " ";
                last_valid_word.clear();
            }
            current_sequence.clear();
        } else {
            current_sequence += to_string(num);

            if (prefix_to_words.find(current_sequence) != prefix_to_words.end()) {
                const vector<string>& words = prefix_to_words[current_sequence];
                if (words.size() == 1) {
                    last_valid_word = words[0];
                    result += last_valid_word + " ";
                    current_sequence.clear();
                    last_valid_word.clear();
                } else {
                    last_valid_word = words[0];
                }
            } else {
                current_sequence.clear();
                last_valid_word.clear();
            }
        }
    }

    cout << result << '\n';

    return 0;
}