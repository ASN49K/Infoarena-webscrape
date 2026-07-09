var i,t,a,b,r:longint; f1,f2:text;

function cmmdc(x,y:longint):longint;
begin
  if y=0 then cmmdc:=x
  else cmmdc:=cmmdc(y, x mod y);
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
