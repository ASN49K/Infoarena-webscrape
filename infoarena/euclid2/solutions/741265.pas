var x,y,n,i,t:longint;
    f1,f2:text;
BEGIN
assign(f1,'euclid2.in');
reset(f1);
readln(f1,n);
assign(f2,'euclid2.out');
rewrite(f2);
for i:=1 to n do
  begin
    readln(f1,x,y);
    while y<>0 do
      begin
      t:=x mod y;
      x:=y;
      y:=t;
      end;
    writeln(f2,x);
  end;
Close(f1);
Close(f2);
END.


