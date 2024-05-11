PROJECTNAME = PLProject
OUTPUT_DIR = build

INCLUDE = .\include\PythonList.cpp
LIB = .\lib\pythonList.o

MAIN_SRC = .\main.cpp

FLAGS = -Wall -Wextra -std=c++20 

default:
	g++ -c $(INCLUDE) -o $(LIB) -std=c++20
	g++ $(MAIN_SRC) $(LIB) $(FLAGS) -o $(OUTPUT_DIR)/$(PROJECTNAME)