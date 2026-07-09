#include <fstream>
using namespace std;
  int euclid(  int a,  int b){
    if(b==0)
        return a;
    else{
        return euclid(b,a%b);
    }
}
int main()
{
ifstream f("euclid2.in",ios::in);
ofstream g("euclid2.out",ios::out);
int t,a,b;
f>>t;
while(t){
    f>>a>>b;
    g<<euclid(a,b)<<"\n";
    t--;
}
f.close();
g.close();
return 0;
}
