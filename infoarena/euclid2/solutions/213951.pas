var a,b,r,i,n:longint;


var f,g:text;

begin
        assign(f,'euclid2.in');
        assign(g,'euclid2.out');
        reset(f);
        rewrite(g);

        readln(f,n);
        for i:=1 to n do
        begin
         readln(f,a,b);
         repeat
                r:=a mod b;
                a:=b;
                b:=r;
         until r=0;
         writeln(g,a);
        end;
        close(f);close(g);
end.
