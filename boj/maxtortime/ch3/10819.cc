#include <iostream>
#include <limits>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int max = numeric_limits<int>().min();
    vector<int> A;

    cin >> N;
    
    for (int i = 0; i < N ; i++) {
        int input;
        cin >> input;
        A.push_back(input);
    }

    sort(A.begin(), A.end());

    do {
        int t_max = 0;

        for (int i = 2 ; i <= N ; i++)
            t_max += abs(A[i-2]-A[i-1]);

        if (t_max > max) max = t_max;
    } while(next_permutation(A.begin(), A.end()));

    cout << max << '\n';

    return 0;
}
