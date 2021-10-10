equazione_Bonnor-Ebert: equazione_Bonnor-Ebert.o Vettore.o FunzioneVettoriale.o VettoreLineare.o
	g++ -std=c++11 -Wall -o $@ $^

%.o: %.cpp Vettore.hpp FunzioneVettoriale.hpp VettoreLineare.hpp
	g++ -std=c++11 -Wall -c -o $@ $<

clear:
	rm *.o
