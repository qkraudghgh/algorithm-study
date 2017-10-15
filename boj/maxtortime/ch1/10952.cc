#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    vector<int> v;

    do {
        cin >> A >> B;
        v.push_back(A+B);

    }
    while (!(A == 0 && B == 0));

    for (int n : v)
        if (n != 0) cout << n << '\n';
}
