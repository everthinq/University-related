say_hi :-
	write('what is your name? '), read(X),
	write('Hi, '), write(X).

sum_of_two(RES) :-
	write('Enter num1: '), read(X),
	write('Enter num2: '), read(Y),
	RES is X + Y.

%RELATIONSHIPS%
man('Ivan').
man('Ilya').
man('Misha').

woman('Nastya').
woman('Natasha').
woman('Jenya').

married('Misha','Jenya').
married('Jenya', 'Misha').

married('Ilya','Natasha').
married('Natasha', 'Ilya').

parent('Misha','Natasha').
parent('Jenya','Natasha').

parent('Ilya','Ivan').
parent('Natasha','Ivan').
parent('Ilya','Nastya').
parent('Natasha','Nastya').

mother(X, Y) :- 
	parent(X, Y),
	woman(X).

father(X, Y) :- 
	parent(X, Y),
	man(X).
%RELATIONSHIPS%