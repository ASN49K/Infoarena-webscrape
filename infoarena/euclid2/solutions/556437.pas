uses crt;
var
 a,b,c,d,i,j,m,n:longint;
 f,g:text;
begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,n);
 for i:=1 to n do
  begin
   readln(f,a,b);
   if a>b then
    begin c:=a;d:=b; end
    else begin c:=b;d:=a; end;
   while c mod d<>0 do
     begin
      m:=d;
      d:=c mod d;
      c:=m;
     end;
   writeln(g,d);
  end;
 close(f);
 close(g);
end.