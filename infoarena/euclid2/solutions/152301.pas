program cmmdc;
var a,b,r:Longint;
    f:text;
begin
assign(f,'euclid2.in');reset(f);
readln(f,a,b);close(f);
r:=a mod b;
while r<>0 do begin
              a:=b;
              b:=r;
              r:=a mod b;
              end;
assign(f,'euclid2.out');rewrite(f);
write(f,b);close(f);
end.
