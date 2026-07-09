#include"fstream"
using namespace std;
long a,b,c;
int main()
{
    ifstream fin("euclid2.in");
    fin>>a>>b;
    fin.close();    
    while(b)
       {
           c=a%b;
           a=b;
           b=c;
       }
    ofstream fout("euclid2.out");
    fout<<a;
    fout.close();
    return 0;
    
}            
