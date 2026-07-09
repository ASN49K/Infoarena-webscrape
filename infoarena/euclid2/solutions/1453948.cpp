#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int n,m,k,i,aux;
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

    cin>>k;
    for(i=0;i<k;i++){
    cin>>n>>m;
    while (n%m!=0) {
       aux=n %m;
       n=m;
       m=aux;

    }
    cout<<m<<endl;

    }

    return 0;
}
