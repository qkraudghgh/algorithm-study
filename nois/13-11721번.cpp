#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int count;

	cin >> a;
	count = (a.length() / 10) + 1; // 몇 번째 줄까지 있는지 구함

	for (int i = 0; i < count; i++) {
		int start_index = i * 10; // 시작 인덱스 구함
		int substr_length = 10; // 자를 스트링 기본 10자리

		if(i == count - 1) { // 마지막 라인이면 스트링 자릿 수 직접 구함
			substr_length = a.length() % 10;
		}

		cout << a.substr(start_index, substr_length) << endl; // 잘라서 출력
	}

	return 0;
}
