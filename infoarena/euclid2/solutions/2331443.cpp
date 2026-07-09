#include<bits/stdc++.h> 
using namespace std;
int getdiv(int a,int b){
	if (!b) return a;
	
	return getdiv(b, a % b);
}
int main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,m;
int k;
int i;
fin>>k;
while(k--){
fin>>n>>m;
fout<<getdiv(n,m);
fout<<endl;
}
}
