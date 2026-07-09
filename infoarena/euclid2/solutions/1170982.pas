program algoritmul_lui_euclid;
var f,g:text;
a,b,t,i,aux,r:longword;
begin
assign(f,'euclid2.in'); assign(g,'euclid2.out'); reset(f); rewrite(g);
readln(f,t);
for i:=1 to t do
        begin
        readln(f,a,b);
        if a>b then begin aux:=a; a:=b; b:=aux; end;
        while b>0 do
                begin
                r:=b;
                b:=a mod b;
                a:=r;
                end;
        writeln(g,a);
        end;
close(f); close(g);
end.
