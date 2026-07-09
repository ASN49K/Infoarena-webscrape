var a,b,r,aux,i,n:longint;
    f,g:text;
begin
        assign(f,'euclid2.in');
        reset(f);
        readln(f,n)

        for i:=1 to n do begin
        read(f,a);
        readln(f,b);


        if b>a then begin
                aux:=a;
                a:=b;
                b:=aux;
                end;

        repeat
        r:=a mod b;
        a:=b;
        if (r=0) and (b>1) then
                k:=1;
        b:=r;
        until r=0;

        assign(g,'euclid2.out');
        rewrite(g);
        writeln(g,a);
        end;

        close(f);
        close(g);
end.
