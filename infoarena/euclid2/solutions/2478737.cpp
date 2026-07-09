#include <fstream>
using namespace std;
int cmmdc(int x,int y){
        if(!y)return x;
        else return cmmdc(y,x%y);
    }
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a;
    in>>a;
    for(int i=0;i<a;i++){
            int m,n;
       in>>m>>n;
    out<<cmmdc(m,n)<<"\n";
    }
        }
