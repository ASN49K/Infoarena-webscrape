var a,b,d:array[1..1024] of longint;
    c:array[0..1024,0..1024] of longint;
    n,i,j,k,l,m,maxi:longint;
function max(x,y:longint):longint;
begin
if x>y then max:=x
   else max:=y;
end;

begin
assign(input,'cmlsc.in');reset(input);

assign(output,'cmlsc.out');rewrite(output);
read(m);
read(N);
for i:=1 to m do read(a[i]);
for i:=1 to n do read(b[i]);
for i:=1 to m do
    for j:=1 to n do
                if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
                             else c[i,j]:=max(c[i-1,j],c[i,j-1]);
for i:=1 to n do
    maxi:=max(maxi,c[m,i]);
for i:=m downto 1 do
     for j:=1 to n do
         if (c[i,j]=maxi) and (a[i]=b[j]) then
            begin
            inc(K);
            d[k]:=a[i];
            dec(maxi);
            break;
            end;
writeln(K);
for i:=k downto 1 do write(d[i],' ');
close(input);
close(output);
end.