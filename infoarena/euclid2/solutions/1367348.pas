program euclid;
var a,b,r,t,i:longint;
    bufin,bufout:array[1..65355] of byte;
begin
  assign(input,'euclid2.in'); reset(input);
  assign(output,'euclid2.out'); rewrite(output);
  settextbuf(input,bufin);
  settextbuf(output,bufout);
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