#include <fstream>

using namespace std;

int main()
{
    int a[1025][1025],v1[1025],v2[1025],i,j,l1,l2,v[1025],k=0;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>l1>>l2;
    for(i=1;i<=l1;i++)
        fin>>v1[i];
    for(i=1;i<=l2;i++)
        fin>>v2[i];
    for(i=0;i<=l1;i++)
        a[0][i]=0;
    for(i=0;i<=l2;i++)
        a[i][0]=0;
    for(i=1;i<=l2;i++)
        for(j=1;j<=l1;j++)
            if(v1[j]==v2[i])
                a[i][j]=a[i-1][j-1]+1;
            else if(a[i][j-1]>a[i-1][j])
                    a[i][j]=a[i][j-1];
                else a[i][j]=a[i-1][j];
    fout<<a[l2][l1]<<"\n";
    i=l2;
    j=l1;
    while(a[i][j])
    {
        if(a[i][j]==a[i][j-1])
        {
            j--;
            continue;
        }
        else if(a[i][j]==a[i-1][j])
            {
                i--;
                continue;
            }
            else
            {
               v[k]=v1[j];
               k++;
               i--;
               j--;
            }
    }
    for(i=k-1;i>=0;i--)
        fout<<v[i]<<" ";
  /*   for(i=0;i<=l2;i++)
    {
        for(j=0;j<=l1;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
*/
    return 0;
}
