type vector=array[1..1024] of integer;
var n,i,j,m,ct,k,max,h,v,z:integer;
    p:boolean;
    a:vector;
    b:vector;
    c:vector;
    d:vector;
    f:text;
begin
assign(f,'cmlsc.in'); reset(f);
readln(f,m,n); ct:=0;  max:=0;  k:=0; v:=0;
for i:=1 to m do
read(f,a[i]);
for i:=1 to n do
read(f,b[i]);
close(f);
for i:=1 to m do
begin
p:=false;
 for j:=ct+1 to n do
 if a[i]=b[j] then begin
       p:=true;
       inc(ct);
       c[ct]:=a[i];
             break;
             end;
if (j>k) and (p) then begin  z:=v+1;
                             d[z]:=a[i];
                             end
                      else ct:=0;
if ct>max then begin for h:=1 to ct do
d[h]:=c[h];
max:=ct;
k:=j;  v:=ct;
end;
end;
assign(f,'cmlsc.out'); rewrite(f);
if z>ct then ct:=z;
writeln(f,ct);
for i:=1 to ct do
write(f,d[i],' ');
close(f);
end.