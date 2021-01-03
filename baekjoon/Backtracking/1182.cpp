//C++98
#include <iostream>
int arr[21];
int cnt=0,N,S;
void func(int k, int sum)
{
	if (k == N)
		return;
	if (sum + arr[k] == S)
		cnt++;
	func(k + 1, sum);
	func(k + 1, sum + arr[k]);
}
int main()
{
	std::cin >> N >> S;
	for (int n = 0;n < N;n++)
	{
		std::cin >> arr[n];
	}
	func(0,0);
	std::cout << cnt;
	return 0;
}