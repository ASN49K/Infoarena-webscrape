program arhiva001;
type tip1=0..1024;
var a,b:array of byte;
    c:array of byte;
    v:array of array of tip1;
    m,n,i,j,k:tip1;

function max(a,b:tip1):tip1;
begin
 if a>b then max:=a
        else max:=b;
end;

begin
 assign(input,'cmlsc.in');
 reset(input);
 read(m); readln(n);
 setlength(a,m+1);
 setlength(b,n+1);
 setlength(v,m+1);
 for i:=0 to m do
  setlength(v[i],n+1);
 for i:=1 to m do read(a[i]); readln;
 for j:=1 to n do read(b[j]);
 close(input);
 {1}
 for i:=1 to m do
  for j:=1 to n do
   if a[i]=b[j] then v[i,j]:=v[i-1,j-1]+1
                else v[i,j]:=max(v[i-1,j],v[i,j-1]);
 {2}
 assign(output,'cmlsc.out');
 rewrite(output);
 k:=v[m,n];
 j:=k;
 writeln(k);
 setlength(c,k+1);
 {3}
 while m*n<>0 do
  if a[m]=b[n] then
    begin c[k]:=a[m];
          m:=m-1;
          n:=n-1;
          k:=k-1;
    end
               else
         if v[m-1,n]<v[m,n-1] then n:=n-1
                              else m:=m-1;

 for i:=1 to j do
  write(c[i],' ');

 close(output);
end.
