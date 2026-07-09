Last login: Tue Dec 26 16:14:54 on console
Carminas-MacBook-Air:~ carmina$ vi






















#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int d=1,law=1;
void dosomething(int a,int b){
        if(a%d==0 && b%d==0)
        law=d;
        if(d<=a &&d <=b){
        d++;
        dosomething(a,b);
        }
}
int main() {
        int a,b,c;
        cin>>c;
        for(int i=0;i<c;i++){
                cin>>a>>b;
                dosomething(a,b);
                cout<<law<<endl;

