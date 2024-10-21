.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  heaptest

C_SOURCES =  main.cpp
C_OBJS     = main.o

CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

heaptest :   main.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================

clean:
	rm -f $(TARGET) $(C_OBJS) core *~




