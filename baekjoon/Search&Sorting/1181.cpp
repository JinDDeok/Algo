//C++98
#include <iostream>
#include <string>
#include <algorithm>
bool str_length_grater(std::string a, std::string b) {
	return a.length() < b.length();
}
int main(){
	int N;
	std::string x[20001];
	std::cin >> N;
	for (int n = 0; n < N; n++) {
		std::cin >> x[n];
	}
	std::sort(x, x + N);
	std::stable_sort(x, x + N, str_length_grater);
	for (int n = 1; n < N+1; n++) {
		if(x[n] != x[n-1])
			std::cout << x[n-1] << "\n";
	}
	return 0;
}