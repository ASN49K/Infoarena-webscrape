var v,v2:array[0..1200]of integer;
    j,i,n,max,k,x,m:longint;
begin
assign(input,'cmlsc.in');reset(input);
assign(output,'cmlsc.out');rewrite(output);
read(n,m); max:=0;
 for i:=1 to n do begin
  read(x);
  j:=1;
  while (j<=i-1)and(v[j]<=x) do inc(j);
  for k:=i-1 downto j do v[k+1]:=v[k];
  v[j]:=x;
 end;
 for i:=1 to m do begin
  read(x);
  j:=1;
  while (j<=i-1)and(v2[j]<=x) do inc(j);
  for k:=i-1 downto j do v2[k+1]:=v2[k];
  v2[j]:=x;
 end;
 i:=0;j:=0;k:=0;
 while (i<=n)and(j<=m) do begin
  if v[i]=v2[j] then begin inc(i);inc(j);inc(k);end
                else
   if v[i]>v2[j] then begin inc(j);max:=(max+k+abs(max-k))div 2;k:=0;end
                else begin inc(i);max:=(max+k+abs(max-k))div 2;k:=0;end;

 end;
max:=(max+k+abs(max-k))div 2;

writeln(max);
close(input);close(output);
end.
