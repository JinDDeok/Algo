//C++98
#include <iostream>
int num;
int cnt = 0;
void func(int k, int val)
{
	if (k > num)
		return;
	if (val == num)
		cnt++;
	func(k + 1, val + 1);
	func(k + 1, val + 2);
	func(k + 1, val + 3);
}
int main()
{
	int T;
	std::cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		std::cin >> num;
		func(0, 0);
		std::cout << cnt << "\n";
		cnt = 0;
	}
	return 0;
}