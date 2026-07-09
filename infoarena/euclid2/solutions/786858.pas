var f,g:text;
a,b,k,i,n,j:longint;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,n);
for i:=1 to n do
begin
read(f,a,b);
for j:=a downto 1 do
if(a mod j=0)and(b mod j=0) then begin k:=j; break; end;
writeln(g,k);
end;
close(f);
close(g);
end.