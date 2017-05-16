equals(0, nil).
equals(1, one).
equals(2, two).
equals(3, three).
equals(4, four).
equals(5, five).
equals(6, six).
equals(7, seven).
equals(8, eight).
equals(9, nine).

equals(nil, 	0).
equals(one, 	1).
equals(two, 	2).
equals(three, 	3).
equals(four, 	4).
equals(five, 	5).
equals(six, 	6).
equals(seven, 	7).
equals(eight, 	8).
equals(nine, 	9).

exchange([],[]) :- !.
exchange([H1|T1], [H2|T2]) :- 
	equals(H1, H2), 
	exchange(T1, T2).

main :- 
	exchange(X, [0, 1, 2, 3, 4, 5, six, seven, eight, nine]),
	write(X).