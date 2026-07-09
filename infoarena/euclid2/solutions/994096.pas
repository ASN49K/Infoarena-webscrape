program pas;
var a,b,T,i:longint; f,g:text;
begin
 assign(f,'euclid2.in'); reset(f);
 assign(g,'euclid2.out'); reset(g); rewrite(g);
 readln(f,T);
 for i:=1 to T do begin
  readln(f,a,b);
  while a<>b do
   if a>b then a:=a-b
          else b:=b-a;
  writeln(g,a);
 end;
 if a<0 then writeln(g,'0');
 close(f); close(g);
end.

