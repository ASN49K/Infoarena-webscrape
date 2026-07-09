var a,b,q:array[1..1024]of byte;
c:array[0..1024,0..1024]of byte;
f,g:text;
i,j:integer;
p,m,n:integer;
function max(x,y:integer):integer;
begin
if x>y then max:=x
    else max:=y;
end;
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,m,n);
for i:=1 to m do
read(f,a[i]);
for i:=1 to n do
read(f,b[i]);
for i:=1 to m do
  for j:=1 to n do
     if a[i]=b[j]then c[i,j]:=c[i-1,j-1]+1
           else c[i,j]:=max(c[i-1,j],c[i,j-1]);
p:=c[m,n];
i:=m;
j:=n;
q[p]:=a[m];
while p>0 do
begin
if c[i-1,j-1]=p-1 then begin dec(i); dec(j);q[p]:=b[j+1];dec(p); end
        else
              if c[i,j]=c[i-1,j]+1 then dec(i)
                     else dec(j);
    end;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,c[m,n]);
for i:=1 to c[m,n] do
write(g,q[i],' ');
close(g);
close(f);
end.