#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, elem, time = 0, pos = 0;
    pair<int, int> aqua;
    cin >> n;
    multiset<pair<int, int>> a;

    vector<int> initial_sizes(n);

    for (int i = 0; i < n; i++) {
        cin >> elem;
        initial_sizes[i] = elem;
        int first_birth_time = max(1, 1000 - elem);
        a.insert(make_pair(first_birth_time, i));
    }

    while (true) {
        aqua = *a.begin();
        a.erase(a.begin());

        int event_time = aqua.first;
        int aquarium_index = aqua.second;

        int travel_time = abs(aquarium_index - pos);

        if (time + travel_time <= event_time) {
            time = event_time;
            pos = aquarium_index;
            
            initial_sizes[aquarium_index] += 1;
            int next_event_time = time + max(1, 1000 - initial_sizes[aquarium_index]);
            a.insert(make_pair(next_event_time, aquarium_index));
        } else {
            cout << event_time << endl;
            return 0;
        }
    }
    return 0;
}
