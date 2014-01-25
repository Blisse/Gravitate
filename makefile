OUTPUT_NAME = gravity
INC_DIR = ./inc
SRC_DIR = ./src
BIN_DIR = ./bin

INCLUDES= \
	-I${SRC_DIR}

SRC := $(shell find $(SRC_DIR) -name '*.cpp')
INC := $(shell find $(INC_DIR) -name '*.h')

CXX = g++
CXXFLAGS = -g -Wall -std=c++0x -I${INC_DIR}
OBJECTS = \
	${BIN_DIR}/main.o \
	${BIN_DIR}/gravity.o \
	${BIN_DIR}/CEvents.o 

DEPS = $(BIN_DIR)/${OUTPUT_NAME}.deps

all: ${DEPS} ${OUTPUT_NAME}

${DEPS}: ${SRC} ${INC}
	@${CXX} -M ${SRC} > ${DEPS}

${OUTPUT_NAME}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${OUTPUT_NAME} -lSDL

${OBJECTS}: ${BIN_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CXX} ${CXXFLAGS} $< -c -o $@

force:
	$(MAKE) fullclean
	$(MAKE)

clean:
	rm ${OBJECTS} ${OUTPUT_NAME}

fullclean:
	rm ${OBJECTS} ${DEPS} ${OUTPUT_NAME}

run:
	./${OUTPUT_NAME}

style:
	astyle --style=java --indent=spaces=2 ${SRC} ${INC}

.PHONY: all clean fullclean run style force

include $(DEPS)