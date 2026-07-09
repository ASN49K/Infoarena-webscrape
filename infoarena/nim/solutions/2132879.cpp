#include<fstream>
using namespace std;

int n,s,v[10000],x;

ifstream f("nim.in");
ofstream g("nim.out");

int main(){

    g>>n;
    for(int i=1;i<=n;i++){

        x=0;
        g>>s;

        for(int k=1;k<=s;k++){

            g>>v[k];
            x=x^v[k];

        }
        if(x!=0)
            g<<"DA"<<"\n";
        else
            g<<"NU"<<"\n";
    }

}
