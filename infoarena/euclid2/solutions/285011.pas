var a,b,t,d,i,n:longint; f,g:text;
function cmmdc(a,b:longint):longint;
begin
if b<>0 then
cmmdc:=cmmdc(b,a mod b)
else cmmdc:=a;
end;
BEGIN

assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,n);
for n:=1 to i do
 readln(f,a,b);
writeln(g,cmmdc(a,b));
close(f); close(g);

END.
