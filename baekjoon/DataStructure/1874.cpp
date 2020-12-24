//C++98
#include <iostream>
#include <stack>
#include <vector>
bool valid(int* arr,int N)
{
	std::vector<char> answer;
	std::vector<char>::iterator it;
	std::stack<int> s;
	int target = 0;
	int num = 1;
	while (target<N)
	{
		if (arr[target] >= num)
		{
			s.push(num);
			answer.push_back('+');
			num++;
		}
		else if (arr[target] == s.top())
		{
			s.pop();
			answer.push_back('-');
			target++;
		}
		else
			return false;
	}
	for (it = answer.begin(); it != answer.end(); it++)
	{
		std::cout << *it << "\n";
	}
	return true;
}
int main()
{
	int N;
	int arr[100001];
	std::cin >> N;
	for (int n = 0;n < N;n++)
		std::cin >> arr[n];

	if (!valid(arr,N))
	{
		std::cout << "NO";
	}
	return 0;
}