#include<iostream>
#include<fstream>
#define MAX 1024
using namespace std;

int M, N,A[MAX], B[MAX],Sol[MAX];

int bckt(int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(A[i]==B[j])
    {
        int t=bckt(i-1,j-1);
        Sol[t]=A[i];
       return t+1;
    }
    else if(bckt(i-1,j)>bckt(i,j-1))
           bckt(i-1,j);
    else
        bckt(i,j-1);
}

int main(void)
{
    int i;

    ifstream fi("cmlsc.in");
    ofstream fo("cmlsc.out");

    fi>>M>>N;
    for(int i=1;i<=M;i++)
        fi>>A[i];
    for(int i=1;i<=N;i++)
        fi>>B[i];

    int nr=bckt(M,N);
    fo<<nr<<'\n';
    for(int i=0;i<nr;i++)
         fo<<Sol[i]<<' ';

    fi.close();
    fo.close();
    return 0;
}
