//C++98
#include <iostream>
#include <string>
#include <deque>
std::deque<int> dq;
void push_front(int val) {
	dq.push_front(val);
}
void push_back(int val) {
	dq.push_back(val);
}
void pop_front() {
	if (dq.size() != 0) {
		std::cout << dq.front() << "\n";
		dq.pop_front();
	}
	else
		std::cout << "-1\n";
}
void pop_back() {
	if (dq.size() != 0) {
		std::cout << dq.back() << "\n";
		dq.pop_back();
	}
	else
		std::cout << "-1\n";
}
void size() {
	std::cout << dq.size() << "\n";
}
void empty() {
	if (dq.size() == 0)
		std::cout << "1\n";
	else
		std::cout << "0\n";
}
void front() {
	if (dq.size() != 0)
		std::cout << dq.front() << "\n";
	else
		std::cout << "-1\n";
}
void back() {
	if (dq.size() != 0)
		std::cout << dq.back() << "\n";
	else
		std::cout << "-1\n";
}
int main() {
	int N, val;
	std::string arg1;
	std::cin >> N;
	for (int n = 0; n < N; n++) {
		std::cin >> arg1;
		if (arg1 == "push_front") {
			std::cin >> val;
			push_front(val);
		}
		else if (arg1 == "push_back") {
			std::cin >> val;
			push_back(val);
		}
		else if (arg1 == "pop_front")
			pop_front();
		else if (arg1 == "pop_back")
			pop_back();
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