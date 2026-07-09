/*Aceasta problema este tot de pe infoarena.http://infoarena.ro/problema/euclid2*/
#include <fstream>
using namespace std;

int main()
{   ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long long a,b,t,i,r,cmmdc;
    
    f >> t;
    
    for(i = 1;i <= t;i++){f >> a;
    f >> b;
    while (b){
    r = a%b;
    a = b;
    b = r;
    }
    cmmdc = a;
    if(cmmdc!=1)g << cmmdc<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
