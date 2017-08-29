#Color code the warnings and errors in the terminal 
export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

CC=g++
CFLAGS = -std=c++14
INCLUDES = -I./Common -L./Common -I./ -L./

.PHONY: all
all: Kalman

.PHONY: debug
debug: CFLAGS += -g
debug: CXXFLAGS += -DDEBUG -g
debug: all

clean:
	@echo "Removing all existing object files"
	@rm -f *.o
	@echo "Removing all existing library files"
	@rm -f *.a
	@echo "Removing all .exe files"
	@rm -f *.exe
	@echo "Removing .gch files"
	@rm -f *.gch
	
Kalman:
	$(CC) $(CFLAGS) $(INCLUDES)  ./Common/fileUltils.cpp ./Common/functionTimer.cpp ./KalmanFilterWrapper.cpp ./KalmanFilter.cpp -o ./KalmanFilterWrapper.exe

