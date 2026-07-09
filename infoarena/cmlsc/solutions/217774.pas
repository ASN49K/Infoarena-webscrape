program Cmlsc;
var
  fl : text;
  n,i,j,k,m:integer;
  a, b, s : array[1..1024] of integer;
  d : array[1..1024,1..1024] of integer;

function max(in1,in2:integer):integer;
begin
   max := in1;
   if in1 < in2 then
      max := in2;
end;
begin
   assign(fl,'cmlsc.in');
   reset(fl);
   readln(fl,n,m);
   for i := 1 to n do
      read(fl,a[i]);
   for i := 1 to m do
      read(fl,b[i]);
   close(fl);


   k := 0;
   for i := 1 to n do
     for j := 1 to m do
        if a[i] = b[j] then
              begin
              d[i,j] := d[i-1,j-1] + 1;
               k := k+1;
               s[k] := a[i];
               end
        else
           d[i,j] := max(d[i-1,j],d[i,j-1]);

   assign(fl,'cmlsc.out');
   rewrite(fl);
   writeln(fl,k);
   for i := 1 to k do
      write(fl,s[i],' ');
   close(fl);
end.
