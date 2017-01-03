#TOP :=$(shell pwd)
TOP :=.

MAIN_DIR:=$(TOP)/mainenv
ALARM_DIR := $(TOP)/mainenv/alarm 
CODEC_DIR := $(TOP)/mainenv/codec 
LOG_DIR := $(TOP)/mainenv/log
NET_DIR := $(TOP)/mainenv/net
OTHER_DIR := $(TOP)/mainenv/other
PARAM_DIR := $(TOP)/mainenv/param
SERVER_DIR := $(TOP)/mainenv/server
TIME_DIR := $(TOP)/mainenv/time
TIMER_DIR := $(TOP)/mainenv/timer


IPC_INC += -I$(MAIN_DIR)/inc
PROJECT_SRC += $(wildcard $(TOP)/*.cpp)

######
# mainenv 
######
IPC_INC += -I$(MAIN_DIR)
PROJECT_SRC += $(wildcard $(MAIN_DIR)/*.cpp)

######
# alarm  
######
IPC_INC += -I$(ALARM_DIR)
PROJECT_SRC += $(wildcard $(ALARM_DIR)/*.cpp)

######
# codec 
######
IPC_INC += -I$(CODEC_DIR)
PROJECT_SRC += $(wildcard $(CODEC_DIR)/*.cpp)

######
# log 
######
IPC_INC += -I$(LOG_DIR)
PROJECT_SRC += $(wildcard $(LOG_DIR)/*.cpp)

######
# Net 
######
IPC_INC += -I$(NET_DIR)
PROJECT_SRC += $(wildcard $(NET_DIR)/*.cpp)

######
# other 
######
IPC_INC += -I$(OTHER_DIR)
PROJECT_SRC += $(wildcard $(OTHER_DIR)/*.cpp)

######
# param 
######
IPC_INC += -I$(PARAM_DIR)
PROJECT_SRC += $(wildcard $(PARAM_DIR)/*.cpp)

######
# server 
######
IPC_INC += -I$(SERVER_DIR)
PROJECT_SRC += $(wildcard $(SERVER_DIR)/*.cpp)

######
# time 
######
IPC_INC += -I$(TIME_DIR)
PROJECT_SRC += $(wildcard $(TIME_DIR)/*.cpp)

######
# timer 
######
IPC_INC += -I$(TIMER_DIR)
PROJECT_SRC += $(wildcard $(TIMER_DIR)/*.cpp)




CFLAGS += $(IPC_INC)

#LDFLAGS += $(LIB)
LDFLAGS += -ldl -pthread  -g


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
	$(CC) $(CFLAGS)  $(OBJECT_FILE) -o "$@" $(LDFLAGS)
#	$(STRIP) $(EXE_NAME)
	cp $(EXE_NAME) ../../release/	

.PHONY:clean
clean:
	rm -rf $(EXE_NAME)
	rm -rf $(DEPFILE)
	rm -rf $(OBJECTS_DIR)/*.o
	


