OUTPUT_NAME = gravity
INC_DIR = ./inc
SRC_DIR = ./src
BIN_DIR = ./bin

INCLUDES= \
	-I${INC_DIR} \
	-I${INC_DIR}/Models/  \
	-I${INC_DIR}/Models/Events/  \
	-I${INC_DIR}/Models/Settings/  \
	-I${INC_DIR}/Models/Timers/  \
	-I${INC_DIR}/Views/  \
	-I${INC_DIR}/ViewControllers/  \
	-I./lib/glm

SRC := $(shell find $(SRC_DIR) -name '*.cpp')
INC := $(shell find $(INC_DIR) -name '*.h')

CXX = g++
CXXFLAGS = -g -Wall -std=c++0x

LIBFLAGS = -lSDL -lGL -lGLU -lglut

OBJECTS = \
	${BIN_DIR}/main.o \
	${BIN_DIR}/gravity.o \
	${BIN_DIR}/SDLEvents.o \
	${BIN_DIR}/Models/BaseObject.o \
	${BIN_DIR}/Models/Dot.o \
	${BIN_DIR}/Models/Events/Event.o \
	${BIN_DIR}/Models/Events/KeyEvent.o \
	${BIN_DIR}/Models/Settings/GravitySettings.o \
	${BIN_DIR}/Models/Timers/Timer.o \
	${BIN_DIR}/Models/Timers/TimerListener.o \
	${BIN_DIR}/Views/BaseView.o \
	${BIN_DIR}/Views/RootWindow.o

DEPS = $(BIN_DIR)/${OUTPUT_NAME}.deps

all: ${DEPS} ${OUTPUT_NAME}

${DEPS}: ${INC} ${SRC}
	@${CXX} -std=c++0x ${INCLUDES} ${SRC} ${LIBFLAGS} > ${DEPS}

${OUTPUT_NAME}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${INCLUDES} ${OBJECTS} -o ${OUTPUT_NAME} ${LIBFLAGS}

${OBJECTS}: ${BIN_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CXX} ${CXXFLAGS} ${INCLUDES} $< -c -o $@

force:
	$(MAKE) fullclean
	$(MAKE)

clean:
	rm ${OBJECTS} ${OUTPUT_NAME}

fullclean:
	rm ${OBJECTS} ${DEPS} ${OUTPUT_NAME}

run:
	clear
	./${OUTPUT_NAME}

style:
	astyle --style=java --indent=spaces=2 ${SRC} ${INC}

.PHONY: all clean fullclean run style force

include $(DEPS)
