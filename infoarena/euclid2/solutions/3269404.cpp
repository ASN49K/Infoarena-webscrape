#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

struct AA{
    int x,y;
};

int main()
{
    int T,r;
    AA p;
    fin>>T;
    while(T!=0){
            fin>>p.x>>p.y;
    if(p.x==p.y && p.x==0)
        fout<<1;
    else{
        while(p.y!=0){
            r=p.x%p.y;
            p.x=p.y;
            p.y=r;
        }
        fout<<p.x<<endl;
    }
    T--;
    }
    return 0;
}
