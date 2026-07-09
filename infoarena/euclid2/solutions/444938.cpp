#include <iostream>
using namespace std;
int main(void) {
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,a,b;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >>a >> b;
		if (a==0) cout << b << endl;
		else if (b==0) cout << a << endl;
		else {
			while (a!=b) {
				if (a>b) a-=b;
				else b-=a;
			}
			cout << a << endl;
		}
	}
}
