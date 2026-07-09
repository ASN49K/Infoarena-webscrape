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
        return euclid(a,b-1);
    else if(b>a)
        return euclid(a-1,b);
}

int main()
{
    int t;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>t;
    while(t>0){
        f>>gl_a>>gl_b;
        g<<euclid(gl_a,gl_b)<<endl;
        t--;
    }




    f.close();
    g.close();

    return 0;
}
