var f,g:text;
    w,n,k,i:longint;
function cmmdc(a,b:longint):longint;
begin
while a <> b do
begin
if a> b then
a:=a-b
else
b:=b-a;


end;

cmmdc:=a;
end;
BEGIN
assign(f,'euclid2.in');
assign(g,'euclid2.out');
rewrite(g);
reset(f);
read(f,n);
for i:=1 to n do
begin
readln(f,w,k);
writeln(g,cmmdc(w,k));
end;
close(f);close(g);
END.