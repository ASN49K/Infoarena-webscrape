#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid.in");
ofstream out("euclid.out");
int n, i, j, div;
struct capra{
    int unu;
    int doi;
};
int main()
{
    in>>n;
    capra vec[n];
    for(i=0;i<n;i++)
        in>>vec[i].unu>>vec[i].doi;
    for(i=0;i<n;i++){
        div=1;
        for(j=1;j<=min(vec[i].unu, vec[i].doi);j++){
            if(vec[i].unu%j==0 && vec[i].doi%j==0)
                div=j;
        }
        out<<div<<"\n";
    }
    return 0;
}
