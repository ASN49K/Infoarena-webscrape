#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,X[1025],Y[1025],LCS[2][1025],i,j,k,h,l=0,p=0,sir[1025]; // folosesc doar 2 linii din matrice si scriu peste ele
int main(){
	f>>n>>m;
	for(i=1;i<=n;i++){
		f>>X[i];}
	for(i=1;i<=m;i++){
		f>>Y[i];}
	for(k=1;k<=n;k++,l=1-l){
		for(h=1;h<=m;h++){
			if(X[k]==Y[h]){
				LCS[1-l][h]=1+LCS[l][h-1];
			}
			else{
				LCS[1-l][h]=max(LCS[l][h],LCS[1-l][h-1]);
			}
		}
	}
	i=n;j=m;
	while(i>=1 || j>=1){
		if(X[i]==Y[j]){
			p++;
			sir[p]=X[i];
			i--;
			j--;}
		else if (LCS[i-1][j] < LCS[i][j-1]) 
			j--;		
		else          
			i--; 
	}
	g<<LCS[l][h-1]<<'\n';
	for(i=p;i>=1;i--){
		g<<sir[i]<<" ";
	}
	f.close();
	g.close();
	return 0;
}

	
	