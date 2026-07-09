#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int i,j,m[1025][1025],n,n2,a[1025],b[1025],sir[1025],bst;
int main()
{
    f>>n>>n2;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=n2;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=n2;j++)
        if(a[i]==b[j]) m[i][j]=m[i-1][j-1]+1;
        else if(m[i-1][j]>m[i][j-1]) m[i][j]=m[i-1][j];
             else m[i][j]=m[i][j-1];
    //for(i=1;i<=n;i++)
    //{
      //  for(j=1;j<=n2;j++)
        //    cout<<m[i][j]<<" ";
        //cout<<endl;
    //}

    for(i=n,j=n2;i;)
        {
            if(a[i]==b[j]) {sir[bst++]=a[i];
                            i--;
                            j--;
                            }
            else if(m[i-1][j]<m[i][j-1])j--;
            else i--;
        }
    g<<bst<<endl;
    for(i=bst-1;i>=0;i--)
        g<<sir[i]<<" ";
    return 0;
}
