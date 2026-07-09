program euclid2;
var t,a,b:longint;
    f1,f2:text;
    i:integer;
function cmmdc(a,b:longint):longint;

begin
if (a=b) then cmmdc:=a
	else if a>b then cmmdc(a-b,b)
        		else cmmdc(a,b-a);
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