{
   Algoritmul_lui_Euclid.pas
   
   Copyright 2016 MihaiMoglan <mihaitamoglan@Private>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
   
   
}


var n,m,i,k,t:longint;
	f,g:text;

BEGIN
	assign(f,'euclid2.in');
	assign(g,'euclid2.out');
	reset(f);
	rewrite(g);
	read(f,t);
	for i:=1 to t do
	 begin
	   read(f,n,m);
	   while n<> 0 do
	    begin
	     k:=n;
	     n:=m mod n;
	     m:=k;
	    end;
	   writeln(g,m);
	  end;
	close(f);
	close(g);
END.

