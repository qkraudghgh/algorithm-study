#include <iostream>
using namespace std;

int main() {
	int count; 
	cin >> count;

	int a;
	int b;

	for(int i = 0; i < count; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}
	
	return 0;
}
