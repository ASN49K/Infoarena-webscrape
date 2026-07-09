Var  n,i,a,b : longint;
     f,g : text;


//Algoritmul lui Euclid
Procedure Euclid2 (x,y : longint);

Var aux : longint;
 Begin

  While y <> 0 Do
   Begin
    aux := x Mod y;
    x := y;
    y := aux;
   End;
  Writeln(g,x);

 End;


//Programul principal

Begin

//Citirea datelor
 Assign(f,'euclid2.in');
 Reset(f);
 Assign(g,'euclid2.out');
 Rewrite(g);

 Readln(f,n);

//Introducem pe rand A si B si folosim "euclid2"
 i := 0;
 Repeat
  Readln(f,a,b);
  Euclid2(a,b);
  i := i+1;
 Until i = n;

 Close(f);
 Close(g);

End.

