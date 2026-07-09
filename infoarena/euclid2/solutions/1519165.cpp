#include <fstream>
#include <vector>
using namespace std;
ifstream fin("hashuri.in");
ofstream fout("hashuri.out");
 vector<int> v[666013];
long n;
void adaugare (int x)
{
    int niv = x%666013;
    v[ niv ].push_back(x);
}
bool verificare(int x)
{
    int niv = x%666013;
    for(int i=0;i<v[niv].size();i++)
        if(v[niv][i] == x)
            return 1;
    return 0;
}
void stergere (int x)
{
    int niv = x%666013;
    for(int i=0;i<v[niv].size();i++)
        if(v[niv][i] == x) {
            v[niv].erase(v[niv].begin() + i);
            return;
        }
}
int main()
{
    int op,x,i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>op>>x;
        if(op==1)
            adaugare(x);
        if(op==2)
            stergere (x);
        if(op==3)
            fout<<verificare(x)<<"\n";
    }
    return 0;
}
