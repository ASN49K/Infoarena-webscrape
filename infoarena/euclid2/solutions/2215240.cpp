#include <iostream>
#include <fstream>

using namespace std;

int gl_a,gl_b;

int euclid(int a, int b){
    if(a%b==0&&gl_b%b==0)
        return b;
    else if(b%a==0&&gl_a%a==0)
        return a;
    else if(a>b)
        return euclid(a,b-2);
    else if(b>a)
        return euclid(a-2,b);
}

int main()
{
    int t,a,b;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>t;
    for(int i=1;i<=t;i++){
        f>>a>>b;
        gl_a=a;
        gl_b=b;
        g<<euclid(a,b)<<endl;
    }




    f.close();
    g.close();

    return 0;
}
