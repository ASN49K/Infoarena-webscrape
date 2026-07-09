#include <fstream>
using namespace std;
int x,y,n,cmmdc;
int euclid(int a, int b)  
  { 
    int c;  
    while (b) {  
        c = a % b;  
        a = b;  
        b = c;  
    }  
    return a;}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");  
    fin>>n;
    while(n)
    {
    fin>>x>>y;		     
    cmmdc=euclid(x,y);  
    fout<<cmmdc<<"\n";
    n--;
    }
    system ("pause");
    return 0;
}

