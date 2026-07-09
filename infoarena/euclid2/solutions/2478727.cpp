#include <fstream>
using namespace std;
int cmmdc(int x,int y){
        int r=x%y;
        while(r){
            x=y;
            y=r;
            r=x%y;
        }
        return y;
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
    out<<cmmdc(m,n);
    }
        }
