program asdadadad;
VAR f,g:text;
    t,a,b:longint;
    r:integer;
Begin
        Assign(f,'euclid2.in');Reset(f);
        Assign(g,'euclid2.out');Rewrite(g);
        readln(f,t);
        while not eof(f) do begin
                readln(f,a,b);
                r:=1;
                while r<>0 do begin
                        r:=a mod b;
                        a:=b;
                        b:=r;
                end;
                writeln(g,a);
        end;
Close(f);Close(g);
end.
