#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in") ;
ofstream fout ("cmlsc.out") ;

int main()
{
    int n , m , sir1[1030] , sir2[1030] , com[1030] , ma=0 ;
    fin>>n>>m ;
    for(int i=1 ; i<=n ; i++)
        fin>>sir1[i] ;
    for(int j=1 ; j<=m ; j++)
        fin>>sir2[j] ;
    for(int i=1 ; i<=m ; i++)
    {
        for(int j=1 ; j<=n ; j++)
            if(sir2[i]==sir1[j])
            {
                ma++ ;
                com[ma]=sir2[i] ;
            }
    }
    fout<<ma<<"\n" ;
    for(int i=1 ; i<=ma ; i++)
        fout<<com[i]<<" " ;
    return 0;
}
