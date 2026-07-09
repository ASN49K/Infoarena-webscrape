#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> a, b, s, a1(1025, 0);
int lmax;

struct date
{
    int fr, poz;
};

vector <date> v;

int main()
{
    int n, m;
    fin >> n >> m;
    if(n < m)
    {
        v.resize(257);
        for(int i = 0 ;i < n; i++)
        {
            int x;
            fin >> x;
            a.push_back(x);
        }
        for(int i = 0; i < m; i++)
        {
            int x;
            fin >> x;
            b.push_back(x);
            v[x].fr++;
            if(v[x].fr == 1)
                v[x].poz = i;

        }
    }
    else
    {
        v.resize(257);
        for(int i = 0; i < n; i++)
        {
            int x;
            fin >> x;
            b.push_back(x);
            v[x].fr++;
            if(v[x].fr == 1)
                v[x].poz = i;

        }
        for(int i = 0 ;i < m; i++)
        {
            int x;
            fin >> x;
            a.push_back(x);
        }
    }
    int last = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(v[a[i]].fr!= 0)
        {
            if(v[a[i]].fr == 1)
                  s.push_back(v[a[i]].poz);
            else
            {
                for(int it = v[a[last]].poz + 1 ;  it < b.size(); it++)
                {
                    if(b[it] == a[i])
                    {
                        v[a[i]].poz = it;
                        s.push_back(it);
                        break;
                    }
                }
            }
            last = i;

        }
    }
   for(int i = 0; i < s.size(); i++)
        fout << b[s[i]] << ' ' << s[i] << "\n";
    fout << "\n";
    for(int i = s.size() - 1; i > 0; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(s[i] > s[j])
            {
                a1[j] = max(a1[j], a1[i] + 1);
                lmax = max(lmax, a1[j]);
            }
        }
    }
    fout << lmax + 1 << "\n";
    for(int i = 0; i < a1.size(); i++)
    {
        if(a1[i] == lmax)
        {
            fout << b[s[i]] << ' ';
            lmax--;
        }
    }
    return 0;
}
