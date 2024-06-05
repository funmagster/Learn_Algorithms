#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    long long cnt_pasp = 0;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; ++i) {
        long long population;
        cin >> population;
        pq.push(population);
    }
    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        
        long long sums = first + second;
        cnt_pasp += sums;
        
        pq.push(sums);
    }
    cout << cnt_pasp;
    return 0;
}