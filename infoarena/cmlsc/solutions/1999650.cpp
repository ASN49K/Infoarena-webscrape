#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m;
    fin>>n>>m;
    vector<int> a(n,0),b(m,0),ss(0,0),Mss(0,0);
    for(int i=0;i<n;i++)
    {
        fin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        fin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            {
                Mss.push_back(a[i]);
            }
        }
    }
    fout<<Mss.size()<<"\n";
    for(int i:Mss)
    {
        fout<<i<<" ";
    }
    return 0;
}
