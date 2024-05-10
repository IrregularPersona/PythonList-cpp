PROJECTNAME = PLProject
OUTPUT_DIR = build

INCLUDE_DIRS = -Iinclude/
LIB_DIRS = -Llib

MAIN_SRC = .\main.cpp

FLAGS = -Wall -Wextra -std=c++20 

default:
	g++ -c .\include\PythonList.cpp -o lib\pythonList.o -std=c++20
	g++ $(MAIN_SRC) .\lib\pythonList.o $(FLAGS) -o $(OUTPUT_DIR)/$(PROJECTNAME) 