const infile='cmlsc.in';
  outfile='cmlsc.out';
  maxn=1027;
var a,b:array[1..maxn]of byte;
  d:array[0..maxn,0..maxn]of integer;
  sir:array[1..maxn]of integer;
  n,m,nr:integer;

 procedure citire;
 var i:integer;
 begin
   assign(input,infile); reset(input); readln(n,m);
   for i:=1 to n do read(a[i]);
   for i:=1 to m do read(b[i]);
   close(input);
 end;

 function max(x,y:integer):integer;
 begin
   if(x>y)then max:=x
   else max:=y;
 end;

 procedure solve;
 var i,j:integer;
 begin
   for i:=1 to n do d[i,0]:=0;
   for i:=1 to m do d[0,i]:=0;
   for i:=1 to n do
    for j:=1 to m do
      if(a[i]=b[j])then d[i,j]:=d[i-1,j-1]+1
      else d[i,j]:=max(d[i-1,j],d[i,j-1]);
 end;

 procedure scrie;
 var i,j:integer;
 begin
   i:=n; j:=m;
   while(i<>0)and(j<>0)do begin
     if(a[i]=b[j])then begin
       inc(nr); sir[nr]:=a[i]; dec(i); dec(j);
       end
     else if(d[i-1,j]<d[i,j-1])then dec(j)
       else dec(i);
     end;
   assign(output,outfile); rewrite(output);
   writeln(nr);
   for i:=nr downto 1 do write(sir[i],' ');
   close(output);
 end;

begin
  citire; solve; scrie;
end.


