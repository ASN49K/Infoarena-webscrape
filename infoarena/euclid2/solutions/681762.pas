program fracti;
var p,q,n,nr:longint;
    f,g:text;
begin
assign(f,'fractii.in');
reset(f);
assign(g,'fractii.out');
rewrite(g);
read(f,n);
nr:=0;
p:=1;
  while p<=n do
  begin
  q:=1;
       while q<=n do begin
       if (p mod q<>0) then nr:=nr+1;
       q:=q+1;
       end;
  p:=p+1;
  end;
write(g,nr);
close(f);close(g);
end.

