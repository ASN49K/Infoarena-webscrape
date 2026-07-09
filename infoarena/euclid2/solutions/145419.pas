program reactivi2;   
{$APPTYPE CONSOLE}  
uses  
  SysUtils;   
type nr = record  
  x,y:shortint;   
  ok:boolean;   
end;   
var fin,fout:text;   
    c,n,i,j:integer;   
    v:array [1..8000] of nr;   
{*---------------------------*}  
procedure citire;   
begin  
        assign(fin,'reactivi.in'); reset(fin);   
        assign(fout,'reactivi.out'); rewrite(fout);   
        readln(fin,n);   
        for i:=1 to n do readln(fin,v[i].x,v[i].y);   
        close(fin);   
end;   
{*---------------------------*}  
procedure qsort(lower, upper : integer);
var left, right : integer;
     pivot,Aux:nr;
     begin
         pivot:=V[(lower+upper) div 2];
         left:=lower;
         right:=upper;
         
         while left<=right do
         begin
             while V[left].x  < pivot.x do left:=left+1;  { Parting for left }
             while V[right].x > pivot.x do right:=right-1;{ Parting for right}
             if left<=right then   { Validate the change }
             begin
                 Aux:=V[left];
                 V[left]:=V[right];
                 V[right]:=Aux;

         {        Aux:=Vecti[left];
                 Vecti[left]:=Vecti[right];
                 Vecti[right]:=Aux;  }
//                 swap (Vectj[left]) with Data[right];
                 left:=left+1;
                 right:=right-1;
             end;
         end;
         if right>lower then qsort(lower,right); { Sort the LEFT  part }
         if upper>left  then qsort(left ,upper); { Sort the RIGHT part }
     end;
{*---------------------------*}  
procedure Afisare;   
begin  
        for i:=1 to n do writeln(fout,v[i].x,' ',v[i].y,' ',v[i].ok);   
end;   
{*---------------------------*}  
function merge:boolean;   
begin  
        merge:=false;   
        if ((v[i].x>=v[j].x) and (v[i].x<=v[j].y)) then merge:=True;
//        if (v[i].x<=v[j].y) then merge:=True;   
end;
{*---------------------------*}  
procedure solve;   
begin  
        For i:=1 to n do  
        begin  
                if not v[i].ok then  
                begin  
                        for j:=1 to i-1 do  
                        begin
//                                if not v[j].ok then
                                if ((v[i].x>=v[j].x) and (v[i].x<=v[j].y) and (not v[j].ok)) then
                                Begin
                                        v[j].ok:=True;   
  
                                        if v[i].x > v[j].x then v[i].x:=v[j].x;   
                                        if v[i].y > v[j].y then v[i].y:=v[j].y;   
                                        Break;   
                                end;   
                        end;   
                end;   
        end;   
end;   
{*-----------MAIN------------*}  
begin  
        citire;   
        C:=0;
        qsort(1,n);
//        ordonare;
        solve;   
        For i:=1 to n do if not v[i].ok then inc(c);
       // afisare;   
        Writeln(fout,c);   
        close(fout);   
end.  

