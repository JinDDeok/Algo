//C++98
#include <stdio.h>
#include <algorithm>
int main() {
	int N,input;
	int N_arr[10001] = { 0 };
	scanf("%d",&N);
	for (int n = 0; n < N; n++) {
		scanf("%d",&input);
		N_arr[input] += 1;
	}
	for (int n = 0; n < 10001; n++) {
		for(int m = 0; m < N_arr[n]; m++)
				printf("%d\n",n);
	}
	return 0;
}