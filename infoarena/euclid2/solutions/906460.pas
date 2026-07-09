program cmmdc;
var x,y,aux,nr,i:longint;
    intrare,iesire:array[1..1 shl 17] of char;
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
assign(f,'euclid2.in');reset(f); settextbuf(f,intrare);
assign(g,'euclid2.out');rewrite(g); settextbuf(g,iesire);
readln(f,nr);
for i:=1 to nr do
 begin
  readln(f,x,y);
  writeln(g,cmmdc(x,y));
 end;
close(f); close(g);
end.