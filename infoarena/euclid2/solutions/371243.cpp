#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in" ,ios::in);
    ofstream fout("euclid2.out", ios::out);
    int a,b, c;
    fin>>a>>b;
    fin.close();
    if(a<=b)
    c=a;
    else
    c=b;
    for(int i=c; i>=1; i--)            
                    if(a%i==0 && b%i==0)
                    {
                    if(i==1)
                    fout<<"0";
                    else
                    {
                    fout<<i;
                    break;
                    }
}
    fout.close();
}
