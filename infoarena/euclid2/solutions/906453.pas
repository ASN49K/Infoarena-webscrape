program cmmdc;
var x,y,aux,nr,i:longint;
    f,g:text;

function cmmdc(var x,y:longint):longint;
begin
if (y=0)then cmmdc:=x
        else begin
             x:=x mod y;
             cmmdc:=cmmdc(y,x);
             end;
end;

begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,nr);
for i:=1 to nr do
 begin
  readln(f,x,y);
  aux:=cmmdc(x,y);
  if aux=1 then writeln(g,0)
           else writeln(g,aux);
 end;
close(f); close(g);
end.