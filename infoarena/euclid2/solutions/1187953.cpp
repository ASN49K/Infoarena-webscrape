
    #include<cstdio>
    #include<fstream>
    using namespace std;
    int t,a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int main()
    {
        FILE * f = fopen ("euclid2.in","r");
        FILE * g = fopen ("euclid2.out","w");

        fscanf (f, "%d", &t);
        while(t)
        {
            fscanf(f, "%d %d", &a, &b);
            while(b>0){
                r=a%b;
                a=b;
                b=r;
            }

            fprintf(g, "%d\n", a);
            --t;
        }

        fclose(f);
        fclose(g);

        return 0;
}
