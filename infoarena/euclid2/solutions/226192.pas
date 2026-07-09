program euclid2;
var a,b,d,i,t: longint;
begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  readln(t);
  for i:=1 to t do
  begin
    readln(a,b);
    repeat
      d:=a mod b;
      a:=b;
      b:=d;
    until d=0;
    writeln(a);
  end;
  close(input);
  close(output);
end.