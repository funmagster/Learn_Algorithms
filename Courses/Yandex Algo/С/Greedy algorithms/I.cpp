// Passes 18 tests out of 22

#include <iostream>

using namespace std;

int main() {
    long long cost, p, need;
    cin >> cost >> p >> need;

    long long time = cost, cook = cost, prod = 1, to_complete, to_buy_and_complete, to_buy;
    if (cost >= need){
        cout << need;
        return 0;
    }
    while (cook < need) {
        to_complete = (need - cook + (prod - 1)) / prod;
        to_buy_and_complete = (need - cook + cost + (prod + p - 1)) / (prod + p);
        if (to_complete <= to_buy_and_complete){
            time += to_complete;
            break;
        }
        else{
            cook -= cost;
            prod += p;
            to_buy = (cost - cook + (prod - 1)) / prod;
            to_complete = (need - cook + (prod - 1)) / prod;
            if (to_complete <= to_buy){
                time += to_complete;
                break;
            }
            cook += prod*to_buy;
            time += to_buy;
        }
        
    }

    cout << time << endl;

    return 0;
}
