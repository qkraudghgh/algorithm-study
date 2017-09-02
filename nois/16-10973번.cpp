#include <iostream>
#include <string>
using namespace std;

int main() {
	int length;
	int number;

	cin >> length;
	int* permutation = (int*) malloc(sizeof(int) * length);

	// 순열 입력
	for(int i = 0; i < length; i ++) {
		cin >> number;
		permutation[i] = number;
	}

	// 마지막 인덱스에 해당하는 i를 생성.
	int i = length - 1;

	/* 마지막 인덱스로부터 인접한 두 수가 가장 먼저 > 를 만족하는 인덱스 i 를 구함.
	   예를 들어 35421이면 두 수 2, 1이 가장 먼저 > 를 만족하므로 i = 4가 됨
	 */
	while (i > 0 && permutation[i - 1] <= permutation[i]) {
		i -= 1;
	}

	cout << i << endl;
	// 만약 마지막 순열이면 여기서 -1이 리턴됨
	if(i <= 0) {
		cout << -1 << endl;
		return -1;
	}

	// 마지막 index에 해당하는 j를 생성
	int j = length - 1;

	/* 마지막 인덱스로부터 i - 1 번째 값과 비교하였을 때, 가장 먼저 arr[j] < arr[i - 1]
	   를 만족하는 인덱스 j를 구함. 앞의 35421로 예를 들면, i - 1 = 3. 즉, 3번 인덱스의
	   2과 4번째 인덱스의 1이 1 < 2를 처음으로 < 를 만족함. 따라서 j는 4임.

	   그리고 이 두 수를 바꿈. 35421 -> 35412
	 */
	while(permutation[j] >= permutation[i - 1]) j -= 1;
	swap(permutation[i-1], permutation[j]);

	// j를 다시 마지막 index로 변경
	j = length - 1;

	/* i가 j보다 같거나 커질 때까지 서로 스왑.
		여기선 이미 같으므로 35412가 결과값.
	 */
	while(i < j) {
		swap(permutation[i], permutation[j]);
		i += 1; j -= 1;
	}

	// 다음 순열 출력
	for(int i = 0; i < length; i++) {
		cout << permutation[i];
		if(i != length - 1) cout << " ";
		else cout << endl;
	}

	return 0;
}

