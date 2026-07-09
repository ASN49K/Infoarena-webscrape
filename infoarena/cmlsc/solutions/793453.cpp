#include<fstream>
using namespace std;

int i,j, m,n,a[1026],b[1026], c[1026][1026], scom[1026];

void pd() {
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
                { c[i][j]=c[i-1][j];
                  if (a[i]==b[j] && c[i-1][j-1]+1>c[i][j]) c[i][j]=c[i-1][j-1]+1;
                  if (c[i][j-1]>c[i][j]) c[i][j]=c[i][j-1]; };
                }
void drum() {
        i=n; j=m;
        int k=c[n][m];
        while (i>0 && j>0)
           if (a[i]==b[j] && c[i][j]==c[i-1][j-1]+1) { scom[k--]=a[i]; i--; j--; }
           else if (c[i-1][j]>c[i][j-1]) i--;
                else j--;
        }

int main() {
        ifstream f1("cmlsc.in");
        ofstream f2("cmlsc.out");
        f1>>n>>m;
        for (i=1;i<=n; i++) f1>>a[i];
        for (i=1; i<=m; i++) f1>>b[i];

        pd();
        drum();

        f2<<c[n][m]<<"\n";
        for (i=1; i<=c[n][m]; i++)
            f2<<scom[i]<<" ";
        f1.close();
        f2.close();
        return 0; }
