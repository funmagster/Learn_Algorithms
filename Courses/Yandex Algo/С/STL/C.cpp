/*
debug needed
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> left_min(n, -1);
    vector<int> right_min(n, -1);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    vector<int> st;
    for (int i = 1; i < n; i++){
        while (!st.empty() and h[st.back()] >= h[i])
            st.pop_back();
        if (!st.empty())
            left_min[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n - 2; i >- 0; i--){
        while (!st.empty() and h[st.back()] >= h[i])
            st.pop_back();
        if (!st.empty())
            right_min[i] = st.back();
        st.push_back(i);
    }
    long long max_square = -1;
    long long square;
    int length;
    int l_best, r_best;
    for (int i = 0; i < n; i++){
        length = 1;
        if (left_min[i] != -1)
            length += i - left_min[i];
        if (right_min[i] != -1)
            length += i - right_min[i];
        square = length * h[i];
        if (square > max_square){
            max_square = square;
            l_best = left_min[i];
            r_best = right_min[i];
        }
    }
    cout << max_square; // << ' ' << l_best << ' ' << r_best;
    return 0;
}
