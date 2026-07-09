#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[1000],i,j,o=1,k,bi[2000],B[1000],N,M,max=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M>>N;
    for(i=1;i<=M;i++)
    f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];
    for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(A[i]==B[j])
            {
                max++;
                bi[o]=B[j];
                o++;

            }
        }
    }
    cout<<max<<endl;
    for(i=1;i<o;i++)
        g<<bi[i]<<" ";

}
