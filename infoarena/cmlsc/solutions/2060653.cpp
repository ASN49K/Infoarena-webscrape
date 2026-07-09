#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
vector <int> v(100);
vector <int> w(100);
vector <int> k(100);
ifstream fin("date.in");



int main()
{
    int n,m,last=0;

    fin>>n>>m;
    if(n>=m)
    {
        int poz=-1;
        for(int i=0; i<n; i++)
            fin>>v[i];

        for(int i=0; i<m; i++)
        {
            int x;
            fin>>x;
            for(int j=0; j<n; j++)
                if(x==v[j] and poz<j )
                {
                    k[last++]=x;
                    poz=j;
                }
        }
    }
    else
     {
        int poz=-1;
        for(int i=0; i<n; i++)
            fin>>v[i];

        for(int i=0; i<m and poz!=n; i++)
        {
            int x;
            fin>>x;
            for(int j=0; j<m; j++)
                if(x==v[j] and poz<j )
                {
                    k[last++]=x;
                    poz=j;
                }
        }
        }

         k.resize(last);
         cout<<k.size()<<'\n';
        for(int i=0; i<last; i++)
            cout<<k[i]<< ' ';

        return 0;

}
