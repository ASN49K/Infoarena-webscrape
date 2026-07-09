{$s-}
program gaju;
var c:array[0..1025,0..1025]of byte;
    a,b,v:array[0..1025]of byte;
    n,m,i,j:integer;
    z:longint;
    f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,n,m);
for i:=1 to n do read(f,a[i]);
readln(f);
for i:=1 to m do read(f,b[i]);
for i:=1 to n do
    for j:=1 to m do
        if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
                     else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
                                               else c[i,j]:=c[i,j-1];
writeln(g,c[n,m]);
i:=n;j:=m;
repeat
if a[i]=b[j] then begin
             z:=z+1;
             v[z]:=a[i];
             i:=i-1;j:=j-1;
             c[n,m]:=c[n,m]-1;
             end
             else
             if c[i-1,j]>c[i,j-1] then i:=i-1
                                  else j:=j-1;
until (i<=0)or(j<=0)or(c[n,m]=0);
for i:=z downto 1 do write(g,v[i],' ');
close(f);close(g);
end.