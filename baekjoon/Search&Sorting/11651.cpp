//C++98
#include <iostream>
#include <vector>
#include <algorithm>
bool y_greater(std::pair<int, int> v1, std::pair<int, int> v2) {
	if (v1.second == v2.second)
		return v1.first < v2.first;
	else
		return v1.second < v2.second;
}
int main(){
	int N,i,j;
	std::vector<std::pair<int, int> > v;
	std::vector<std::pair<int, int> >::iterator it;
	std::cin >> N;
	for (int n = 0;n < N;n++) {
		std::cin >> i >> j;
		v.push_back(std::make_pair(i, j));
	}
	std::sort(v.begin(), v.end(),y_grater);

	for (it = v.begin(); it != v.end();*it++) {
		std::cout << it->first << " " << it->second << "\n";
	}
	return 0;
}
