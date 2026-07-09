#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("cmmdc.in");
	ofstream cout("cmmdc.out");
	int a,b;
	cin >> a >> b;
	while(a!=b){
		if(a>b){
			a=a-b;
		}
		if(b>a){
			b=b-a;
		}
	}
	if(a==1){
		cout << 0;
	}
	else{
		cout << a;
	}
return 0;
}

