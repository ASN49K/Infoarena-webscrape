#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <thread>

#define pb push_back
#define mp make_pair
#define MAXN 100001
#define DIM 8192
using namespace std;

int t,a,b;

ofstream fout("euclid2.out");
class Reader
{
public:
    Reader(const char* filename)
    {
        f.open(filename);
        pos = 0;
        f.read(buffer,DIM);
    }
    inline Reader& operator >>(int& x)
    {
        x=0;
        sgn=1;
        while((buffer[pos]<'0'||buffer[pos]>'9')&&buffer[pos]!='-')
            if(++pos==DIM)
                f.read(buffer,DIM),pos=0;
        if(buffer[pos]=='-')sgn=-1,pos++;
        while(buffer[pos]>='0'&&buffer[pos]<='9')
        {
            x=x*10+buffer[pos]-'0';
            if(++pos==DIM)f.read(buffer,DIM),pos=0;
        }
        x*=sgn;
        return (*this);
    }
    inline Reader& operator >>(char* c)
    {
        aux = 0;
        while(isspace(buffer[pos]))
            if(++pos==DIM)
                f.read(buffer,DIM),pos=0;
        while(!isspace(buffer[pos]))
        {
            c[aux++]=buffer[pos];
            if(++pos==DIM)f.read(buffer,DIM),pos=0;
        }
        return (*this);
    }
    ~Reader()
    {
        f.close();
    }
private:
    ifstream f;
    int pos,aux,sgn;
    char buffer[DIM];
};
Reader fin("euclid2.in");
int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
