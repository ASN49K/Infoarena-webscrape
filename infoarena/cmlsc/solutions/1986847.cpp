#include<fstream>
#include<iostream>

using namespace std;

int max(int x, int y){
	if(x>y) return x;
	return y;
}


int main(){
	ifstream in; ofstream out;
	in.open("cmlsc.in"); out.open("cmlsc.out");
	out.clear();
	int m,n,i,j, where; 
	in>>m>>n;
	int intersect[max(m,n)];
	int a[m+1], b[n+1], sol[n+1][m+1];
    for(i=1;i<=m;i++) in>>a[i];
    for(i=1;i<=n;i++) in>>b[i]; 
	for(i=0;i<=n;i++) sol[i][0]=0;    
    for(i=0;i<=m;i++) sol[0][i]=0;
    
    for(i=1;i<=n;i++)
       for(j=1; j<=m; j++){
       	  if(b[i]==a[j]) sol[i][j]=sol[i-1][j-1]+1;
       	  else   sol[i][j]=max(sol[i-1][j], sol[i][j-1]);    
	   }
	out<<sol[n][m]<<endl;
	
	i=n; j=m; where=0;
	while(i!=0 && j!=0){
		if(b[i]==a[j]) {
	           intersect[where]=b[i];
			   where++;
			   i--; j--; 
			}
		else if(sol[i-1][j]>sol[i][j-1]) i--; 
		else j--;
	}
	
	
	while(where!=0){
		where--;
		out<<intersect[where]<<" ";
	}
	
		
		
	in.close(); out.close();
}
