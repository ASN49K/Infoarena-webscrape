#include <iostream>
#include <fstream>

using namespace std;

/*int lnko(int a, int b)
{
    if(!b) return a;
    else lnko(b, a%b);
}*/
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,x,y,a,b,aux;
    f>>n;
    for(; n>0; n--){
        f>>x>>y;
        if(x<y){
            aux=x;
            x=y;
            y=aux;
        }
        while(y!=0){
            aux=x;
            x=y;
            y=aux%y;
        }
        g<<x<<endl;
    }
    return 0;
}
