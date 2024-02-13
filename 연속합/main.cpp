#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> narray;
vector<int> sum_array(100000, -1001);
int main() {
	int n, num, i, compare;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num;
		narray.push_back(num);
	}

	for (i = n-1; i >= 0; i--) {
		if (i == n - 1) {  //끝 수이면 그냥 저장
			sum_array[i] = narray[i];
		}
		else {
			compare = sum_array[i + 1] + narray[i];   //더해줄지 말지 여부결정
			if ( compare > narray[i]) {
				sum_array[i] = compare;
			}
			else {
				sum_array[i] = narray[i];
			}
		}
	}

	auto iter = max_element(sum_array.begin(), sum_array.end());
	cout << *iter;
}