var i,x,y,n,aux:longint;
    f,g:text;

function cmmdc(x,y:longint):longint;
 var aux:longint;
   begin
    while y<>0 do
     begin
      aux:=y;
      y:=x mod y;
      x:=aux;
     end;
    end;

begin              ;
assign(f,'euclid2.in');assign(g,'euclid2.out');reset(f);rewrite(g);
readln(f,n);
for i:=1 to n do
 begin
  readln(f,x,y);
  writeln(g,cmmdc(x,y));
  end;
close(f);
close(g);
end.
