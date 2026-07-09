var a,b,r,t:longint;
    f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,t);
repeat
  t:=t-1;
  read(f,a,b);
  r:=a mod b;
  while r<>0 do  begin
   a:=b;
   b:=r;
   r:= a mod r;
    end;
   writeln(g,b);
until t=0;
close(g);
close(f);
end.


