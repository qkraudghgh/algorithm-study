#include <iostream>
#include <string>
using namespace std;

int next_permutation(int* permutation, int length);

int main() {
	int length;
	int type;

	cin >> length;
	cin >> type;

	int* permutation = (int*) malloc(sizeof(int) * length);

	if(type == 1) { 
		int order;
		cin >> order;
		order -= 1;	

		for(int i = 0; i < length; i++) {
			permutation[i] = i + 1; // 기본값 입력. length가 4이면 1234
		}

		while(order--) {
			next_permutation(permutation, length); // order 번째 순열 찾기
		}

		for(int i = 0; i < length; i++) { // 구한 순열 출력
			cout << permutation[i];
			if(i != length - 1) cout << " ";
			else cout << endl;
		}
	} else if(type == 2) {
		int count = 1;
		int number;

		for(int i = 0; i < length; i++) {
			cin >> number;
			permutation[i] = number;

			count *= (i + 1); // n!을 기본값으로 줌
		}

		// 순열 찾으면서 count를 내려서 몇 번쨰인지 찾음.
		while(next_permutation(permutation, length) != -1) {
			count--;
		}

		cout << count << endl;
	}

	free(permutation);
	return 0;
}

int next_permutation(int* permutation, int length) {
	// 마지막 인덱스에 해당하는 i를 생성.
	int i = length - 1;

	/* 마지막 인덱스로부터 인접한 두 수가 가장 먼저 < 를 만족하는 인덱스 i 를 구함.
	   예를 들어 35421이면 두 수가 3, 5가 가장 먼저 < 를 만족하므로 i = 1가 됨
	 */
	while (i > 0 && permutation[i - 1] >= permutation[i]) {
		i -= 1;
	}

	// 만약 마지막 순열이면 여기서 -1이 리턴됨
	if(i <= 0) {
		return -1;
	}

	// 마지막 index에 해당하는 j를 생성
	int j = length - 1;

	/* 마지막 인덱스로부터 i - 1 번째 값과 비교하였을 때, 가장 먼저 arr[j] > arr[i - 1]
	   를 만족하는 인덱스 j를 구함. 앞의 35421로 예를 들면, i - 1 = 0. 즉, 0번 인덱스의
	   3과 2번째 인덱스의 4가 4 > 3 이므로 처음으로 > 를 만족함. 따라서 j는 2임.

	   그리고 이 두 수를 바꿈. 35421 -> 45321
	 */
	while(permutation[j] <= permutation[i - 1]) j -= 1;
	swap(permutation[i-1], permutation[j]);

	// j를 다시 마지막 index로 변경
	j = length - 1;

	/* i가 j보다 같거나 커질 때까지 서로 스왑.
		45321 -> 41325 -> 41235
	 */
	while(i < j) {
		swap(permutation[i], permutation[j]);
		i += 1; j -= 1;
	}

	return 0;
}
