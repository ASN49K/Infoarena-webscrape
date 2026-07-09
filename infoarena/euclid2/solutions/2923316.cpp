#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid1.out");
int main()
{
    int t,a,b,aux;
    fin>>t;
    while(fin>>a>>b)
    {
        if(a<b)switch(a,b);
        while(a%b!=0)
        {
            aux=b;
            b=a%b;
            a=aux;
        }
        fout<<b<<endl;
    }
    fin.close();
    fout.close();

    return 0;
}
