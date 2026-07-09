{DINH QUANG DAT TIN 07-10}
{CMLSC}
CONST
 TFI='cmlsc.in';
 TFO='cmlsc.out';
 MAX=2001;
TYPE
 arr1int=array[0..MAX] of integer;
VAR
 fi,fo:text;
 res,m,n:longint;
 d,a,b:arr1int;
 f:array[0..MAX] of arr1int;
 posa,posb:array[0..MAX,0..256] of integer;

PROCEDURE       input;
var
 i:longint;
begin
 assign(fi,tfi);reset(fi);
  read(fi,m,n);
  for i:=1 to m do read(fi,a[i]);
  for i:= 1 to n do read(fi,b[i]);
 close(fi);
end;

PROCEDURE       init;
var
 i:longint;
begin
 res:=0;
 for i:= m downto 1 do
  begin
   posa[i]:=posa[i+1];
   posa[i][a[i]]:=i;
  end;

 for i:= n downto 1 do
  begin
   posb[i]:=posb[i+1];
   posb[i][b[i]]:=i;
  end;
end;

FUNCTION        smax(x,y:longint):longint;
begin
 if x<y then exit(y);
 exit(x);
end;

PROCEDURE       go(i,j1,j2:longint);
var
 c:longint;
begin
 if i=0 then exit;
 for c:= 0 to 256 do
  if f[posa[j1][c],posb[j2][c]]=i then
   begin
    d[i]:=c;
    go(i-1,posa[j1][c]+1,posb[j2][c]+1);
    exit;
   end;
end;

PROCEDURE       process;
var
 i,j:longint;
begin
 for i:=m downto 1 do
  for j:= n downto 1 do
   if a[i]=b[j] then f[i][j]:=f[i+1][j+1]+1
    else f[i][j]:=smax(f[i][j+1],f[i+1][j]);
 res:=f[1][1];
 go(res,1,1);
end;

PROCEDURE       output;
var
 i:longint;
begin
 assign(fo,tfo);rewrite(fo);
  writeln(fo,res);
  for i:= res downto 1 do write(fo,d[i],' ');
 close(fo);
end;

BEGIN
 input;
 init;
 process;
 output;
END.