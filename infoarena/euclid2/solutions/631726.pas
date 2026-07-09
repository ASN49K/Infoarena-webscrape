program euc2;
var f,t:text;
    x,y:int64;
    n,i:integer;
begin
  assign(f,'euclid2.in');
  reset(f);
  read(f,n);
  readln(f);
  assign(t,'euclid2.out');
  rewrite(t);
  for i:=1 to n do
    begin
      readln(f,x,y);
      repeat
        if x<>y then
        if x<y then y:=y-x
               else x:=x-y;
      until x=y;
      writeln(t,x);
    end;
  close(f);close(t);
end.
