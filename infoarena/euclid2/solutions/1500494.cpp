#include<iostream>
#include<fstream>
using namespace std;
int asdf(int a, int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int a,b,n;
int main(){
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(int i=0;i<n;i++)
    {
        in >> a >> b;
        out << asdf(a,b);
    }
    return 0;
}
