var f,g:text;
i,n,a,b,j:longint;
function divizor(a,b:longint):longint;
var i:integer;
q:longint;
begin
        while b<>0 do begin
                q:=a mod b;
                a:=b;b:=q;
        end;
        divizor:=a;
end;
begin
        assign (f,'euclid2.in');assign (g,'euclid2.out');
        reset(f);rewrite (g);
        read (f,n);
        for i:=1 to n do begin
                read (f,a,b);
                if a<b then begin
                        j:=a;a:=b;b:=j;  end;
                writeln (g,divizor(a,b)); end;
        close(f);close(g);
end.
