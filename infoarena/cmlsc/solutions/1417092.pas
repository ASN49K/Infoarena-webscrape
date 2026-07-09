uses math;
const
        nm=1030;
var
     dp:array[0..nm,0..nm] of longint;
     n,m,i,j,x:longint;
     a,b,sol:array[1..nm] of byte;

begin
 assign(input,'cmlsc.in'); reset(input);
 assign(output,'cmlsc.out'); rewrite(output);
   readln(n,m);
   for i:=1 to n do read(a[i]);
   for j:=1 to m do read(b[j]);
  close(input);

for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then dp[i,j]:=dp[i-1,j-1]+1 else
                     dp[i,j]:=max(dp[i-1,j],dp[i,j-1]);
i:=n;
j:=m;
x:=0;
 while (i>0)and(j>0) do
   begin
    if a[i]=b[j] then
     begin
       inc(x);
       sol[x]:=a[i];
       dec(i);
       dec(j);
     end else
           begin
            if dp[i-1,j]>dp[i,j-1] then dec(i) else dec(j);
           end;
   end;
writeln(x);
for i:=x downto 1 do write(sol[i],' ');
close(output);
end.