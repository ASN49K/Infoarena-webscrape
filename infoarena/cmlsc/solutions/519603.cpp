#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 1024+1;

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");

	int m,n;
	int a[MAX], b[MAX];
	int sol[MAX],prev[MAX],current[MAX],aux[MAX];

	in >> m >> n;
	a[0]=0; b[0]=0;
	for(int i=1;i<=m;i++) in >> a[i];
	for(int j=1;j<=n;j++) in >> b[j];

	for(int i=0;i<=m;i++) cerr<<a[i]<<" ";cerr<<"\n";
	for(int j=0;j<=n;j++) cerr<<b[j]<<" ";cerr<<"\n";

	for(int j=0;j<=n;j++){
		sol[j]=0;
		prev[j]=0;
		current[j]=0;
	} 
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if (a[i]==b[j]){
				if(sol[j]<=sol[j-1]){
					sol[j]=sol[j-1]+1;
					if(sol[j]==sol[j-1]){
						prev[j]=prev[j-1];
					}else{
						prev[j]=current[j-1];
					}
					current[j]=j;
				}
			}else{
				if(sol[j-1]>sol[j]){
					sol[j]=sol[j-1];
					prev[j]=prev[j-i];
					current[j]=current[j-1];
				}
			}
		}
	}

	out << sol[n] << "\n";

	int solIndex=sol[n]-1;
	aux[solIndex]=b[current[n]];
	int prevj = prev[n];
	while(prevj!=0){
		--solIndex;
		aux[solIndex]=b[prevj];
		prevj=prev[prevj];
	}


	for(int k=0;k<sol[n];k++){
		out << aux[k] <<" ";
	}
	out << "\n";

	in.close();
	out.close();
	return 0;
}
