var a,b,t,c:int64; i:longint;
    fi,fo:text;
begin
assign (fi,'euclid2.in'); reset(fi);
assign (fo,'euclid2.out'); rewrite(fo);
read(fi,t);
for i:=1 to t do begin
read (fi,a,b);
c:=0;
while b<>0 do begin
c:=a mod b;
a:=b;
b:=c;
end;
writeln (fo,a);
end;
close(fi);
close(fo);
end.