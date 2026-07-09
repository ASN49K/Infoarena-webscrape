#include <iostream>
#include <fstream>
using namespace std;

int main(){

ifstream teia("cmlsc.in");
ofstream rares("cmlsc.out");

int n,m,v[1069],c[1069],p=0;

teia>>n>>m;

for(int i=0;i<n;i++){
	teia>>v[i];
}
for(int i=0;i<m;i++){
	teia>>c[i];
}

for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(v[i]==c[j]){
			p++;
			break;
		}
	}
}
rares<<p<<"\n";	
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(v[i]==c[j]){
			rares<<v[i]<<" ";
			break;
		}
	}

}


return 0;	
}                                                                                                                                                                                                                                                                                                                                                                                                                               