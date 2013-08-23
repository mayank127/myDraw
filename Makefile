CC=g++

GL_INC_DIR=/usr/include
GL_LIB_DIR=/usr/lib

GL_LIBS=-L$(GL_LIB_DIR) -lglut -lGLU -lGL

CPPFLAGS = -Wall

.PHONY:clean all clean

LIBS = $(GL_LIBS)

SRCS := $(wildcard *.cpp)
INCS := $(wildcard *.hpp)
OBJS := $(SRCS:%.cpp=obj/%.o)
DEPS := $(OBJS:.o=.d)

TARGET = my_draw

-include $(OBJS:.o=.d)

all: setup $(TARGET)

setup:
	mkdir -p obj

$(OBJS): obj/%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@ -MD

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
	make clean

clean:
	rm -rf  ./*~ obj/
