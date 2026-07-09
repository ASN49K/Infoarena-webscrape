var c:array[0..10000,0..10000]of integer;
    a,b:array[1..10000]of integer;
    n,m:integer;

procedure citire;
var i:integer; f:text;
begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 writeln(n,' ',m);
 for i:=1 to n do begin read(f,a[i]); write(a[i],' '); end;readln(f);
 writeln;
 for i:=1 to m do begin read(f,b[i]); write('[',i,':',b[i],'] '); end;
 close(f);
end;

procedure init;
var i,j,k,p,max:integer;f:text;
begin
 assign(f,'cmlsc.out');
 rewrite(f);
 k:=0;p:=0;max:=0;
 for i:=1 to n do c[i,0]:=0;
 for i:=1 to m do c[0,i]:=0;
 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then
    begin
     c[i,j]:=c[i-1,j-1]+1;
     if c[i,j]>max then begin max:=c[i,j]; k:=i; p:=j; end;
    end;
 writeln(f,max);
 k:=k-max+1; p:=1;
 while p<=max do
  begin
   write(f,a[k],' ');
   inc(k);inc(p);
  end;
 close(f);
end;

begin
 citire;
 init;
end.


