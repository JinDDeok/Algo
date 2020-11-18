//C++98
#include <stdio.h>
#include <algorithm>
int Binarysearch(int N_arr[], int N, int target) {
	int st = 0;
	int end = N;
	while (st<=end) {
		int mid = (st + end) / 2;
		if (N_arr[mid] == target)
			return 1;
		else if (N_arr[mid] < target)
			st = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

int main() {
	int N, M;
	int N_arr[100001], M_arr[100001];

	scanf("%d",&N);
	for (int i = 0; i < N; i++)
		scanf("%d",&N_arr[i]);
	std::sort(N_arr, N_arr + N);
	scanf("%d",&M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &M_arr[i]);
		printf("%d\n",Binarysearch(N_arr, N, M_arr[i]));
	}
	return 0;
}