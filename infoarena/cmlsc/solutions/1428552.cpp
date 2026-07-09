#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define Nmax 10001
int b[Nmax],a[Nmax],sir[Nmax],sol[Nmax],M,N,bst;
void citire()
{
    ifstream f("cmlsc.in");
    cin>>M>>N;
    for (int i =0 ; i<M ; i++)
        cin>>a[i];
    for(int j=0;j <N; j++)
        cin>>b[j];

}
int subsir(int nr)
{
    int j=1;
    for (int i =1 ; i <= nr && j <=N; i++)
      for ( ;j<=N && b[i] != sir[j]; ++j );
         return j <= N;
}

void bkt( int nivel , int len)
{
    ofstream g("cmlsc.out");

    if(nivel == M +1)
    {
        if(subsir(len))
           {

            if(bst < len)
            bst = len;
        for ( int i = 1 ; i <= bst;i++)
        {
            cout<<sir[i];
        }
         return ;
        }

    }
    bkt(nivel+1,len);
    sir[len+1]=a[nivel];
    bkt(nivel+1,len+1);
}
int main()
{
    citire();
    bkt(1,0);
}
