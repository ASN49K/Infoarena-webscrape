var c:array[0..10000,0..10000]of integer;
    a,b,d:array[1..10000]of integer;
    n,m:integer;

procedure citire;
var i:integer; f:text;
begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 randomize;
 for i:=1 to n do read(f,a[i]);
 for i:=1 to m do read(f,b[i]);
 close(f);
end;

function max(a,b:integer):integer;
begin
 if a>b then max:=a else max:=b;
end;

procedure init;
var i,j:integer;
begin
 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1 else c[i,j]:=max(c[i-1,j],c[i,j-1]);
end;

{procedure afis_mat;
var i,j:integer;
begin
 for i:=1 to n do
  begin
   for j:=1 to m do  write(c[i,j],' ');
   writeln;
  end;
end; }

procedure afis;
var i,j,k:integer; f:text;
begin
 assign(f,'cmlsc.out');
 rewrite(f);
 writeln(f,c[n,m]);
 i:=n; j:=m; k:=0;
 while c[i,j]>0 do
  begin
   while a[i]<>b[j] do
    begin
     if c[i,j-1]<c[i-1,j] then dec(i) else dec(j);
    end;
   inc(k);
   d[k]:=a[i];
   dec(i); dec(j);
  end;
 for i:=k downto 1 do write(f,d[i],' ');
 close(f);
end;

begin
 citire;
 init;
 afis;
end.


