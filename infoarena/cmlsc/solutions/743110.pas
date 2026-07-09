program subsircomun;
var n,m,i,j,l,k:integer;
    c:array[0..1024,0..1024] of integer;
    x,y,s:array[1..1024] of byte;
function max(a,b:integer):integer;
begin
if a>b then max:=a else max:=b;
end;
begin
assign(input,'cmlsc.in'); reset(input);
assign(output,'cmlsc.out'); rewrite(output);
readln(n,m);
for i:=1 to n do read(x[i]);
readln;
for i:=1 to m do read(y[i]);
close(input);
for i:=1 to n do
        for j:=1 to m do
                if x[i]=y[j] then
                             c[i,j]:=c[i-1,j-1]+1
                             else
                             c[i,j]:=max(c[i,j-1],c[i-1,j]);
l:=c[n,m];
writeln(l);
i:=n; j:=m; k:=0;
while k<l do begin
             if x[i]=y[j] then begin
                               k:=k+1;
                               s[k]:=x[i];
                               end;
             if c[i-1,j]>=c[i,j-1] then i:=i-1
                                   else j:=j-1;
             end;
for i:=l downto 1 do write(s[i],' ');
close(output);
end.

