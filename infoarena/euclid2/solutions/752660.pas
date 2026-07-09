program algortim;
var f,g:text;
    t:longint;
    x,y,r,i,aux:longint;
begin
assign(f,'euclid2.in');reset(f);readln(f,t);
assign(g,'euclid2.out');rewrite(g);
r:=0;
for i:=1 to t do begin
                 readln(f,x,y);
                 while y<>0 do begin
                               aux:=y;
                               y:=x mod y;
                               x:=aux;
                               end;
                 writeln(g,x);
                 end;
close(f);close(g);
end.
