#include<fstream>
using namespace std;
typedef unsigned int intPoz;
intPoz euclid(intPoz a, intPoz b){
    if(!a || !b ) return a+b;
    if(a > b) return euclid(a%b,b);
    else return euclid(a,b%a);
}
int main()
{

    intPoz T,t,x,y;
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");

    fin >> T;
    for(t = 0; t < T; t++){
        fin >> x >> y;
        fout << euclid(x,y) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
