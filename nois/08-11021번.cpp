#include <iostream>
using namespace std;

int main() {
	int count;
	cin >> count;

	int a, b;

	for(int i = 0; i < count; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a + b << endl;
	}

	return 0;
}
