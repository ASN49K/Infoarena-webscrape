var f,g:text;
    i,j,k,y,u:longint;
    a,b,c:array[1..1240]of longint;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
readln(f,u,y);
for i:=1 to u do
    read(f,a[i]);
readln(f);
for i:=1 to y do
    read(f,b[i]);
for i:=1 to u do
    for j:=1 to y do
        if a[i]=b[j] then begin
                          k:=k+1;
                          c[k]:=a[i];
                          end;
writeln(g,k);
for i:=1 to k do
write(g,c[i],' ');
close(g);
end.
