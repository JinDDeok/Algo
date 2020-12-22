//C++98
#include <stack>
#include <string>
#include <iostream>
#include <vector>
bool valid(std::string chk)
{
	std::stack<std::string> s;
	for (int i = 0; i < chk.size(); i++)
	{
		if (chk[i] == '(')
		{
			s.push("(");
		}
		else if (chk[i] == ')')
		{
			if (s.size() == 0)
				return false;
			s.pop();
		}
	}
	return s.empty();
}
int main()
{
	std::string str;
	int T;
	std::vector<std::string> v;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		std::cin >> str;
		if (valid(str))
			v.push_back("YES");
		else
			v.push_back("NO");
	}

	for (int t = 0;t < T;t++)
	{
		std::cout << v[t] << "\n";
	}

	return 0;
}