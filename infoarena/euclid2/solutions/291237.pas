var a,b,i,n:longint; f,g:text;
function cmmdc(a,b:longint):longint;
begin
if b<>0 then
cmmdc:=cmmdc(b,a mod b)
else cmmdc:=a;
end;
BEGIN

assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
begin
 readln(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f); close(g);

END.
