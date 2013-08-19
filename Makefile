CC=g++

GL_INC_DIR=/usr/include
GL_LIB_DIR=/usr/lib

GL_LIBS=-L$(GL_LIB_DIR) -lglut -lGLU -lGL

CFLAGS = -Wall

.PHONY:clean

OBJ = my_draw.o
LIBS = $(GL_LIBS)

all: $(OBJ) my_draw

$(OBJ): %.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

my_draw: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@

clean:
	rm -f  ./*~ ./core $(OBJ)

#DEPENDENCIES- DO NOT DELETE
my_draw.o : my_draw.h
