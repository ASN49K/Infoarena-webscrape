var
    f,g:text;
    n,i,a,b,r:longint;
begin
    assign(F,'euclid2.in');reset(f);
    assign(g,'euclid2.out');rewrite(g);
    readln(f,n);
    for i:=1 to n do
        begin
        readln(f,a,b);
        while b>0 do
            begin
            r:=a mod b;
            a:=b;
            b:=r;
            end;
        writeln(g,a,' ');
        end;
    close(F);close(g);
end.

