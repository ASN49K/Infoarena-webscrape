#include <bits/stdc++.h>
using namespace std;



int main(){

	ifstream cin;
	cin.open("euclid2.in");
	ofstream cout;
	cout.open("euclid2.out");
	//int main
	int t;
	cin>>t;
	while(t--){
	int a,b,rest;
	cin>>a>>b;
	while(b != 0){

		rest = a % b;
		a = b;
		b=rest;

	}
	cout<<a;}
}
