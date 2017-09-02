#include <iostream>
#include <string>
using namespace std;

int next_permutation(int* permutation, int length);

int main() {
	int length;

	cin >> length;
	int* permutation = (int*) malloc(sizeof(int) * length);

	for(int i = 0; i < length; i++) {
		permutation[i] = i+1;
	}

	while(next_permutation(permutation, length) != -1) {}

	return 0;
}

int next_permutation(int* permutation, int length) {
	for(int i = 0; i < length; i++) {
		cout << permutation[i];
		if(i != length - 1) cout << " ";
		else cout << endl;
	}
	
	int i = length - 1;
	while (i > 0 && permutation[i - 1] >= permutation[i]) {
		i -= 1;
	}

	if(i <= 0) {
		return -1;
	}
	int j = length - 1;

	while(permutation[j] <= permutation[i - 1]) j -= 1;
	swap(permutation[i-1], permutation[j]);
	j = length - 1;

	while(i < j) {
		swap(permutation[i], permutation[j]);
		i += 1; j -= 1;
	}
	return 0;
}
