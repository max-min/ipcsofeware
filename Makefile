#TOP :=$(shell pwd)
TOP :=.

MAIN_DIR:=$(TOP)/mainenv


IPC_INC += -I$(MAIN_DIR)/inc
IPC_INC += -I$(LOG_DIR)

PROJECT_SRC += $(wildcard $(TOP)/*.cpp)

######
# mainenv 
######
IPC_INC += -I$(MAIN_DIR)
PROJECT_SRC += $(wildcard $(MAIN_DIR)/*.cpp)

######
# alarm  
######
ALARM_DIR := $(TOP)/mainenv/alarm
IPC_INC += -I$(ALARM_DIR)
PROJECT_SRC += $(wildcard $(ALARM_DIR)/*.cpp)

######
# codec 
######
CODEC_DIR := $(TOP)/mainenv/codec
IPC_INC += -I$(CODEC_DIR)
PROJECT_SRC += $(wildcard $(CODEC_DIR)/*.cpp)

######
# log 
######
LOG_DIR := $(TOP)/mainenv/log
IPC_INC += -I$(LOG_DIR)
PROJECT_SRC += $(wildcard $(LOG_DIR)/*.cpp)

######
# Net 
######
NET_DIR := $(TOP)/mainenv/net
IPC_INC += -I$(NET_DIR)
PROJECT_SRC += $(wildcard $(NET_DIR)/*.cpp)

######
# other 
######
OTHER_DIR := $(TOP)/mainenv/other
IPC_INC += -I$(OTHER_DIR)
PROJECT_SRC += $(wildcard $(OTHER_DIR)/*.cpp)

######
# param 
######
PARAM_DIR := $(TOP)/mainenv/param
IPC_INC += -I$(PARAM_DIR)
PROJECT_SRC += $(wildcard $(PARAM_DIR)/*.cpp)

######
# server 
######
SERVER_DIR := $(TOP)/mainenv/server
IPC_INC += -I$(SERVER_DIR)
PROJECT_SRC += $(wildcard $(SERVER_DIR)/*.cpp)

######
# time 
######
TIME_DIR := $(TOP)/mainenv/time
IPC_INC += -I$(TIME_DIR)
PROJECT_SRC += $(wildcard $(TIME_DIR)/*.cpp)

######
# timer 
######
TIMER_DIR := $(TOP)/mainenv/timer
IPC_INC += -I$(TIMER_DIR)
PROJECT_SRC += $(wildcard $(TIMER_DIR)/*.cpp)


######
# common
#######
COMMON_DIR := $(TOP)/mainenv/common
IPC_INC += -I$(COMMON_DIR)
PROJECT_SRC += $(wildcard $(COMMON_DIR)/tinyxml/*.cpp)


CFLAGS += $(IPC_INC)

STD += -std=c99
#LDFLAGS += $(LIB)
LDFLAGS +=  -ldl -pthread -g 


OBJECTS_DIR:=$(TOP)/objects
OBJECT_FILE:=$(addprefix $(OBJECTS_DIR)/, $(addsuffix .o, $(basename $(notdir $(PROJECT_SRC)))))


CC := g++
EXE_NAME:=ipc_software
DEPFILE:=$(PROJECT_ROOT)/deps

.PHONY:all
all:$(DEPFILE) $(EXE_NAME)

$(DEPFILE): $(PROJECT_SRC) Makefile
	@echo "Generating new dependency file...";
	@-rm -f $(DEPFILE)
	@for f in $(PROJECT_SRC); do \
		OBJ=$(OBJECTS_DIR)/`basename $$f|sed -e 's/\.cpp/\.o/' -e 's/\.c/\.o/'`; \
		echo $$OBJ: $$f>> $(DEPFILE); \
		echo '	$(CC) $$(CFLAGS)  -c -o $$@ $$^'>> $(DEPFILE); \
		done

-include $(DEPFILE)

############################################
$(EXE_NAME): $(OBJECT_FILE)
	$(CC) $(STD) $(CFLAGS)  $(OBJECT_FILE) -o "$@" $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf $(EXE_NAME)
	rm -rf $(DEPFILE)
	rm -rf $(OBJECTS_DIR)/*.o


