var f1, f2:text;
  a1,a2,a3:array[0..1024] of integer;
  a:array[0..1024,0..1024] of integer;  
  i,j,n1,n2,n3,nn:integer;
  
function max(a,b:integer):integer;
begin
  if a>b
  then max:=a
  else max:=b
end;

begin
  assign(f1,'cmlsc.in');
  reset(f1);
  assign(f2, 'cmlsc.out');
  rewrite(f2);
  
  readln(f1,n1,n2);
  for i:=1 to n1 do read(f1,a1[i]);
  for i:=1 to n2 do read(f1,a2[i]);
  
  for i:=0 to n1 do
    for j:=0 to n2 do
      a[i,j]:=0;
      
  for i:=1 to n1 do
    for j:=1 to n2 do
      if a1[i]=a2[j]
      then a[i,j]:=a[i-1,j-1]+1
      else a[i,j]:=max(a[i-1,j],a[i,j-1]);
            
  i:=n1; j:=n2; n3:=a[n1,n2]; nn:=n3;
  while (i>0)and(j>0) do
  begin
    if a1[i]=a2[j]
    then begin 
      a3[n3]:=a1[i];
      dec(i); dec(j); dec(n3);      
    end
    else if a[i-1,j]>a[i,j-1]
    then dec(i)
    else dec(j);
  end;
   
  writeln(f2, nn);
  for i:=1 to nn do write(f2,a3[i],' ');
  
  close(f2);
end.