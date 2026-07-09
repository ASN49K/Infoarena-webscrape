program subsir;
var a,b,c:array[1..100] of integer;
    i,n,j,k,m:integer; prelucrat:array[1..100] of boolean;
procedure citire;
var f:text;
begin
  assign(f,'cmlsc.in');
  reset(f);
  readln(f,n,m);
  for i:= 1 to n do read(f,a[i]);
  readln(f);
  for j:= 1 to m do read(f,b[j]);
  close(f);
end;

procedure prelucrare;
begin
  for i:=1 to n do begin
    for j:=1 to m do
    if (a[i]=b[j]) and (not prelucrat[i]) then begin
                inc(k);
                c[k]:=a[i];
                prelucrat[i]:=true;
    end;
  end;
end;

procedure afisare;
var f:text;
begin
  assign(f,'cmlsc.out');
  rewrite(f);
  writeln(f,k);
  for i:=1 to k do write(f,c[i]:3);
  close(f);
end;

begin
citire;
prelucrare;
afisare;
end.