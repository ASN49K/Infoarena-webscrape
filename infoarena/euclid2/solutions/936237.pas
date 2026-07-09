program algEuclid;
VAR
        f,g:text;
        n,a,b,i:longint;
        r:integer;
BEGIN
        assign(f,'euclid2.in'); reset(f);
        assign(g,'euclid2.out'); rewrite(g);
        readln(f,n);
        for i:=1 to n do begin
        readln(f,a,b);
                while b<>0 do begin
                        r:=b;
                        b:=a mod b;
                        a:=r;
                end;
        writeln(g,a);
        end;
        Close(g);
END.