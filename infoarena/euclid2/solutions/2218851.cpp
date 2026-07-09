#include<fstream>
#include<iostream>

using namespace std;

int cmmdc( unsigned a, unsigned b)
{
    if(a>b) return cmmdc(a-b, b);
    else if(a<b) return cmmdc(b-a, a);
    else return a;
}


int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    unsigned n = 0;   
    
    in >> n;
    for(unsigned i=0; i<n; i++)
    {
        unsigned a = 0;
        unsigned b = 0;
        in >> a >> b;
        out << cmmdc(a,b)<<'\n';      
    }
    
    in.close();
    out.close();
}
