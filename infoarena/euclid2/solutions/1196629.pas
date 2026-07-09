var a,b,i,n:longint;f,g:text;
function euclid(m,n:longint):longint;
begin
if n=0 then euclid:=m
   else euclid:=euclid(n,m mod n);
end;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
read(f,n);
for i:=1 to n do
begin
read(f,a,b);
writeln(g,euclid(a,b));
end;
close(f);close(g);
end.
