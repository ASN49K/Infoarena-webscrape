#include <bits/stdc++.h>

using namespace std;
int v[1005][3];
int main()
{
    ifstream fin("clmsc.in");
    ofstream fout("clmsc.out");
    int n;
    fin>>n;
    for(int k1=1;k1<=n;k1++)
    {
        fin>>v[k1][0];
    }
    // 0 - numarul
    // 1 - predecesorul
    // 2 - lungimea sirului
    v[1][1]=0;
    v[1][2]=1;
    int maxim1=1;
    int pozitie1=1;
    for(int k1=2;k1<=n;k1++)
    {
        int pozitie;
        int maxim=-1;
        for(int k2=1;k2<k1;k2++)
        {
            if(v[k2][0]<=v[k1][0])
            {
                if(v[k2][2]>maxim)
                {
                    maxim=v[k2][2];
                    pozitie=k2;
                }
            }
        }
        if(maxim!=-1)
        {
            v[k1][1]=pozitie;
            v[k1][2]=v[pozitie][2]+1;
            if(v[k1][2]>maxim1)
            {
                maxim1=v[k1][2];
                pozitie1=k1;
            }
        }
        else
        {
            v[k1][1]=0;
            v[k1][2]=1;
        }
    }
    if(maxim1!=1)
    {
    fout<<maxim1<<"\n";
    vector<int>v2;
    while(v[pozitie1][1]!=0)
    {
        v2.push_back(pozitie1);
        pozitie1=v[pozitie1][1];
    }
    v2.push_back(pozitie1);
    for(int k1=v2.size()-1;k1>=0;k1--)
    {
        fout<<v2[k1]<<' ';
    }
    }
    else
    {
        fout<<1<<"\n";
        fout<<v[1][0];
    }
    fin.close();
    fout.close();
}