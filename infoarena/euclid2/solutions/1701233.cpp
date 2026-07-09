#include<fstream>
#include<iostream>
using namespace std;
int a,b,x, T;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(int i=1; i<=T; ++i)
        {
            fin>>a>>b;
            while(b)
                {
                    x=a%b;
                    a=b;
                    b=x;

                }
            fout<<a<<'\n';
        }

}
