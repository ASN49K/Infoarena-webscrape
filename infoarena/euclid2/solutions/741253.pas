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
      t:=y;
      y:=x mod y;
      x:=t;
      end;
    writeln(x);
  end;

{for i:=1 to n do
  begin
    readln(x,y);
    while x<>y do
      if x>y
        then
          x:=x-y
        else
          y:=y-x;
  writeln(x);
  end;         }
Close(input);
Close(output);
END.


