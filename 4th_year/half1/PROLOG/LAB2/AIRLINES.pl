%0 - name
%1 - price
%2 - flight_time
%3 - direct_flight
%4 - discounts

airplane('American Airlines', 100, 2, 'Y', 'Y').
airplane('Delta Air Lines', 200, 10, 'N', 'N').
airplane('Air France', 300, 2, 'Y', 'N').
airplane('Southwest Airlines', 400, 12, 'N', 'Y').
airplane('Fly Emirates', 500, 2, 'Y', 'N').

chosen :-
	write('Enter price between 100 and 500: '), read(Price),
	write('Enter flight time between 2 and 12: '), read(Flight_time),
	write('Do you want a direct flight? Answer might be Y or N: '), read(Direct_flight),
	write('Do you want any discounts? Answer might be Y or N: '), read(Discounts),
	airplane(Name, Price, Flight_time, Direct_flight, Discounts),
	write('\nYou will need to choose the '), write(Name).