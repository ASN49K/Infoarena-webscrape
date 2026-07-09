program p1;
var a,b,k:array[0..1024] of integer;
    f,g:text;
    c:array[0..1024,0..1024] of integer;
    i,n,m,j,u,l:longint;
function max(o1,o2:integer):integer;
begin
if o1>o2 then max:=o1
        else max:=o2;
end;
begin
assign(f,'cmlsc.in');reset(F);
assign(g,'cmlsc.out');rewrite(G);
readln(f,n,m);
for i:=1 to n do read(f,a[i]);
readln(f);
for i:=1 to m do read(f,b[i]);
for i:=1 to n do c[i,0]:=0;
for i:=1 to m do c[0,j]:=0;
for i:=1 to n do
        for j:=1 to m do
                if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
                        else  c[i,j]:=max(c[i-1,j],c[i,j-1]);
i:=n;
j:=m;
while c[i,j]<>0 do begin
        if a[i]=b[j] then begin
                        k[c[i,j]]:=a[i];
                        dec(i);
                        dec(j);
                          end
                          else
                          if c[i-1,j]>c[i,j-1] then i:=i-1
                                        else j:=j-1;
                        end;
writeln(g,c[n,m]);
for i:=1 to c[n,m] do write(g,k[i],' ');
close(F);
close(G);
end.