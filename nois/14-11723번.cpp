#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int set = 0; // int는 4Bytes => 32비트. 비트의 값에 따라 set에서 있는지 없는지를 판단.
	int length, number; 
	char* method = (char*) malloc(sizeof(char *) * 10);

	scanf("%d", &length);
	while (length--) {
		scanf("%s", method);

		if (strcmp(method, "add") == 0) {
			scanf("%d", &number); number--;
			/* number 3에 대해서 추가를 하는 경우, 32 - 3번째 비트가 1이 되면 됨.
			   때문에 set과 (000..)00000100을 or 연산하면 됨.
			*/
			set = (set | (1 << number));
		}
		else if (strcmp(method, "remove") == 0) {
			scanf("%d", &number); number--;
			/* number 3에 대해서 제거 하는 경우, 32 - 3번째 비트가 0이 되면 됨.
			   때문에 set과 11111011을 and 연산하면, 다른 비트는 원래 값을 유지하면서 32 - 3
			   번째 비트만 0으로 만들게 됨.
			*/
			set = (set & ~(1 << number));
		}
		else if (strcmp(method, "check") == 0) {
			scanf("%d", &number); number--;

			/* number 3에 대해서 체크를 하는 경우, 32 - 3번째 비트가 1인지 0인지 확인하여야함.
			   때문에 set과 00000100을 and 연산하여 이 값이 0인 경우. 없다고 판단 가능.
			*/
			int exist = (set & (1 << number));
			if (exist) { printf("%s","1\n"); }
			else { printf("%s", "0\n"); }
		}
		else if (strcmp(method, "toggle") == 0) {
			/* number 3에 대해서 체크를 하는 경우, 32 - 3번째 비트를 0 <-> 1 바꾸면 됨.
			   때문에 set과 00000100을 XOR 연산하여 값이 같으면(있으면) 0, 다르면(없으면) 1이 됨.
			*/
			scanf("%d", &number); number--;
			set = (set ^ (1 << number));
		}
		else if (strcmp(method, "all") == 0) {
			set = set | 0xFFFFFF;
		}
		else if (strcmp(method, "empty") == 0) {
			set = 0;
		}
	}
}


