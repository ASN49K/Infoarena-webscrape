program gaju;
var f,g:text;
    n,m,i,j,k,poz:integer;
    w,v,ki:array[1..1024]of byte;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,n,m);
for i:=1 to n do read(f,v[i]);
for i:=1 to m do read(f,w[i]);
k:=0;poz:=1;
for i:=1 to n do begin
    for j:=poz to m do
        if v[i]=w[j]then begin
                         k:=k+1;
                         ki[k]:=v[i];
                         poz:=j;
                         break;
                         end;
end;
writeln(g,k);
for i:=1 to k do write(g,ki[i],' ');
close(g);
end.