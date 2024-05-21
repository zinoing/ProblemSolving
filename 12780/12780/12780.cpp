// 12780.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	string str;
	string N;
	int ans = 0;

	cin >> str;
	cin >> N;

	int previous = 0;
	int index = 0;

	for (int i = 0; i < str.size(); i++) {
		index = 0;
		previous = i;
		while (i < str.size() && N[index] == str[i]) {
			++index;
			++i;
		}

		i = previous;
		if (index == N.size()) {
			++ans;	
		}
	}

	cout << ans;
}