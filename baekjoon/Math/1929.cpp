//C++98
#include <iostream>
int main()
{
	int M, N, i, j;
	int arr[1000001] = { 0 };
	std::cin >> M >> N;
	for (i = 2; i <= N; i++)
		arr[i] = i;

	for (i = 2; i <= N; i++)
	{
		for (j = 2; i * j <= N; j++)
		{
			if (arr[i * j] != 0)
				arr[i*j] = 0;
		}
	}

	for (i = M; i <= N; i++)
	{
		if(arr[i] != 0)
			std::cout << arr[i] << "\n";
	}
	return 0;
}