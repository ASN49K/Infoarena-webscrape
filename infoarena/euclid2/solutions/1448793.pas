program finfo;
var t,i,d,a,b,l:longint;
    f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,t);
for i:=1 to t do begin
  readln(f,a,b);
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
   writeln(g,a);
end;
close(output);
end.
