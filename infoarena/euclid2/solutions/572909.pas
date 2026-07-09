program cmmdc_perechidenumere;
var c,n,x,y:longint;
    d,o:text;
function cmmdc(a,b:longint):longint;
 begin
   while a<>b do
     if a<b then b:=b-a
            else a:=a-b;
   cmmdc:=a;
 end;
begin
assign(d,'euclid2.in');assign(o,'euclid2.out');
reset(d);rewrite(o);
readln(d,n);
for c:=1 to n do
  begin
    read(d,x);read(d,y);
    writeln(o,cmmdc(x,y));
  end;
close(d);close(o);
end.