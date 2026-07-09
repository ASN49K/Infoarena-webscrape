program algoritmul_lui_euclid;
var f,g:text;
a,b,t,i:longword;
begin
assign(f,'euclid2.in'); assign(g,'euclid2.out'); reset(f); rewrite(g);
readln(f,t);
for i:=1 to t do
        begin
        readln(f,a,b);
        while a<>b do
                if a>b then a:=a-b
                       else b:=b-a;
        writeln(g,a);
        end;
close(f); close(g);
end.
