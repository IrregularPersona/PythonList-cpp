PROJECTNAME = PLProject
OUTPUT_DIR = build

INCLUDE_DIRS = -Iinclude/
LIB_DIRS = -Llib

MAIN_SRC = .\main.cpp

FLAGS = -Wall -Wextra -std=c++20 

default:
	g++ $(MAIN_SRC) .\lib\pythonList.o $(FLAGS) -o $(OUTPUT_DIR)/$(PROJECTNAME) 