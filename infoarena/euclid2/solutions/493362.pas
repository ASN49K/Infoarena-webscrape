program euclid;
var f,g:text; i,t,a,b:longint;
function cmmdc(a,b:longint):longint;
var r:longint;
begin
r:=1;
While r>0 do
 begin
 r:=a mod b;
 a:=b;
 b:=r;
 end;
cmmdc:=a;
end;
begin
Assign(f,'euclid2.in'); Reset(f);
Assign(g,'euclid2.out');Rewrite(g);
Readln(f,t);
For i:=1 to t do
 begin
 Readln(f,a,b);
 Writeln(g,cmmdc(a,b));
 end;
Close(f); Close(g);
end.