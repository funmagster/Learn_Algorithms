#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main(){
    string seq;
    string elem;
    getline(cin, seq);
    istringstream iss(seq);
    int a, b;
    vector<int> stack;

    while (iss >> elem){
        if (elem == "+"){
            a = stack.back();
            stack.pop_back();

            b = stack.back();
            stack.pop_back();

            stack.push_back(a + b);
        }
        else if (elem == "-"){
            a = stack.back();
            stack.pop_back();

            b = stack.back();
            stack.pop_back();

            stack.push_back(b - a);
        }
        else if (elem == "*"){
            a = stack.back();
            stack.pop_back();

            b = stack.back();
            stack.pop_back();

            stack.push_back(a * b);
        }
        else{
            stack.push_back(stoi(elem));
        }
    }
    cout << stack[0];
    return 0;
}