const tfi='euclid2.in';
      tfo='euclid2.out';
var   fi,fo:text;
  n:longint;

function find(a,b:longint):longint;
begin
  if a=0 then exit(b) else
  if b=0 then exit(a);
  if a>b then exit(find(a mod b,b)) else exit(find(a,b mod a));
end;

procedure process;
var a,b,i:longint;
begin
  read(fi,n);
  for i:=1 to n do
   begin
    read(fi,a,b);
    writeln(fo,find(a,b));
   end;
end;

begin
  assign(fi,tfi); reset(fi);
  assign(fo,tfo); rewrite(fo);
  process;
  close(fi); close(fo);
end.