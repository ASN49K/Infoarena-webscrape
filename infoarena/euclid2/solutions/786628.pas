program finfo;
var t,i,d,a,b,l:longint;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out'); rewrite(output);
readln(t);
for i:=1 to t do begin
  readln(a,b);
  if (b>a) then
   begin
      d:=a;
      a:=b;
      b:=d;
   end;
      while (b<>0) do
      begin
         l:=a mod b;
         a:=b;
         b:=l;
      end;
   writeln(a)
end;
close(output);
end.
