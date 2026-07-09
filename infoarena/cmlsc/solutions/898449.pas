program fdgfdg;
var f,g:text;
a,b,rez:array[1..1024] of integer;
n,m,i,j,k:integer;
cost:array[0..1024,0..1024] of integer;
function max(x,y:longint):longint;
begin
if x>y then max:=x else max:=y;
end;
begin
assign(f,'cmscl.in'); reset(f);
assign(g,'cmscl.out'); rewrite(g);
readln(f,m,n);
  for i:=1 to m do
     read(f,a[i]);
     readln(f);
     for j:=1 to n do
        read(f,b[j]);
     for i:=1 to m do
         for j:=1 to n do
            begin
                if a[i]=b[j] then
                   cost[i,j]:=cost[i-1,j-1]+1
                   else
                   begin
                   cost[i,j]:=cost[i-1,j];
                   if cost[i,j-1]>cost[i,j] then
                     cost[i,j]:=cost[i,j-1];
                   end;
            end;

     writeln(g,cost[m,n]);
     i:=m; j:=n;
        For k:=cost[m,n] downto 1 do
          begin
             while cost[i,j]=cost[i-1,j] do
             i:=i-1;
             while cost[i,j]=cost[i,j-1] do j:=j-1;
             rez[k]:=a[i];
             i:=i-1;
          end;
     for i:=1 to cost[m,n] do
        write(g,rez[i],' ');
close(f);
close(g);
end.