function gdc(a,b:integer):integer;
begin if b = 0 then gdc:=a
else gdc:=gdc(b,a mod b) end;

var f,g:text;
    i,j,k,l,m,n:longint;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);

read(f,n);
for i:=1 to n do
 begin
 read(f,k,l);
 writeln(g,gdc(k,l));
 end;

writeln(gdc(66,88));

close(f);
close(g);
end.