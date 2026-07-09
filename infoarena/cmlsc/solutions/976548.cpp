#include <fstream>
using namespace std;

int m,n,a[1024],b[1024],matrix[1024][1024],raspuns[1024],dim;

int maxim(int q,int w)
{
    if(q>=w) return q;
      else return w;
}


int main()
{
    ifstream inFile("cmlsc.in");
    inFile>>m>>n;
    int i,j;
    for(i=1;i<=m;i++) inFile>>a[i];
    for(i=1;i<=n;i++) inFile>>b[i];

    ofstream outFile;
    outFile.open("cmlsc.out");


dim=0;

for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(a[j]==b[i]) {
                       matrix[i][j]=1+matrix[i-1][j-1];
                      // dim++; raspuns[dim]=a[j];
                     }
         else matrix[i][j]=maxim(matrix[i-1][j],matrix[i][j-1]);
/*
for(i=1;i<=n;i++) {
    for(j=1;j<=m;j++)
        outFile<<matrix[i][j]<<" ";
        outFile<<endl;
                 }
*/
dim=1;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        {
          if(matrix[i][j]==dim) {raspuns[dim]=a[j];dim++; }
        }

 dim--;
 outFile<<matrix[n][m]<<endl;
 for(i=1;i<=matrix[n][m];i++) outFile<<raspuns[i]<<" ";
    outFile.close();
    return 0;
}

