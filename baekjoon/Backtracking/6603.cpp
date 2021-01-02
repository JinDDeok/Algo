//C++98
#include <iostream>
int visit[50];
int arr[7];
void func(int loop, int k, int* S)
{
	if (loop == 6)
	{
		for (int lotto_cnt = 0; lotto_cnt < 6; lotto_cnt++)
		{
			std::cout << arr[lotto_cnt] << " ";
		}
		std::cout << "\n";
		return;
	}
	for (int k_num = 0; k_num < k; k_num++)
	{
		if (!visit[S[k_num]])
		{
			if (loop > 0 && arr[loop - 1] > S[k_num])
				continue;
			arr[loop] = S[k_num];
			visit[S[k_num]] = 1;
			func(loop + 1, k, S);
			visit[S[k_num]] = 0;
		}
	}
	
}
int main()
{
	int k, S[14];
	std::cin >> k;
	while (k != 0)
	{
		for (int k_cnt = 0; k_cnt < k; k_cnt++)
			std::cin >> S[k_cnt];

		func(0, k, S);
		std::cout << "\n";

		std::cin >> k;
	}
	return 0;
}