//C++98
#include <iostream>
#include <string>
#include <stack>
std::stack<int> s;
void push(int val) {
	s.push(val);
}
void pop() {
	if (s.size() != 0) {
		std::cout << s.top() << "\n";
		s.pop();
	}
	else
		std::cout << "-1\n";
}
void size() {
	std::cout << s.size() << "\n";
}
void empty() {
	if (s.size() == 0)
		std::cout << "1\n";
	else
		std::cout << "0\n";
}
void top() {
	if (s.size() != 0)
		std::cout << s.top() << "\n";
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
		else if (arg1 == "top")
			top();
	}
	return 0;
}