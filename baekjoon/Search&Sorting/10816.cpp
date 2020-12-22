//C++98
#include <stdio.h>
#include <algorithm>
int main()
{
	int N, M;
	int N_arr[500001], M_arr[500001];
	int answer[500001];
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
	{
		scanf("%d", &N_arr[n]);
	}
	scanf("%d", &M);
	for (int m = 0; m < M; m++)
	{
		scanf("%d", &M_arr[m]);
	}
	std::sort(N_arr, N_arr + N);

	for (int m = 0;m < M;m++)
	{
		int low = std::lower_bound(N_arr, N_arr + N, M_arr[m]) - N_arr;
		int upp = std::upper_bound(N_arr, N_arr + N, M_arr[m]) - N_arr;
		answer[m] = upp - low;
	}
	for (int m = 0; m < M; m++)
	{
		printf("%d ", answer[m]);
	}

	return 0;
}