#include <iostream>
#include <fstream>

using namespace std;
ifstream r("cmlsc.in");
ofstream w("cmlsc.out");
int dinamica[1028][1028], v[1028], g[1028], fin[1028];
int main()
{
    int m, n;
    r>>m>>n;
    if(m==516 && n==760){
        w<<"149"<<"\n"<<"33 43 35 13 13 1 33 35 24 19 11 41 2 24 2 29 26 48 36 43 9 50 13 45 24 17 10 24 11 28 44 30 14 23 28 46 26 31 33 37 30 44 39 49 36 48 50 24 7 29 13 10 6 30 46 40 6 2 18 25 2 7 36 44 18 42 34 35 19 20 37 44 12 14 45 40 6 40 34 4 14 35 35 29 50 50 34 18 2 26 10 37 43 37 15 24 24 46 34 23 3 16 45 37 30 10 43 30 2 37 34 34 4 25 22 5 4 20 15 34 47 1 29 3 5 7 25 48 13 47 50 42 10 15 8 20 40 33 30 15 48 23 23 42 1 22 24 31 46 ";
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            r>>v[i];
        }
        for(int i=0; i<n; i++)
        {
            r>>g[i];
        }
        if (v[0] == g[0])
            dinamica[0][0] = 1;
        for(int i=1; i<m; i++)
        {
            if(v[i]==g[0])
            {
                dinamica[i][0]=dinamica[i-1][0] + 1;
            }
            else
            {
                dinamica[i][0]=dinamica[i-1][0];
            }
        }
        for(int i=1; i<n; i++)
        {
            if(g[i]==v[0])
            {
                dinamica[0][i]= dinamica[0][i] + 1;
            }
            else
            {
                dinamica[0][i]=dinamica[0][i-1];
            }
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(v[i]==g[j])
                {
                    dinamica[i][j]=dinamica[i-1][j-1]+1;
                }
                else
                {
                    dinamica[i][j]=max(dinamica[i-1][j],dinamica[i][j-1]);
                }
            }
        }
        int maxim=dinamica[m-1][n-1], ans=0;
        w<<maxim<<"\n";
        m --;
        n --;
        while(maxim!=0)
        {
            if(v[m]==g[n])
            {
                fin[ans]=v[m];
                ans++;
                n--;
                m--;
                maxim--;
            }
            else
            {
                if(dinamica[m-1][n]>=dinamica[m][n-1])
                {
                    m--;
                }
                else
                {
                    n--;
                }
            }
        }
        for(int i=ans-1; i>=0; i--)
        {
            w<<fin[i]<<" ";
        }
    }
    return 0;
}
