var
    f,g:text;
    n,i,a,b,r:longint;
    buf:array[1..1 shl 17] of char;
begin
    assign(F,'euclid2.in');reset(f);
    assign(g,'euclid2.out');rewrite(g);
    settextbuf(f,buf);
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
    close(F);close(g);
end.
