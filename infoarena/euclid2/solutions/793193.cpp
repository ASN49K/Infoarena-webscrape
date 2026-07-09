#include <fstream>
using namespace std;
int main()
{
    int t, a, b,sw,  c, r,i ;
    ifstream in("euclid2.in") ;
    ofstream out("euclid2.out") ;
    in>>t ;
    for(i=1;i<=t;i++) {
    c=0; r=0;
    in>>a>>b ;
        if(a<b){
        sw=a; a=b; b=sw; }

    do{
        c=(a/b);
        r=(a%b);
        a=b;
        if(r>0)
        b=r ;
}while(r>0) ;
    out<<b<<endl;
    }
    return 0;
}
