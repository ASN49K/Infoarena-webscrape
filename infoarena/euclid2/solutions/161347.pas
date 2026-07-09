var a,b,t,r,i:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,t);
for i:=1 to t do begin
                 read(f,a,b);
                 repeat
                      r:=a mod b;
                      a:=b;
                      b:=r;
                 until b=0;
                 writeln(g,a);
                 end;
close(f);
close(g);
end.