program Cmlsc;
type vec=array[1..1024] of integer;
     mat=array[0..1025,0..1025] of integer;

var a,b:vec; lcs:mat;
    f,g:text;
    na,nb,i,j:integer;
procedure rezolva();
begin
 for i:=1 to na do
  for j:=1 to nb do
   if (a[i]=b[j])
    then
     lcs[i,j]:=lcs[i-1,j-1] + 1
    else
     if lcs[i-1,j]>lcs[i,j-1]
       then
        lcs[i,j]:=lcs[i-1,j]
       else
        lcs[i,j]:=lcs[i,j-1];
end;
procedure afisare_solutie(i,j:integer);
begin
 if lcs[i,j]<>0 then
   begin
    if a[i]=b[j]
     then
      begin
       afisare_solutie(i-1,j-1);
       write(g,a[i],' ');
      end
     else
      if lcs[i,j]=lcs[i-1,j]
       then
        afisare_solutie(i-1,j)
       else
        afisare_solutie(i,j-1);
   end;
end;


begin {pp}
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,na,nb);
 for i:=1 to na do
  read(f,a[i]);
 for i:=1 to nb do
  read(f,b[i]);
 close(f);
 assign(g,'cmlsc.out');
 rewrite(g);
 rezolva();
 writeln(g,lcs[i,j]);
 afisare_solutie(na,nb);
 close(g);
end.