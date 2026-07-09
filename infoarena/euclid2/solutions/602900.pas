program algorritmul_lui_euclid;
var
 n,a,b,c,i:integer;
 f,g:text;
begin
 assign(f,'euclid2.in');
 assign(g,'euclid2.out');
 reset(f);
 read(f,n);
 rewrite(g);
 for i:=1 to n do
  begin
   read(f,a);
   read(f,b);
   c:=a;
   if b mod c<>0 then
    repeat
    c:=c-1;
    until (a mod c=0) and (b mod c=0);
   writeln(g,c);
  end;
 close(f);
 close(g);
end.