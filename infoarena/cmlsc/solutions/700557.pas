type matrice=array[0..1025,0..1025] of word;
     vector=array[1..1025]of word;
var f:text;
    v,s1,s2:vector;
    i,j:word;
    a:matrice;
    n,m,x:word;
procedure citire(n:word;var s1:vector);
var i:word;
begin
for i:=1 to n do
read(f,s1[i]);
end;
procedure construire(i,j:word;var v:vector;var x:word);
begin
if a[i,j]>0 then if s1[i]=s2[j] then  begin x:=x+1;
                                     v[x]:=s1[i];
                                    construire(i-1,j-1,v,x);end
                                else if a[i-1,j]>a[i,j-1] then construire(i-1,j,v,x)
                                                          else construire(i,j-1,v,x)
            ; end;
function max(x,y:word):word;
begin
if x>y then max:=x
      else max:=y;
      end;
begin
assign(f,'cmlsc.in');reset(f);
readln(f,n,m);
citire(n,s1);
citire(m,s2);
for i:=1 to n do
for j:=1 to m do
if s1[i]=s2[j] then  a[i,j]:=a[i-1,j-1]+1
                    else begin a[i,j]:=max(a[i-1,j],a[i,j-1]);
                                                    end;


x:=0;

  close(f);
assign(f,'cmlsc.out');rewrite(f);
construire(n,m,v,x);
writeln(f,a[n,m]);
for i:= a[n,m] downto 1 do
write(f,v[i],' '); close(f);

   end.


