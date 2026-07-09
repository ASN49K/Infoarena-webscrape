var a:array[1..100000,1..2] of longword;
buf1: array[1..1 shl 10] of char;
fi: text;
r, i, n, j:longint;
begin
assign(fi,'euclid2.in');
assign(output,'euclid2.out');
reset(fi);
rewrite(output);
settextbuf(fi,buf1);
readln(fi, n);
for i:=1 to n do
for j:=1 to 2 do
read(fi, a[i,j]);
for i:=1 to n do
begin
r:=a[i,1] mod a[i,2];
while r<>0 do
begin
a[i,1]:=a[i,2];
a[i,2]:=r;
r:=a[i,1] mod a[i,2];
end;
writeln(a[i,2]);
end;
close(input);
close(output);
end.