var a,b,v:array[1..1024] of 1..256;
t:array[1..1024,1..1024] of byte;
m,n,i,j,x:word;
f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);rewrite(g);
readln(f,m,n);
for i:=1 to m do
    read(f,a[i]);
readln(f);
for i:=1 to n do
    read(f,b[i]);
for i:=1 to m do
    for j:=1 to n do
        if a[i]=b[j] then
           t[i,j]:=t[i-1,j-1]+1
        else
            if t[i-1,j]>t[i,j-1] then
               t[i,j]:=t[i-1,j]
            else
                t[i,j]:=t[i,j-1];
i:=m;j:=n;
repeat
      if a[i]=b[j] then
         begin
         x:=x+1;
         v[x]:=a[i];
         i:=i-1;
         j:=j-1;
         end
      else
          if t[i-1,j]>t[i,j-1] then
             i:=i-1
          else
              j:=j-1;
until t[i,j]=0;
writeln(g,x);
for i:=x downto 1 do
    write(g,v[i],' ');
close(f);close(g);
end.