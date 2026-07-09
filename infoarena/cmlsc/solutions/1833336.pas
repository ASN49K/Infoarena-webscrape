function max(var a,b:word):word;
  begin
  if a>=b then max:=a else max:=b; end;
var fi,fo:text;
    a,b:array[1..1500] of word;
    dp:array[0..1500,0..1500] of word;
    rs:array[1..1500] of word;
    n,m,i,j,k:word;
begin
assign(fi,'cmlsc.in'); assign(fo,'cmlsc.out'); reset(fi); rewrite(fo);
readln(fi,n,m);
for i:=1 to n do read(fi,a[i]);
for i:=1 to m do read(fi,b[i]);

for i:=1 to n do
  for j:=1 to m do
        if a[i]=b[j] then dp[i,j]:=dp[i-1,j-1]+1 else dp[i,j]:=max(dp[i-1,j],dp[i,j-1]);
i:=n; j:=m; k:=0;

while (i>0) and (j>0) do
        if a[i]=b[j] then begin
                                inc(k);
                                rs[k]:=a[i];
                                dec(j);
                                dec(i);
                                end
                           else  begin
                                if dp[i-1,j]>dp[i,j-1] then
                                                        dec(i)
                                                        else
                                                        dec(j);
                                                                end;
writeln(fo,dp[n,m]);
for i:=k downto 1 do
        write(fo,rs[i],' ');


close(fi); close(fo);

end.
