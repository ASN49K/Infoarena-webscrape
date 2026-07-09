program algortim;
var f,g:text;
    t:longint;
    x,y,r,i:longint;
begin
assign(f,'euclid2.in');reset(f);readln(f,t);
assign(g,'euclid2.out');rewrite(g);
for i:=1 to t do begin
                 readln(f,x,y);
                 if x<y then begin
                             r:=x;
                             x:=y;
                             y:=r;
                             end;
                 r:=0;
                 repeat
                 r:=x mod y;
                 x:=y;
                 y:=r;
                 until r=0;
                 writeln(g,x);
                 end;
close(f);close(g);
end.