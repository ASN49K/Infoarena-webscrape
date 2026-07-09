#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main(){
int m,n,c=0,vv=0;
in >>m>>n;
int a[m],b[n],dd[n];
for(int i=0;i<m;i++){
	in >>a[i];
}
for(int i=0;i<n;i++){
	in >>b[i];
}
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	if(a[i] == b[j]){
		c++;
		dd[vv]=a[i];
		vv++;
	}
}
}
out <<c<<"\n";
for(int i=0;i<vv;i++){
	out <<dd[i]<<" ";
}
}

