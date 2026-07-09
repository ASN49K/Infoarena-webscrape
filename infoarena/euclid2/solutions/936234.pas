program algEuclid;
VAR
        f,g:text;
        n,a,b:longint;
BEGIN
        assign(f,'euclid2.in'); reset(f);
        assign(g,'euclid2.out'); rewrite(g);
        readln(f,n);
        for i:=1 to n do begin
                readln(f,a,b);
                while a<>b do begin
                        if a>b then
                                a:=a-b
                                else
                                 b:=b-a;
                end;
                writeln(g,a);
        end;
        Close(g);
END.