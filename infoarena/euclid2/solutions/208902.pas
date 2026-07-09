var t,a,b,c,r:longint;
    ok:boolean;
    f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
readln(f,t);
assign(g,'euclid2.out');
rewrite(g);
while not eof(f) do begin
readln(f,a,b);
ok:=true;
while ok do begin
              r:=a mod b;
              if r=0 then ok:=false;
              a:=b;
              b:=r;
              end;
writeln(g,a);
end;
end.
