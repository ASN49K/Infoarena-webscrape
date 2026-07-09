var i,t,a,b,r:longint; f1,f2:text;

function cmmdc(a,b:longint):longint;
var x,y:longint;
begin
  x:=a; y:=b;
  while (x<>0)and(y<>0) do
    if x>y
    then x:=x mod y
    else y:=y mod x;
  cmmdc:=x+y;
end;

begin
   assign(f1,'euclid2.in');
   reset(f1);
   assign(f2,'euclid2.out');
   rewrite(f2);
   read(f1,t);
   for i:=1 to t do
   begin
      read(f1,a,b);
      r:=cmmdc(a,b);
      writeln(f2,r);
   end;
   close(f1);
   close(f2);
end.
