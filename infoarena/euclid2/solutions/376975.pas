var f,g:text;
    i,n,a,b:longint;

function euclid(x,y:longint):longint;
var r:longint;
begin
 while y>0 do begin
   r:=x mod y;
   x:=y;
   y:=r;
 end;
 euclid:=x;
end;

begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,n);
 for i:=1 to n do begin
    readln(f,a,b);
    writeln(g,euclid(a,b));
 end;
 close(f);
 close(g);

end.