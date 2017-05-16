predicates
	nondeterm solution.
	nondeterm find_form(real,real,real)
clauses
	find_form(X, Y, Z) :- 
	X <= Y, !, 
	A = log(X + Z),
	write("A = ", A), nl, fail.

	find_form(X, Y, Z):- 
	X > Y,
	B = (Y / 2) + ( sin(Z) * sin(Z) * sin(Z) ),
	write("B = ",B), nl, fail.
	
	solution :- 
	write("X = "),readreal(X),
	nl,write("Y = "),readreal(Y),
	nl,write("Z = "),readreal(Z),
	find_form(X, Y, Z).
goal	
	solution.
