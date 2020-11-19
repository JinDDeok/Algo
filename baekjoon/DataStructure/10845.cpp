//C++98
#include <iostream>
#include <string>
#include <queue>

std::queue<int> q;
void push(int val) {
	q.push(val);
}
void pop() {
	if (q.size() != 0) {
		std::cout << q.front() << "\n";
		q.pop();
	}
	else
		std::cout << "-1\n";
}
void size() {
	std::cout << q.size() << "\n";
}
void empty() {
	if (q.size() == 0)
		std::cout << "1\n";
	else
		std::cout << "0\n";
}
void front() {
	if(q.size() != 0)
		std::cout << q.front() << "\n";
	else
		std::cout << "-1\n";
}
void back() {
	if (q.size() != 0)
		std::cout << q.back() << "\n";
	else
		std::cout << "-1\n";

}
int main() {
	int N, val;
	std::string arg1;
	std::cin >> N;
	for (int n = 0; n < N; n++) {
		std::cin >> arg1;
		if (arg1 == "push") {
			std::cin >> val;
			push(val);
		}
		else if (arg1 == "pop")
			pop();
		else if (arg1 == "size")
			size();
		else if (arg1 == "empty")
			empty();
		else if (arg1 == "front")
			front();
		else if (arg1 == "back")
			back();
	}
	return 0;
}