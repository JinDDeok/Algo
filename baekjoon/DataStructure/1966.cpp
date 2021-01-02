//C++98
#include <iostream>
#include <deque>
#include <queue>
int result(int N, int M, std::deque<int> doc_priority, std::priority_queue<int> pri_queue, int* doc_find)
{
	int print = 1;
	int doc_val = M;
	while (!doc_priority.empty())
	{
		if (doc_priority.front() == pri_queue.top())
		{
			if (doc_val == 0)
				return print;
			doc_priority.pop_front();
			pri_queue.pop();
			print++;
		}
		else
		{
			doc_priority.push_back(doc_priority.front());
			doc_priority.pop_front();
		}
		doc_find[doc_val] = 0;
		if (doc_val <= 0)
		{
			doc_val = doc_priority.size() - 1;
			doc_find[doc_val] = 1;
		}
		else
			doc_find[--doc_val] = 1;
	}
}
int main()
{
	int T;
	int N, M, priority;
	std::cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		std::deque<int> doc_priority;
		std::priority_queue<int> pri_queue;
		int doc_find[101] = { 0 };
		std::cin >> N >> M;
		for (int doc_cnt = 0; doc_cnt < N; doc_cnt++)
		{
			std::cin >> priority;
			doc_priority.push_back(priority);
			pri_queue.push(priority);
		}
		doc_find[M] = 1;
		std::cout << result(N, M, doc_priority, pri_queue, doc_find) << "\n";
	}
	return 0;
}