#include<bits/stdc++.h>

using namespace std;

int n,m,A[1030],B[1030],rs[1030], D[1030][1030],i,j,x;

int main()
{
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	
	cin>>m>>n;
	
	for(i=1;i<=m;i++)
	  cin>>A[i];
	for(i=1;i<=n;i++)
	  cin>>B[i];
	  
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	   if(A[i]==B[j])
	     D[i][j]= ++D[i-1][j-1];
	    else D[i][j]=max(D[i-1][j],D[i][j-1]);
	   
	   cout<<D[m][n]<<endl; 
	
    for(i=m,j=n;i && j;)
      if(A[i]==B[j]) {
	  rs[++x]=A[i];
      i--;
      j--;}
	  else 
	  
	  	if(D[i-1][j]<D[i][j-1])
	  	  j--;
	  	else i--;
	for(i=x;i;i--)
	 cout<<rs[i]<<' ';
	   
	    return 0;
	
}
