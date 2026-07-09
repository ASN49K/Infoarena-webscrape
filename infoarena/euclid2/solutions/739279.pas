var f,g:text;
a,b:int64;
i,t:longint;
function cmmdc(a,b:int64):int64;
var r:int64;
begin
 r:=1;
  while r<>0 do
   begin
   r:=a mod b;
   a:=b;
   b:=r;
   end;
   cmmdc:=a;
end;


begin
assign(f,'euclid2.in');  reset(f);
assign(g,'euclid2.out');  rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
writeln(g,cmmdc(a,b));

end;

close(f); close(g);

end.