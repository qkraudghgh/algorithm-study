#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    vector<int> plus;
    
    while (cin >> A >> B) plus.push_back(A+B);

    for (int n : plus)
        cout << n << '\n';
}
