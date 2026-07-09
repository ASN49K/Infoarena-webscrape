var c,d,m,n:longint;
function e(a,b:longint):longint;
begin
if (b>0) then e:=e(b,a mod b) else e:=a;
end;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
read(c);
for d:=1 to c do
begin
read(m,n);
writeln(e(m,n));
end;
end.
