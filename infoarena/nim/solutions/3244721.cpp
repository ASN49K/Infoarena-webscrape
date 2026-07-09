#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("ciur.in", "r", stdin);
	freopen("ciur.out", "w", stdout);

	int N;
	cin >> N;

	vector<bool> isPrime(N + 1, true);
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += i)
			isPrime[j] = false;
	}

	int countPrimes = 0;
	for (int i = 2; i <= N; i++)
		countPrimes += (isPrime[i] ? 1 : 0);
	cout << countPrimes;

	return 0;
}