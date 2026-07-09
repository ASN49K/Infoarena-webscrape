var f,g:text; n,m,k,i:integer;
begin
assign(f, 'euclid2.in');
reset(f);
assign(g, 'euclid2.out');
rewrite(g);
readln(f,k);
for i:=1 to k do
begin
read(f,n); readln(f,m);
while (m mod n<>0) and (n mod m<>0) do
if n>m then n:=n mod m
       else m:=m mod n;
if n>m then writeln(g,n)
        else writeln(g,m);
end;
close(f); close(g);
end.