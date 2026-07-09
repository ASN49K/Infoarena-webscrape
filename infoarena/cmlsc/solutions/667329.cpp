#include <fstream>
using namespace std;
#define NMax 1024
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst; 
int main()
{
int i, j;
cin>>M>>N;
for(i=1;i<=M;i++)
cin>>A[i];
for(i=1;i<=N;i++)
cin>>B[i];
for(i=1;i<=M;i++)
for(j=1;j<=N;j++)
if (A[i] == B[j])
D[i][j] = 1 + D[i-1][j-1];
else
if(D[i-1][j]>D[i][j-1])
D[i][j]=D[i-1][j];
else
D[i][j]=D[i][j-1];
for (i = M, j = N; i; )
if (A[i] == B[j])
{bst++;
sir[bst] = A[i], i--, j--;}
else if (D[i-1][j] < D[i][j-1])
j--;
else
i--;
cout<<bst<<"\n";
for (i = bst; i>=1; i--)
cout<<sir[i]<<" ";
return 0;
}
