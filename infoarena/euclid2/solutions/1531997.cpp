#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,y,i,k,aux;
    ofstream fout("euclid2.out");
    ifstream fin("euclid2.in");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        k=1;
        while(k==1)
            if(!y) k=0;
                else
                {
                    aux=x;
                    x=y;
                    y=aux%y;
                }
        fout<<x<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
