#include<fstream>
#define NMax 1024
using namespace std;
int m,n, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;
int main()
{
    
    int i,j;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=n;i++)
    f>>A[i];
    for(j=1;j<=m;j++)
    f>>B[j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
if (A[i] == B[j])
D[i][j]=1+D[i-1][j-1];
else if(D[i-1][j]<D[i][j-1])
D[i][j]=D[i][j-1];
else D[i][j]=D[i-1][j];

for(i = n, j = m; i;)
if(A[i]==B[j])
{bst++;
sir[bst]=A[i], i--,j--;}

else  if(D[i-1][j]<D[i][j-1])   
j--;

else

i--;
g<<bst<<"\n";

for (i = bst; i>=1; i--)

g<<sir[i]<<" ";
return 0;

}
