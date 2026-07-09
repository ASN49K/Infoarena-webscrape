
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//cout << 10 % 5;
	freopen ("euclid2.out","w+",stdout);
	freopen("euclid2.in","r",stdin);
	//cout << "asa da";
	int cases;
	int a,b;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> a>>b;
		while (a != b || (a!=0 && b!=0)) {
			if ( a==0 ){
				a = b;
				break;
			}
			if ( b==0){
				break;
			}
			if (a > b) {
				a = a%b;
			} else {
				b = b%a;
			}
		}
		cout << a << endl;
	}
	fclose(stdout);
	return 0;
}
