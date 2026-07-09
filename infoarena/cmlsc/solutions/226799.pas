program lcs;
var A,B,C: array[1..1024] of byte;
    L: array[1..1025,1..1025] of integer;
    m,n,i,k: longint;

{returneaza numai lungimea celui
mai lung subsir comun, folosind
numai doua linii din matrice X,Y}
function cmlsc:longint;
var i,j: longint;
begin
  for i:=m downto 1 do
   for j:=n downto 1 do
   begin
     if (i=m+1) or (j=n+1) then L[i,j]:=0
     else if (A[i]=B[j]) then
             L[i,j]:=1+L[i+1,j+1]
          else
             if L[i+1,j]>L[i,j+1] then

                L[i,j]:=L[i+1,j]
             else
                L[i,j]:=L[i,j+1]
   end;
   cmlsc:=L[1,1];
end;

procedure sir;
var i,j: longint;
begin
  i:=1; j:=1; k:=0;
  while (i<=m)and(j<=n) do
    if (A[i]=B[j]) then
    begin
      inc(k);
      C[k]:=A[i];
      inc(i); inc(j);
    end
    else if L[i+1,j]>=L[i,j+1] then inc(i)
         else inc(j);
  for i:=1 to k do
    write(C[i],' ');
end;

begin
  assign(input,'cmlsc.in');
  reset(input);
  assign(output,'cmlsc.out');
  rewrite(output);
  readln(m,n);
  for i:=1 to m do
   read(a[i]);
  for i:=1 to n do
   read(b[i]);
  k:=cmlsc;
  writeln(k);
  sir;
  close(input);
  close(output);
end.