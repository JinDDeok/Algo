//C++98
#include <iostream>
#include <algorithm>
bool desc(int a, int b) {
	return a > b;
}
int main(){
	int N, answer = 0;
	int A_arr[51], B_arr[51];
	std::cin >> N;
	for (int n = 0; n < N; n++)
		std::cin >> A_arr[n];
	for (int n = 0; n < N; n++)
		std::cin >> B_arr[n];

	std::sort(A_arr, A_arr + N);
	std::sort(B_arr, B_arr + N, desc);

	for (int n = 0; n < N; n++)
		answer += A_arr[n] * B_arr[n];

	std::cout << answer;
	return 0;
}