var v,w,a :array[1..1024] of longint;
    f,g :text;
    n,m,i,max,j,u :longint;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m); readln(f);
for i:=1 to n do read(f,v[i]);
readln(f); max:=0;
for i:=1 to m do read(f,w[i]);
for i:=1 to n do
    for j:=1 to m do if v[i]=w[j] then begin
                                       max:=max+1;
                                       a[max]:=v[i];
                                       for u:=i to n do v[u]:=v[u+1];
                                       n:=n-1;
                                       for u:=j to m do w[u]:=w[u+1];
                                       m:=m-1;
                                       end;
writeln(g,max);
for i:=1 to max do write(g,a[i],' ');
close(g);
end.