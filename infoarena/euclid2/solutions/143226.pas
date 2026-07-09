var a,b,r:longint;
begin
assign(input,'euclid2.in');reset(input);
assign(output,'euclid2.out');rewrite(output);
read(a,b);r:=a mod b;
 while r<>0 do begin
  a:=b;b:=r;r:=a mod b;
 end;
close(input);close(output);
end.