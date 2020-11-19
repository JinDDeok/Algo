//C++98
#include <iostream>
#include <string>
#include <list>
int main(){
	std::string str;
	char command1, command2;
	std::list<char> l;
	std::list<char>::iterator iter = l.end();
	int M;
	std::cin >> str;
	std::cin >> M;

	for (int i = 0; i < str.length(); i++) 
		l.push_back(str[i]);

	for (int m = 0; m < M; m++) {
		std::cin >> command1;
		if (command1 == 'P') {
			std::cin >> command2;
			l.insert(iter,command2);
		}
		else if (command1 == 'L') {
			if(iter != l.begin())
				--iter;
		}
		else if (command1 == 'D') {
			if (iter != l.end())
				++iter;
		}
		else if (command1 == 'B') {
			if (iter != l.begin()) {
				--iter;
				iter = l.erase(iter);
			}
		}
	}
	for (iter = l.begin(); iter != l.end(); iter++) {
		std::cout << *iter;
	}
	return 0;
}