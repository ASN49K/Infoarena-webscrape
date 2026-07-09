var t,i,a,b:longint;

function cmmdc(a,b:longint):longint;
var r:longint;
begin
while b<>0 do
  begin
  r:=a mod b;
  a:=b;
  b:=r;
  end;
cmmdc:=a;
end;

begin
assign(input,'euclid2.in');
reset(input);
assign(output,'euclid2.out');
rewrite(output);
readln(t);
for i:=1 to t do
  begin
  readln(a,b);
  writeln(cmmdc(a,b));
  end;
close(input);
close(output);
end.