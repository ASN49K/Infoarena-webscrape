#include<fstream>

using namespace std;

unsigned long int a,b,nr;

int euclid(int a,int b){
    unsigned long int r;
    while(r){
              r=a%b;
              a=b;
              b=r;
              }
     return a;
    
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
                 
