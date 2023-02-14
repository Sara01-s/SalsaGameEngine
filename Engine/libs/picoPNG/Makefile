# $(1) : Compiler					(gcc, g++)
# $(2) : Object file to generate	(*.o)
# $(3) : Source file 				(*.c, *.cpp)
# $(4) : Dependencies				(*.h, *.hpp)
# $(5) : Compiler flags				(-Wall, -pedantic)
 
define COMPILE
$(2) : $(3) $(4)
	$(1) -c $(3) -o $(2) $(5)
endef

# $(1) : Source file
# C or C++ File to Object file modus operandi e.g.
# input  : src/tinyPTC/xbcde.cpp
# output : obj/tinyPTC/xbcde.o

define C2O
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef


# $(1) : Dependency
define C2H
$(patsubst %.c,%.h,$(patsubst %.cpp,%.hpp,$(1)))
endef


APP 	:= libPicoPNG.a
CFLAGS  := -Wall -pedantic
CCFLAGS := $(CFLAGS) -std=c++14
C       := gcc
CC      := g++
AR		:= ar
ARFLAGS := -crs
RANLIB  := ranlib
MKDIR   := mkdir -p
RM		:= rm
SRC     := src
OBJ     := obj

ifdef DEBUG 			#Activar debug (uso: make DEBUG=1)
	CFLAGS  += -g
	CCFLAGS += -g
else
	CFLAGS  += -O3
	CCFLAGS += -O3
endif


# % = * (cualquier cosa)
ALLCPPS    := $(shell     find src/ -iname *.cpp)
ALLCS      := $(shell 	  find src/ -iname *.c)
ALLOBJ     := $(foreach   F,$(ALLCPPS) $(ALLCS),$(call C2O,$(F)))
SUBDIRS    := $(shell 	  find src -type d)
OBJSUBDIRS := $(patsubst  $(SRC)%,$(OBJ)%,$(SUBDIRS))

.PHONY: info

# Archivar librería
$(APP) : $(OBJSUBDIRS) $(ALLOBJ)
	$(AR) $(ARFLAGS) $(APP) $(ALLOBJ)
	$(RANLIB) $(APP)

# $@ = %.0 (producto esperado)
# $^ = %.c (dependencia)

# foreach var "F" = "file in ..."
$(foreach F,$(ALLCPPS),$(eval $(call COMPILE,$(CC),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILE,$(C),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS))))


# foreach rules e.g.
#$(OBJ)/%.o : $(SRC)/%.c
#	$(C) -o $(patsubst $(SRC)%, $(OBJ)%, $@) -c $^ $(CFLAGS)
#
#$(OBJ)/%.o : $(SRC)/%.cpp
#	$(CC) -o $(patsubst $(SRC)%, $(OBJ)%, $@) -c $^ $(CCFLAGS)


info: 
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLOBJ))
	

$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)

## CLEAN RULES
clean:
	$(RM) -r "./$(OBJ)"

cleanall: clean
	$(RM) "./$(APP)"
	
