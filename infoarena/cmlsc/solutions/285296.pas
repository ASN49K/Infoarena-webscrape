program suma;
const fin = 'cmlsc.in';
      fout = 'cmlsc.out';
var i,j,k,m,n:integer;
    sol,a,b:array [1..1024] of byte;
    l:array [0..1024,0..1024] of byte;

function max(t1,t2:byte):byte;
begin
  max:=t1;
  if t2>t1 then
    max:=t2;
end;

begin
  assign(input,fin);
  assign(output,fout);
  reset(input);
  rewrite(output);
  fillchar(l,sizeof(l),0);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);

  readln(m,n);
  for i:=1 to m do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  for i:=1 to n do
    for j:=1 to m do
      if b[i] = a[j] then
        l[i,j]:=1+l[i-1,j-1]
      else
        l[i,j]:=max(l[i-1,j],l[i,j-1]);

   writeln(l[n,m]);
   i:=n;
   j:=m;
   k:=0;
   while l[i,j] > 0 do
     if b[i] = a[j] then
     begin
       inc(k);
       sol[k]:=b[i];
       dec(i);
       dec(j);
     end
     else
      if max(l[i-1,j],l[i,j-1]) = l[i-1,j] then
        dec(i)
      else
        dec(j);
   for i:=k downto 1 do
     write(sol[i],' ');
   writeln;

  close(input);
  close(output);
end.
