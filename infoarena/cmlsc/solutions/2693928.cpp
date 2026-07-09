#include<bits/stdc++.h>  
using namespace std; 

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
  
int N, M, i, j, D[1030][1030], A[1030], B[1030], sir[1030], bst; 
  


// Driver Code 
int main()  
{  
	fi >> M >> N;
	for(i=1; i<=M; i++) fi >> A[i];
	for(i=1; i<=N; i++) fi >> B[i];

    for (i = 1; i <= M; i++)  
    for (j = 1; j <= N; j++)  
    {  
        if (A[i] == B[j]) D[i][j] = D[i - 1][j - 1] + 1;  
        else D[i][j] = max(D[i - 1][j], D[i][j - 1]);  
    } 
	
	/*cout << " #";
	for(i=1; i<=M; i++) cout << " " << A[i]; cout << '\n';
	
	for (i=1; i<=N; i++)  
	{	
		cout << " " << B[i];
		for (j=1; j<=M; j++) 
		cout << " " << D[j][i];
		cout << '\n';
	}*/
	
	for (i = M, j = N; i; )
	if (A[i] == B[j]) sir[++bst] = A[i], --i, --j;
	else 
	if (D[i-1][j] < D[i][j-1]) --j;
	else --i;
	  

      
    fo << bst << '\n';  
      for (i = bst; i; --i) fo << sir[i] << " ";
    return 0;  
}  
