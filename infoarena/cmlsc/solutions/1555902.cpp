#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream fin("cmlsc.in");
    int n,m,a[1030],b[1030];
    vector<int> v;
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
        fin.close();
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]){v.push_back(a[i]);break;}
        }
    }
    ofstream fout("cmlsc.out");
    fout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
        fout<<v[i]<<" ";
        fout.close();
        return 0;
}
