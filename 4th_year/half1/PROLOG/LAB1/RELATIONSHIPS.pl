%RELATIONSHIPS%
%man && womans
man('Vasya').			%1
man('Afonya').			%2

man('Petya').			
man('Vaflentin').		
man('Oleg').			

woman('Zina').			%1
woman('Vika').			%2
woman('Larisa').		
woman('Vera').	%1
woman('Nadya').		%2

%man && womans

%married
married('Vasya', 'Zina').		%1
married('Zina', 'Vasya').		%1

married('Afonya', 'Vika').		%2
married('Vika', 'Afonya').		%2

married('Petya', 'Larisa').		
married('Larisa', 'Petya').		
%married

%parents
parent('Vasya', 'Petya').		%1
parent('Zina', 'Petya').		%1
parent('Vasya', 'Vera').	%1
parent('Zina', 'Vera').	%1

parent('Afonya', 'Larisa').		%2
parent('Vika', 'Larisa').		%2
parent('Afonya', 'Nadya').	%2
parent('Vika', 'Nadya').	%2

parent('Petya', 'Vaflentin'). 	
parent('Larisa', 'Vaflentin'). 	
parent('Petya', 'Oleg'). 		
parent('Larisa', 'Oleg'). 		
%parents
%RELATIONSHIPS%

mother(Mother, Child) :- 
	woman(Mother),
	parent(Mother, Child).

father(Father, Child) :- 
	man(Father), 
	parent(Father, Child).

sister(Sister, Y) :-
    woman(Sister), 
    mother(Mother, Sister), 
    mother(Mother, Y), 
    Sister \= Y.

aunt(Aunt, Child) :- 
	woman(Aunt), 
	parent(Parent, Child),
	sister(Aunt, Parent).