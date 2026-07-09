var i,a,b,t,r:longint;
begin
assign(input,'euclid2.in');reset(input);
assign(output,'euclid2.out');rewrite(output);
readln(t);
for i:=1 to t do begin
  readln(a,b);
 r:=a mod b;
  while r<>0 do begin
    a:=b;
    b:=r;
    r:=a mod b; end;
  writeln(b);
end;
close(input);close(output);
end.
