#include <iostream>
#include <string>
using namespace std;

int main() {
	int count;
	int total = 0;
	string a;
	
	cin >> count;
	cin >> a;

	for (int i = 0; i < count; i++) {
		total += (a.at(i) - '0');
	}

	cout << total << endl;

	return 0;
}
