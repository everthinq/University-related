school('Rybnitsa').
school('Tiraspol').
school('Rezina').
school('Bender').

student('Bereket Roman', 'Rybnitsa').
student('Grigorieva Ekaterina', 'Rybnitsa').
student('Duminyuk Bogdan', 'Tiraspol').
student('Kozlov Petr', 'Tiraspol').
student('Marko Alex', 'Rezina').
student('Potapov Andrei', 'Rezina').
student('Rusnak Nikola', 'Bender').
student('Statnic Artur', 'Bender').
student('Tolstov Ivan', 'Rybnitsa').
student('Tyatkov Valek', 'Rybnitsa').

condition(X) :-
	X = 'Rybnitsa',
	school(X), !.

find :- 
	student(Surname, X),
	condition(X),
	write(Surname), nl, fail.