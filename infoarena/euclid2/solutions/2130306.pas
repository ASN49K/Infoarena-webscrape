program euclid;
var a,b,c:longint;
fi,fo:text;
begin
assign (fi,'euclid2.in'); reset(fi);
assign (fo,'euclid2.out'); rewrite(fo);
read (fi,a,b);
while b<>0 do begin
c:=a mod b;
a:=b;
b:=c;
end;
write (fo,a);
close(fi);
close(fo);
end.

