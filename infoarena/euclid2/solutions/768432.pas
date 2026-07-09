program euclid2;
var fi,fo:text;
  a,b,r:longint;
begin
assign(fi,'euclid2.in');reset(fi);
assign(fo,'euclid2.out');rewrite(fo);
read(fi,n);
for i:=1 to n do begin
                readln(fi,a,b);
                repeat r:=a mod b;
                a:=b;b:=r;until r=0;
                writeln(fo,a);
                end;
                close(fi);close(fo);
end.
