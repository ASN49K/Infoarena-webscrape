var f,f2:text;
    t,i,a,b:longint;

function cmmdc(x,y:longint):longint;
 var aux:longint;
 begin
  while y<>0 do
   begin
    aux:=y;
    y:=x mod y;
    x:=aux;
   end;
  cmmdc:=x;
 end;

begin
assign(f,'euclid2.in');
assign(f2,'euclid2.out');
reset(f);
rewrite(f2);
readln(f,t);
for i:=1 to t do
 begin
  readln(f,a,b);
  writeln(f2,cmmdc(a,b));
 end;
close(f);
close(f2);
end.
