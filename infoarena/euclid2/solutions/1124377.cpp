#include <iostream>
#include <fstream>

using namespace std ;

int main()
{
   ifstream fin("ciur.in");
   ofstream fout("ciur.out");



    int i,a, b, n ;
    fin >> n ;
    for(i=1; i<=n; ++i)
        {
        fin>>a>>b;
        while(a!=b){
            if(a>b)
                a=a-b;
                else b=b-a;
        }

        fout<< a<<'\n';

    }

    return 0;
}
