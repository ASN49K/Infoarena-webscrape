#include<fstream>

using namespace std;

int a,b,nr;

int euclid(int a,int b){
    if(!b) return a;
    else euclid(b,a%b);
}

int main()
{
    ifstream g("euclid2.in");
    ofstream f("euclid2.out");
    
    g>>nr;
    for(;nr;nr--)
    {
                 g>>a>>b;
                 f<<euclid(a,b)<<endl;
                 }
    return 0;
}
                 
