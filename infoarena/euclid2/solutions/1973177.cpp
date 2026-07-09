#include <fstream>

using namespace std;
long a,b,t; int d,T,i;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> T;
    for(i=0;i<T;i++){
        t=1;
        in >> a >> b;
    while (a%2==0&&b%2==0)
        {a = a/2;
        b = b/2;
        d++;}
    while (a!=b){
        if (a%2==0) a = a/2;
        else if (b%2==0) b = b/2;
        else if (a>b) a = (a-b)/2;
        else b = (b-a)/2;}
    while(d){
        t=t*2;
        d--;}
    out << t*a << "\n";}
    return 0;
}
