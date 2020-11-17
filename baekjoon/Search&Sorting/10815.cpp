//C++98
#include <stdio.h>
#include <algorithm>

int BinarySearch(int N_arr[], int N, int target) {
	int st = 0;
	int end = N;
	while (st <= end) {
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
	int N_arr[500001], M_arr[500001];
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
		scanf("%d", &N_arr[n]);
	
	std::sort(N_arr, N_arr + N);

	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%d", &M_arr[m]);
		printf("%d ",BinarySearch(N_arr, N, M_arr[m]));
	}
	return 0;
}