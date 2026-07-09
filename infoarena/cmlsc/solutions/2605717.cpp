#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main(){
long long int m,n,c=0,ll=0;
in >>m>>n;

int a[m],b[n],dd[m][n],yu[n];
for(int i=0;i<m;i++){
	in >>a[i];
}
for(int i=0;i<n;i++){
	in >>b[i];
}
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		if(i==0 || j==0){
			dd[i][j]=0;
		}else if(a[i]==b[j]){
    	dd[i][j]=dd[i-1][j-1]+1;
    	c=dd[i][j];
    	yu[ll]=a[i];
    	ll++;
	}else{
		dd[i][j]=max(dd[i-1][j],dd[i][j-1]);
		c=dd[i][j];
		
	}
}
}
out <<c<<"\n";
for(int i=0;i<c;i++){
	out <<yu[i]<<" ";
}

}
/*
	if(a[i] == b[j]){
		c++;
		dd[vv]=a[i];
		vv++;
		ii=j;
		break;
	}
	*/

