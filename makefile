OBJECTS=main.o bezier.c bresemham.c plot.c
OUTPUT=MAIN
CFLAGS=-I/usr/local/Mesa-3.4/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/local/Mesa-3.4/lib -L/usr/X11R6/lib
$(OUTPUT): $(OBJECTS)
	cc $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $(OBJECTS) $(LDLIBS)
$(OBJECTS): main.h
clean:
	rm -f *.o
	rm -f main
