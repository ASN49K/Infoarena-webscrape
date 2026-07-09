#include <fstream>
#include <iostream>

using namespace std;

/*
int main()
{
    int nr1, nr2;
    cin>>nr1>>nr2;
    while(nr1!=nr2)
    {
        if(nr1>nr2)
        {
            nr1=nr1-nr2;
        }
        else if(nr2>nr1)
        {
            nr2=nr2-nr1;
        }
    }
    cout<<nr1;
    return 0;
}
*/

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    int x, nr1, nr2, rest;
    fin>>x;
    for(int i=1;i<=x;i++)
    {
        fin>>nr1>>nr2;
        while(nr2)
        {
            rest=nr1%nr2;
            nr1=nr2;
            nr2=rest;
        }
        fout<<nr1<<"\n";
    }
}
