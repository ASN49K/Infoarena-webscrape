#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int a, int b){
    int rest;
while(b){
        rest=a%b;
        a=b;
        b=rest;
}
return a;

}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int nr,nr1, nr2;
    in>>nr;
    for(int i=1; i<=nr; i++){
    in>>nr1>>nr2;


    out<<cmmdc(nr1,nr2)<<endl;
    }


    return 0;
}
