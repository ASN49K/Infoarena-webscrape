#include<iostream>

using namespace std;
int n;
void read(){
	freopen("euclid2.in", "r", stdin);
	cin >> n;
}

void swap(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
}

int main(){
	freopen("euclid2.out", "w", stdout);
	read();
	int a, b;
	for (; n; n--){
		cin >> a >> b;
		if (a % b == 0){
			printf("%d\n", b);
			continue;
		}
		if (b % a == 0){
			printf("%d\n", a);
			continue;
		}
		if (a < b){
			swap(a, b);
		}
		while (a % b){
			a = a % b;
			swap(a, b);
		}
		printf("%d\n", b);
	}
	return 0;
}