program euclid2;
var t,a,b:longint;
    f1,f2:text;
    i:integer;
function cmmdc(a,b:longint):longint;

begin

repeat
if a>b then a:=a-b
	else b:=b-a;
 cmmdc:=a;
 until a=b;
end;

BEGIN
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);
rewrite(f2);
readln(f1,t);
      for i:=1 to t do    begin
      readln(f1,a,b);
      writeln(f2,cmmdc(a,b));
                               end;
      close(f1);close(f2);
      end.