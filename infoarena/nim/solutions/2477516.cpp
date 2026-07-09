#include <bits/stdc++.h>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,rez,x;
int main()
{int i,j;
 fin>>t;
 for(i=1;i<=t;i++)
    {fin>>n;
     rez=0;
     for(j=1;j<=n;j++)
        {fin>>x;
         rez^=x;
        }
     if(rez==0)
        fout<<"NU"<<'\n';
        else
         fout<<"DA"<<'\n';
    }
 return 0;
}
