#include<bits/stdc++.h>

using namespace std;

int n,m,A[1030],B[1030],rs[1030], D[1030][1030],i,j,x;
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
int main()
{

	in>>m>>n;
	
	for(i=1;i<=m;i++)
	  in>>A[i];
	for(i=1;i<=n;i++)
	  in>>B[i];
	  
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	   if(A[i]==B[j])
	     D[i][j]= ++D[i-1][j-1];
	    else D[i][j]=max(D[i-1][j],D[i][j-1]);
	   
	   out<<D[m][n]<<"\n"; 
	
    for(i=m,j=n;i && j;)
      if(A[i]==B[j]) {
	  rs[++x]=A[i];
      i--;
      j--;}
	  else 
	  
	  	if(D[i-1][j]<D[i][j-1])
	  	  j--;
	  	else i--;
	  	out<<rs[x];
	for(i=x-1;i;i--)
	 out<<" "<<rs[i];
	   
	    return 0;
	
}
