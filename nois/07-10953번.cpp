#include <iostream>
using namespace std;

int main() {
	int count;
	cin >> count;

	int a, b;
	char seperator;

	for(int i = 0; i < count; i++) {
		cin >> a >> seperator >> b;
		cout << a + b << endl;
	}

	return 0;
}
