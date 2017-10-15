#include <iostream>
#include <limits>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int cost = numeric_limits<int>().max();

    cin >> N;

    int** M = new int* [N];
    vector<int> A;
    
    for (int i = 0 ; i < N ; i++) {
        A.push_back(i);
        M[i] = new int[N];

        for (int j = 0 ; j < N ; j++) {
            cin >> M[i][j];
        }
    }

    sort(begin(A), end(A));

    do {
        int temp = 0;
        int c = 0;
        int i = 1;

        for (i = 1 ; i <= N ; i++) {
            if (i == N)
                c = M[A[i-1]][A[0]];
            else
                c = M[A[i-1]][A[i]];

            if (c == 0)
                break;
            else
                temp += c;
        }

        if (i != N+1)
            continue;

        if (temp < cost) cost = temp;
            
    } while(next_permutation(begin(A), end(A)));

    cout << cost << '\n';

    delete[] M;

    return 0;
}
