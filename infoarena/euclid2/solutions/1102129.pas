Program A1;
var a,b,k,t:longint;
    o,i:text;
function cmmdc(var a:longint;b:longint):longint;
begin
   if b=0 then cmmdc:=a
     else cmmdc:=cmmdc(b,a mod b);
end;
begin
assign(i,'euclid2.in');
assign(o,'euclid2.out');
reset(i);
rewrite(o);
readln(i,t);
for k:=1 to t do
begin
   readln(i,a,b);
   writeln(o,cmmdc(a,b));
end;
close(i);
close(o);
end.