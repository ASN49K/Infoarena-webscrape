#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream be("cmlsc.in");
ofstream ki("cmlsc.out");
int a[1024][1024],k=0;
void lsc(int m,int n,vector<int>a1,vector<int>b,vector<int>&c)
{

    while(m!=0 && n!=0)
    {
        if(a1[n]==b[m])
        {
            k++;
            c[k]=a1[n];
            m--;
            n--;
        }
        else{ if(a[m-1][n]>a[m][n-1])
            m--;
        else
            n--;}
    }
}
int main()
{
   int n,m;
    be>>n>>m;
    vector<int>a1(n+1);
    vector<int>b(m+1);
    vector<int>c(n+m);
    for(int i=1;i<=n;i++)
        be>>a1[i];
    for(int j=1;j<=m;j++)
        be>>b[j];
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;j++)
            if(a1[j]==b[i]){
                    a[i][j]=a[i-1][j-1]+1;
            }
            else /*if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
            else a[i][j]=a[i][j-1];*/
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    ki<<a[m][n]<< '\n';
    lsc(m,n,a1,b,c);
    for(int i=k;i>0;i--)
        ki<<c[i]<<" ";
    return 0;
}
