CXX=g++
TARGET=FlyingMan
OBJ=Flyingman.o	Hauky.o	Console.o	Material.o	resource.res
INCLUDEPATH=../include

$(TARGET):	$(OBJ)
	$(CXX) -o	../bin/$@	$(OBJ) -I.
Flyingman.o:	../Flyingman.cpp	$(INCLUDEPATH)/Hauky.hpp	$(INCLUDEPATH)/Console.hpp	$(INCLUDEPATH)/Material.hpp
	$(CXX) -c	../Flyingman.cpp -I $(INCLUDEPATH)
Hauky.o:	$(INCLUDEPATH)/Hauky.cpp	$(INCLUDEPATH)/Hauky.hpp	$(INCLUDEPATH)/Console.hpp	$(INCLUDEPATH)/Material.hpp
	$(CXX) -c	$(INCLUDEPATH)/Hauky.cpp -I $(INCLUDEPATH)
Console.o:	$(INCLUDEPATH)/Console.cpp	$(INCLUDEPATH)/Console.hpp	$(INCLUDEPATH)/Material.hpp
	$(CXX) -c	$(INCLUDEPATH)/Console.cpp -I $(INCLUDEPATH)
Material.o:	$(INCLUDEPATH)/Material.cpp	$(INCLUDEPATH)/Material.hpp
	$(CXX) -c	$(INCLUDEPATH)/Material.cpp -I $(INCLUDEPATH)
resource.res:	$(INCLUDEPATH)/resource.rc
	windres $(INCLUDEPATH)/resource.rc -O coff -o resource.res

clean:
	rm $(OBJ)