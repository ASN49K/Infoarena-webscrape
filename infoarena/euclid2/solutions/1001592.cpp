    #include <iostream>

    #include <fstream>

    using namespace std;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int cmmdc(int x, int y)
    {
        int r;

        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        return x;
    }

    int main()
    {
        int x,y,t;
        f>>t;
        for(int i=0;i<t;i++)
        {
            f>>x>>y;
            g<<cmmdc(x,y)<<endl;
        }


        return 0;
    }
