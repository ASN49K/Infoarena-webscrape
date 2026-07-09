program euclid;
var a,b,r,t,i:longint;
begin
  assign(input,'euclid2.in'); reset(input);
  assign(output,'euclid2.out'); rewrite(output);
  readln(t);
  for i:=1 to t do
    begin
      readln(a,b);
      repeat
        r:=a mod b;
        a:=b;
        b:=r;
      until r=0;
      writeln(a);
    end;
  close(input); close(output);
end.