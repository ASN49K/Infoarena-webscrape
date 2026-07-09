program eucliddoi;
var a,b,r:longint;
    f,g:text;
begin
        assign(f,'euclid2.in');
        assign(g,'euclid2.out');
        reset(f);
        rewrite(g);
        read(f,a);
        read(f,b);
        r:=a mod b;
        while r<>0 do
        begin
                a:=b;
                b:=r;
                r:=a mod b;
        end;
        writeln(g,b);
        close(f);
        close(g);
end.

