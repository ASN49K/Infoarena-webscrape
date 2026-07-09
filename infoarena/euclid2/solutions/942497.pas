Program euclid;
var t,i:1..100000;
    a,b:2..2000000000;
    m,cmmdc:1..2000000000;
    intrare,iesire:text;
begin
assign(intrare,'euclid2.in');
assign(iesire,'euclid2.out');
reset(intrare);
rewrite(iesire);
readln(intrare,t);
for i:=1 to t do
  begin
    readln(intrare,a,b);
    for m:=1 to a do
       begin
         if (a mod m=0) and (b mod m=0) then cmmdc:=m;
       end;
    writeln(iesire,cmmdc);
  end;
close(intrare);
close(iesire);
end.