var x,y,n,i,t:longint;

BEGIN
assign(input,'euclid2.in');
reset(input);
readln(n);
assign(output,'euclid2.out');
rewrite(output);
for i:=1 to n do
  begin
    readln(x,y);
    while y<>0 do
      begin
      t:=x mod y;
      x:=y;
      y:=t;
      end;
    writeln(x);
  end;
Close(input);
Close(output);
END.


