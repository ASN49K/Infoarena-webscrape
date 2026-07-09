#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n, m, a[1025], b[1025], c[1025], S = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    if(n < m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i] == b[j])
                {
                    c[S] = a[i];
                    S++;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(b[i] == a[j])
                {
                    c[S] = b[i];
                    S++;
                }
            }
        }
    }
    cout << S << endl;
    for(int i = 0; i < S; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}