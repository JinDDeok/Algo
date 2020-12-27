//C++98
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
std::string result(std::string p, int n, std::string array_num)
{
	std::deque<std::string> dq;
	std::string num;
	for (int i = 1; array_num[i] != '\0'; i++)
	{
		if (array_num[i] == ',' || array_num[i] == ']')
		{
			dq.push_back(num);
			num = "";
		}
		else
			num += array_num[i];
	}
	int head = 0, tail = n-1;
	std::string st = "left";
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == 'R')
		{
			if (st == "left")
				st = "right";
			else  if (st == "right")
				st = "left";
		}
		else if (p[i] == 'D')
		{
			if (head > tail)
				return "error";
			if (st == "left")
			{
				dq.pop_front();
				head++;
			}
			else if (st == "right")
			{
				dq.pop_back();
				tail--;
			}
		}
	}
	std::string ans = "[";
	while (!dq.empty())
	{
		if (st == "left")
		{
			ans += dq.front();
			dq.pop_front();
		}
		else if (st == "right")
		{
			ans += dq.back();
			dq.pop_back();
		}
		if (!dq.empty())
		{
			ans += ",";
		}
	}
	ans += "]";
	return ans;
}
int main()
{
	int T;
	std::vector<std::string> answer;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++)
	{
		std::string p;
		int n;
		std::string array_num;
		std::cin >> p >> n >> array_num;
		answer.push_back(result(p, n, array_num));
	}
	for (int i = 0; i < T; i++)
	{
		std::cout << answer[i] << "\n";
	}
	return 0;
}