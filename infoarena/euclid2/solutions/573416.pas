program cmmdc_impartire;
type vector=array [1..50000] of longint;
var n,i,d,m,r,a0,b0:longint;
    f1,f2:text;
    a,b:vector;
begin
assign(f1,'euclid2.in');
reset(f1);
assign(f2,'euclid2.out');
rewrite(f2);
readln(f1,n);
for i:=1 to n do
  readln(f1,a[i],b[i]);
close(f1);
for i:=1 to n do
  begin
  a0:=a[i];
  b0:=b[i];
  if (a[i]=0) or (b[i]=0) then
    d:=a[i]+b[i]
  else
   begin
    repeat
      r:=a0 mod b0;
      a0:=b0;
      b0:=r;
    until r=0;
    d:=a0;
   end;
   writeln(f2,d);
  end;
close(f2);
end.

