var a,b,r,aux,i,t:longint;
    f,g:text;
begin
        assign(f,'euclid2.in');
        reset(f);
        readln(f,t);

        assign(g,'euclid2.out');
        rewrite(g);

        for i:=1 to t do begin

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
        b:=r;
        until r=0;

        writeln(g,a);
        end;

        close(f);
        close(g);
end.
