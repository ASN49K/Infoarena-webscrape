#include <fstream>
using namespace std;

int m,n,a[1025],b[1025],matrix[1025][1025],raspuns[1025],dim;

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
          if(matrix[i][j]==dim) {raspuns[dim]=a[j]; dim++; i++; }
        }

 dim--;
/* dim=1; i=1; j=1;
 while((j<=m)&&(i<=n))
       if(matrix[i][j]==dim)
          {
            raspuns[dim]=a[j];
            dim++;
            i++;
            j++;
          }
            else if(j<m) j++;
                  else {j=1; i++;}   */

 outFile<<matrix[n][m]<<" "<<endl;
 for(i=1;i<=matrix[n][m];i++) outFile<<raspuns[i]<<" ";
    outFile.close();
    return 0;
}

