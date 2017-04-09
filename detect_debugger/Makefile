INCLUDE=-I.
LIBS=
OBJS=main.o

CFLAGS=-Wall 
#-O2
CXX=g++
CC=gcc

CSUFFIX=c
CXXSUFFIX=cpp

APP=detect_debugger

all: $(APP)

$(APP): $(OBJS) $(LIBS)
	$(CC) -g $(DEBUG) $(CFLAGS) $^ -o $@



.$(CXXSUFFIX).o:
	$(CXX) -c -g $(CFLAGS) $< -o $@

.$(CSUFFIX).o:
	$(CC) -c -g $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(APP) ~.*


