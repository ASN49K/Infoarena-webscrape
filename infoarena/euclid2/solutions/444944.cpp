#include <iostream>
using namespace std;
int lnko(int x,int y) {
	if (!y) return x;
	return lnko(y,x%y);
}
int main(void) {
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,a,b;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >>a >> b;
		cout << lnko(a,b) << endl;
	}
}
