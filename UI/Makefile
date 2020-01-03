compile: main.cpp startUI.cpp startUI.h
	g++ -o startUI *.cpp -std=c++11 -g `pkg-config gtkmm-3.0 --cflags --libs`

run: startUI
	./startUI

clean:
	rm startUI
