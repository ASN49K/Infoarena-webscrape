var n,a,b,r,i:longint;
begin
assign(input,'euclid2.in');reset(input);
assign(output.'euclid2.out');rewrite(output);
readln(n);
 for i:=1 to n do begin
  read(a,b);
  r:=a mod b;
  while r<>0 do begin
   a:=b;b:=r;r:=a mod b;
  end;
  writeln(b);
 end;
close(input);close(output);
end.
