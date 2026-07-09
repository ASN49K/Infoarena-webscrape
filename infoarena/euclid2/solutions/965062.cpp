#include<fstream>

int main()
{

    int a,b,i,r,aux;
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    in>>i;
    for( ; i ;--i)
    {

        in>>a>>b;
        if(b > a)
        {

            a = aux;
            a = b;
            b = aux;
        }
        r = a % b;
        while( r != 0)
        {

            a = b;
            b = r;
            r = a % b;
        }
        out<<b<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
