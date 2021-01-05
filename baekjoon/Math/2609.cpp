//C++98
#include <iostream>
int main()
{
	int num1, num2, mod, lcm;
	std::cin >> num1 >> num2;
	lcm = num1 * num2;
	do
	{
		mod = num1 % num2;
		num1 = num2;
		num2 = mod;
	} while (mod != 0);

	std::cout << num1 << "\n";
	std::cout << lcm / num1 << "\n";
	return 0;
}