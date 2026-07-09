#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream A("ciur.in");
    ofstream B("ciur.out");
    int N,n=0;
    A>>N;
    N-=2;
    int P[N];
    for (int i=0;i<=N;++i)
    {
        P[i]=1;
    }
    cout<<endl;
    for (int i=0;i<=N;++i)
    {
         if(P[i])
        {
            i+=2;
            ++n;
            for(int j=2*i;j<=N;j+=i)
                P[j]=0;
            i-=2;
        }

          cout<<P[i]<<" ";

    }

    B<<n;
    return 0;
}
