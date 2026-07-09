#include <bits/stdc++.h>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int n , q , a[100005] , st , dr , val , cnt = 0 , egal , aux[100005] , k , ok = 0 , mx;

/**void Afis()
{
    for(k = st;k <= dr;k++)
        cout << a[k] << " ";
    cout << "\n";
}*/

int main()
{
    int i , j;
    fin >> n >> q;
    for(i = 1;i <= n;i++)
    {
        fin >> a[i];
        aux[i] = a[i];
    }
    while(q--)
    {
        fin >> st >> dr >> val;
        mx = -1;
        ///Afis();
        for(i = st;i <= dr;i++)
            if(a[i] > mx) mx = a[i];
        cnt = 0;
        egal = 0;
        while(egal == 0)
        {
            for(i = st;i <= dr;i++)
                if(a[i] == val) egal++;
            if(dr - st + 1 == egal){egal = 1;break;}
            else egal = 0;
            for(i = st;i <= dr;i++)
            {
                ///Afis();
                if(val < mx)
                    while(a[i] >= val)
                    {
                        a[i] = 0;
                        i++;
                        ok = 1;
                    }
                    ///1 2 1 2   0 0 0 0
                else
                    while(a[i] > val)
                    {
                        a[i] = 0;
                        i++;
                        ok = 1;
                    }
                if(ok == 1) cnt++;
                if(a[i] < val)
                {
                    i++;
                    ok = 0;
                }
                ///cout << "|" << i << " " << mx << "|";
            }
            ok = 0;
            for(i = st;i <= dr;)
            {
                ///Afis();
                while(a[i] == val and i <= dr) i++;
                for(j = i;a[j] < val and j <= dr;j++)
                {
                    a[j]++;
                    ok = 1;
                }
                if(ok == 1)
                {
                    cnt++;
                    ok = 0;
                }
                i = j;
            }
        }
        for(i = 1;i <= n;i++)
            a[i] = aux[i];
        fout << cnt << "\n";
        ///cout << "\n\n\n\n\n\n\n\n";
    }
    return 0;
}
