Program Euclid_Optimizat;
var f1,f2:text;
    r,i,t,x,y:longint;

Function CMMDC(x,y:longint) : longint;
 var r:longint;
  begin
   while r<>0 do
    begin
     r:=x mod y;
     x:=y;
     y:=r;
    end;
   CMMDC:=x;
  end;

begin
assign(f1,'euclid2.in'); reset(f1);
assign(f2,'euclid2.out'); rewrite(f2);
readln(f1,t);
for i:=1 to t do
 begin
   readln(f1,x,y);
   r:=cmmdc(x,y);
   writeln(f2,r);
 end;

close(f1); close(f2);
end.


