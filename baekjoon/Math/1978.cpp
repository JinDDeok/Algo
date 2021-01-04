//C++98
#include <iostream>
#include <math.h>
bool isprime(int prime)
{
	if (prime == 1)
		return false;
	for (int i = 2; i <= sqrt(prime); i++)
	{
		if (prime % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int N, number, cnt = 0;
	std::cin >> N;
	for (int n = 0;n < N;n++)
	{
		std::cin >> number;
		if (isprime(number))
			cnt++;
	}
	std::cout << cnt << "\n";
	return 0;
}