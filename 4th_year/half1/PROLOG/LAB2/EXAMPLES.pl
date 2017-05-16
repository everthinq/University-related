%1%
student('Ivanov', 2).
student('Petrov', 2).
student('Sidorov', 2).
student('Kovalev', 2).

student('Antonov', 3).
student('Anisimov', 3).
student('Tihonov', 3).
student('Travkin', 3).

student('Jdanov', 4).
student('Galkin', 4).

book('Physics', 1001, 1990, 'Ivanov').
book('Chemistry', 3002, 1970, 'Petrov').
book('Physics', 1002, 1985, 'Antonov').
book('Chemistry', 3003, 2001, 'Tihonov').
book('Chemistry', 3004, 2000, 'Galkin').
book('Math', 4001, 1985, 'Galkin').

%RULES%
%	какие книги (название, номер) 
%	не возвращены студентами заданного курса;
rule_1 :-
	write('Enter the student year: '), read(Year),
	student(Studname, Year),
	book(Titlebook, Numbook, _, Studname),
	write(Titlebook), write(', '),
	write(Numbook), write(', '),
	write(Studname).	

%	кто из студентов не вернул книги, 
%	изданные до 1990 года;
rule_2 :-
	write('Enter release year of the book: '), read(YearFromUser),
	book(_, _, Year, Studname),
	Year < YearFromUser,
	write(Year), write(' '),
	write(Studname).	

%	кто из студентов не вернул книги заданной 
%	тематики (например, по химии).
rule_3 :-
	write('Enter the book title: '), read(Titlebook),
	book(Titlebook, _, _, Studname),
	write(Titlebook), write(' '),
	write(Studname).
%RULES%

%GOALS%
%	перечислить фамилии студентов 3-го курса, 
%	которые пользуются услугами библиотеки;
goal_1 :-
	student(Studname, 3),
	write(Studname).
	
%	перечислить фамилии студентов 2-го и 4-го курсов, 
%	которые пользуются услугами библиотеки;
goal_2 :-
	student(Studname, 2), write(Studname), write(', 2');
	student(Studname, 4), write(Studname), write(', 4').
	
%	какие книги (название и номер) 
%	не возвращены студентами 2-го курса?
goal_3 :-
	student(Studname, 2),
	book(Titlebook, Numbook, Year, Studname),
	write(Titlebook), write(', '),
	write(Numbook), write(', '),
	write(Year), write(', '),
	write(Studname).

%	Кто из студентов не вернул книги, 
%	изданные до 1990 года?	
goal_4 :-
	book(Titlebook, Numbook, Year, Studname),
	Year < 1990,
	write(Titlebook), write(', '),
	write(Numbook), write(', '),
	write(Studname).
	
%	Кто из студентов 
%	не вернул книги по физике?
goal_5 :-
	book(Titlebook, Numbook, Year, Studname),
	Titlebook = 'Physics',
	write(Titlebook), write(', '),
	write(Numbook), write(', '),
	write(Year), write(', '),
	write(Studname).
%GOALS%
%1%