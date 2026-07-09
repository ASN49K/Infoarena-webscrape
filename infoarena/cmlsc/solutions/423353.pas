program CMLSC;
type vektor = array[1..1024] of byte;
var a,b,mg:vektor;
    r:array[0..255] of byte;
    n,m,mgn:integer;
    ki,be:text;
    
procedure olvvekt(var a:vektor;n:integer);
var i:integer;
begin
 for i:=1 to n do
     read(be,a[i]);
end;
    
procedure olvas;
var i:integer;
begin
 readln(be,n,m);
 if n > m then
    begin
     olvvekt(a,n);
     olvvekt(b,m);
    end
     else
    begin
     olvvekt(b,n);
     olvvekt(a,m);
     i:=n;
     n:=m;
     m:=i;
    end;
end;

procedure szamol;
var i:integer;
begin
 for i:=1 to m do
     inc( r[ b[i] ] );
 for i:=n downto 1 do
    if r[ a[i] ] > 0 then
       begin
         inc(mgn);
         mg[mgn]:= a[i];
         while b[m] <> a[i] do
           begin
            dec(r[ b[m] ]);
            dec(m);
            if m=0 then exit;
           end;
       end;
end;

procedure kiir;
var i:integer;
begin
 writeln(ki,mgn);
 for i:=mgn downto 1 do write(ki,mg[i],' ');
end;

begin
 assign(be,'cmlsc.in');
 assign(ki,'cmlsc.out');
 reset(be);
 rewrite(ki);
 olvas;
 szamol;
 kiir;
 close(ki);
end.
