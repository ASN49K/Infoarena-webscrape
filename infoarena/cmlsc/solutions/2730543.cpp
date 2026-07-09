#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    int a,b,v[1024],s[1024],con=0;
    bool v1[256]={false};
    fin>>a>>b;
    for (int i=0; i<a; i++)
    {
        fin>>v[i];
        v1[v[i]]=true;
    }
    for (int i=0; i<b; i++)
    {
        fin>>s[i];
        if (v1[s[i]]==true)
        {
            con++;
            v[con]=s[i];
        }
    }
    fout<<con<<endl;
    for (int i=1; i<con; i++)
        fout<<v[i]<<" ";
    fout<<v[con];
    return 0;
}
