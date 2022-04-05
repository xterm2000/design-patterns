# compiler flag 
GCC := g++

#define any includes other than /usr/include
INCLUDES := -I./include

# library paths in addition to usr/lib  
LFLAGS := -L./lib

# paths 
BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj

# targets 
EXE := $(BIN_DIR)/main

# list of source files 
SRC := $(wildcard $(SRC_DIR)/*.cpp)

# from the source list the objects 
#OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

######## FLAGS ##########

# when linking, to avoid linker errors, 
# it is strongly recommended to put LDFLAGS before object file ans LDLIBS after 

CPPFLAGS := -Iinclude -MMD -MP            # preprocessor flag
LDFLAGS  := -Llib                         # linker flag 
LDLIBS   := -lm                           # left empty if no libs needed   
CFLAGS   := -Wall -O2 \
	-std=c++17 -Wshadow -g # -pedantic  # compiler flags
#########################

files := $(wildcard $(SRC_DIR)/*.cpp)
objects := $(patsubst %.cpp,%.o,$(files))

.PHONY: all clean

all: $(EXE)

# linking step
$(EXE): $(OBJ) | $(BIN_DIR)
	@echo "linking..."
	$(GCC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# compilation 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "compilng..."
	$(GCC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@



# create directories of not exist 
$(BIN_DIR) $(OBJ_DIR): 
	@echo "creating dir  $@"
	@mkdir -p $@


clean:
	@echo "Cleaning up..."
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)


info:
	@echo "------- info --------"
	@echo "files: "  $(SRC)
	@echo "objects:" $(OBJ)


print-%: ; @echo $*=$($*)

#-include $(OBJ:.o=.d)
