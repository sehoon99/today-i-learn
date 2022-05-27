#include<iostream>
#include<algorithm>
using namespace std;
int n, a, arr1[1001] = { 0, }, dp1[1001], maxl1 = 0, arr2[1001] = { 0, }, dp2[1001], maxl2 = 0, maxl3 = 0;
bool visit[1001] = { false, };
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		arr1[i] = a;
		arr2[n - i + 1] = a;
	}
	for (int i = 1; i <= n; i++) {
		dp1[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr1[i] > arr1[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
		maxl1 = max(maxl1, dp1[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp2[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr2[i] > arr2[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
		maxl1 = max(maxl2, dp2[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (dp1[i] + dp2[n - i + 1] > maxl3) {
			maxl3 = dp1[i] + dp2[n - i + 1] - 1;
		}
	}

	cout << maxl3;
	return 0;
}