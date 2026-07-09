program Euclid;
type qw=array[1..100000] of longint;
var
a,b:qw;
r,n,i:longint;
f,g:text;

function euclid(u, v: longint): longint;
  begin
    if u mod v <> 0 then
        euclid := euclid(v, u mod v)
    else
        euclid := v;
  end;


begin
assign(f,'euclid2.in'); reset(f);
readln(f,n);
for i:=1 to n do
read(f,a[i],b[i]);
close(f);
assign(g,'euclid2.out'); rewrite(g);
for i:=1 to n do
writeln(g,euclid(a[i],b[i]));
close(g);
end.