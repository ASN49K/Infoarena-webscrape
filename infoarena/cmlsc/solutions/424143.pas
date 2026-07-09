program CMLSC;
type vektor = array[1..1024] of integer;
      bvekt = array[0..256] of byte;
var a,b:vektor;
    t:bvekt;
    be,ki:text;
    m,n:integer;
    suf:array[1..1024,1..1024] of integer;

procedure olvas;
var i,j:integer;
     x:integer;
begin
 readln(be,n,m);
 for i:=1 to n do
   begin
    read(be,a[i]);
    t[ a[i] ]:= $0F;
   end;
 j:=0;
 for i:=1 to m do
   begin
    read(be,x);
    if t[x] <> 0 then
        begin
         inc(j);
         b[j]:=x;
         t[x]:=$ff;
        end;
   end;
 m:=j;
 j:=0;
 for i:=1 to n do
   if t[ a[i] ] = $ff then
      begin
       inc(j);
       a[j]:=a[i];
      end;
 n:=j;
end;

procedure kiir(i,j:integer);
var v:array[1..1024] of byte;
    vn:integer;
begin
 vn:=0;
 while (j > 0)and(i > 0) do
  begin
    if (a[i]=b[j]) then
       begin
        inc(vn);
        v[vn] := a[i];
	dec(i);
	dec(j)
       end
	    else
       begin
	if suf[i-1,j] < suf[i,j-1] then
             dec(j)
            else dec(i);
       end;
  end;
 writeln(ki,vn);
 for i:=vn downto 1 do write(ki,v[i],' ');
end;

function max(a,b:longint):longint;inline;
begin
 if a>b then max:=a
   else max:=b;
end;

procedure csinal;
var Mi,Mj,i,j:longint;
begin
 mi:=0; mj:=0;
 for i:=1 to n do
  for j:=1 to m do
     if a[i]=b[j] then
       begin
        suf[i,j]:=suf[i-1,j-1] + 1;
        if suf[i,j] > suf[mi,mj] then
              begin
               mi:=i;
               mj:=j;
              end;
       end
          else
            suf[i,j]:=max( suf[i-1,j], suf[i,j-1] ) ;

 kiir(mi,mj);
end;

begin
 assign(be,'cmlsc.in');
 assign(ki,'cmlsc.out');
 reset(be);
 rewrite(ki);
 olvas;
 csinal;
 close(ki);
end.
