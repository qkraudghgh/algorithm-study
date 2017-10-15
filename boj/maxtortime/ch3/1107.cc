#include <iostream>

using namespace std;

int possible(int c);
bool broken[10] = {false, };

int main() {
    int N, M;

    cin >> N;
    cin >> M;

    int R = abs(N-100);

    for (int i = 0 ; i < M ; i++) {
        int b;
        cin >> b;

        broken[b] = true;
    }

    for (int i = 0 ; i < 1000000 ; i++) {
        int is_broken = possible(i);

        if (is_broken) {
            int temp = abs(i-N) + is_broken;

            if (temp < R) R = temp;
        }
    }

    cout << R << '\n';
}

int possible(int c) {
    if (c == 0)
        return broken[0] ? 0 : 1;

    int length = 0;

    while (c != 0) {
        if (broken[c % 10])
            return 0;

        c /= 10;
        length++;
    }

    return length;
}
