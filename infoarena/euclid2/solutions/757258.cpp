#include <iostream>
#include <fstream>
using namespace std;
void cmmdc ( int , int );
ifstream fin ( "fin.txt");
    ofstream fout ( "fout.txt");
int main()
{
    int n,a,b,i;
    //ifstream fin ( "fin.txt");
    //ofstream fout ( "fout.txt");
    fin>>n;
    for (i=0;i<n;i++)
    {
        fin>>a>>b;
        cmmdc ( a,b );
    }
    return 0;
}

void cmmdc ( int a , int b )
{
    int r;
    while ( b!=0 )
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
}
