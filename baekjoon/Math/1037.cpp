//C++98
#include <iostream>
#include <algorithm>
int main()
{
	int N, max_val, min_val;
	int arr[51];
	std::cin >> N;
	for (int n = 0;n < N;n++)
		std::cin >> arr[n];
	max_val = *std::max_element(arr, arr + N);
	min_val = *std::min_element(arr, arr + N);
	std::cout << max_val * min_val << "\n";
	return 0;
}