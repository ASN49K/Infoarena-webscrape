Program euclid;
Var
f1,f2:text;
a,b,r,i:longint;
Begin
Assign (f1,'euclid2.in');
Reset (f1);
Assign (f2,'euclid2.out');
Rewrite(f2);
read (f1,a,b);
r:=a mod b;
While r<>0 do
Begin
a:=b;
b:=r;
r:=a mod b;
end;
end.