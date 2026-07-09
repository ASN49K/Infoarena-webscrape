program p;
var
v1,v2:array [1..256] of 0..1024;
nr,i,m,n:word;
sz:byte;
f:text;

begin
assign(f,'cmlsc.in'); reset(f);
readln(f,m,n);

for i:=1 to m do
begin
 read(f,sz);
 inc(v1[sz]);
end;

for i:=1 to n do
begin
 read(f,sz);
 inc(v2[sz]);
 if v1[sz]<v2[sz] then inc(nr,v1[sz]) else inc(nr,v2[sz]);
end;

close(f); assign(f,'cmlsc.out'); rewrite(f);

writeln(f,nr);

for i:=1 to 256 do
 while (v1[i]>0) and (v2[i]>0) do
 begin
  write(f,i,' ');
  dec(v1[i]);
  dec(v2[i]);
 end;

close(f);
end.