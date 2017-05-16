%1
f(Number, 'is negative') :- Number < 0, !.
f(Number, 'is zero') :- Number = 0, !.
f(Number, 'is positive') :- Number > 0.

%2
p(4).
p(5) :- !.
p(6).

%3
 max(X, Y, X)  :-  
 	X  >=  Y, !.
 	max(X, Y, Y).