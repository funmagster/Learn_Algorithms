#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Result {
    int a1_best, a2_best, a3_best, a4_best;
};


Result solve(const vector<int>& a1, const vector<int>& a2,
            const vector<int>& a3, const vector<int>& a4,
            int n1, int n2, int n3, int n4){
    Result result;
    int a1_best = a1[0], a2_best = a2[0], a3_best = a3[0], a4_best = a4[0];

    int max_elem, min_elem, dif, dif_curr;
    max_elem = max({a1[0], a2[0], a3[0], a4[0]});
    min_elem = min({a1[0], a2[0], a3[0], a4[0]});
    dif = max_elem - min_elem;

    int i1 = 0, i2 = 0, i3 = 0, i4 = 0;

    while (i1 < n1 and i2 < n2 and i3 < n3 and i4 < n4){

        min_elem = min({a1[i1], a2[i2], a3[i3], a4[i4]});
        max_elem = max({a1[i1], a2[i2], a3[i3], a4[i4]});
        
        dif_curr = max_elem - min_elem;

        if (dif_curr < dif){
            dif = dif_curr;
            dif = dif_curr;
            a1_best = a1[i1];
            a2_best = a2[i2];
            a3_best = a3[i3];
            a4_best = a4[i4];
        }
        if (dif == 0)
            break;
        
        if (min_elem == a1[i1])
            i1++;
        else if (min_elem == a2[i2])
            i2++;
        else if (min_elem == a3[i3])
            i3++;
        else
            i4++;
        

    }

    result.a1_best = a1_best;
    result.a2_best = a2_best;
    result.a3_best = a3_best;
    result.a4_best = a4_best;

    return result;
}

int main(){
    int n1, n2, n3, n4; 

    cin >> n1;
    vector<int> a1(n1);
    for (int i = 0; i < n1; i++){
        cin >> a1[i];
    }

    cin >> n2;
    vector<int> a2(n2);
    for (int i = 0; i < n2; i++){
        cin >> a2[i];
    }

    cin >> n3;
    vector<int> a3(n3);
    for (int i = 0; i < n3; i++){
        cin >> a3[i];
    }

    cin >> n4;
    vector<int> a4(n4);
    for (int i = 0; i < n4; i++){
        cin >> a4[i];
    }
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(a3.begin(), a3.end());
    sort(a4.begin(), a4.end());
    Result res = solve(a1, a2, a3, a4, n1, n2, n3, n4);
    cout << res.a1_best << ' ' << res.a2_best << ' ' << res.a3_best << ' ' << res.a4_best;
    return 0;
}