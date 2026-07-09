#include <fstream>
#include <algorithm>

using namespace std;
int a[12];
int main()
{
    int n,i,j,x,y;
    ifstream fin("permutari.in");
    fin>>n;
    fin.close();
    for(i=1;i<=n;i++)
        a[i]=i;
    ofstream fout("permutari.out");
    while(a[0]==0)
        {
              for(i=1;i<=n;i++)
                fout<<a[i]<<'\n';
            fout<<'\n';
            j=n;
            while(a[j]<a[j-1])
                    j--;

            x=a[j-1]+1;
            for(i=j;i<=n;i++)
                if(a[i]==x)
                    {
                        y=i;
                        break;
                    }
            x=a[j-1];
            a[j-1]=a[y];
            a[y]=x;
            sort(a+j,a+n+1);
        }
        fout.close();
    return 0;
}
