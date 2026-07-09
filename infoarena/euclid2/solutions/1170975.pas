program algoritmul_lui_euclid;
var f,g:text;
a,b,t,i,min,j,cm:longword;
begin
assign(f,'euclid2.in'); assign(g,'euclid2.out'); reset(f); rewrite(g);
readln(f,t);
for i:=1 to t do
        begin
        readln(f,a,b);
        min:=(a+b-abs(a-b)) div 2;
        cm:=1;
        for j:=2 to min do
                if (a mod j=0) and (b mod j=0) then cm:=j;
        writeln(g,cm);
        end;
close(f); close(g);
end.
