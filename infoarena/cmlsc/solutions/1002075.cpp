#include <fstream>
#include <algorithm>

using namespace std;


int main()
{
    int i,m,k=0,a[100],b[1000],n,s=0,d;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin>>m>>n;

    for(i=0;i<m;i++)
        fin>>a[i];
    for(i=0;i<n;i++)
        fin>>b[i];
    d=b[0];
    for(i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a[i]==b[j])
                {
                    k++;
                    s=max(a[i],s);
                    d=min(d,b[j]);

                }
    fout<<k<<"\n"<<d<<" "<<s;




    fin.close();
    fout.close();

    return 0;
}
