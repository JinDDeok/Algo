//C++98
#include <iostream>
#include <queue>
#include <vector>
int main()
{
	std::queue<int> q;
	std::vector<int> answer;
	std::vector<int>::iterator it;
	int N, K;
    int count = 0;
	int n = 1;
    
	std::cin >> N >> K;
	do
	{
		if (n <= N)
		{
			count++;
			if (count == K)
			{
				answer.push_back(n);
				count = 0;
			}
			else
				q.push(n);
			n++;
		}
		else
		{
			count++;
			if (count == K)
			{
				answer.push_back(q.front());
				count = 0;
			}
			else
				q.push(q.front());
			q.pop();
		}
	} while (n<=N || !q.empty());

	std::cout << "<";
	for (it = answer.begin(); it != answer.end() - 1; it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << answer[answer.size()-1] << ">";
	return 0;
}