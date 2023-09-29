CC = clang
CFLAGS = -Wall -Wextra -Werror -O3 -std=c17

INCLUDES = 
LINKS =  
LINK_FLAGS = 

# INCLUDES = -I ${SDL_PATH}/include -I ./glad/include
# LINKS = -L ${SDL_PATH}/lib
# LINK_FLAGS = -lSDL2

APP = app.out
# ROM_NAME = test/my_rom.ch8
 
SRC_FILES = ./src/test.c ./src/lib_logging/logging.c
OBJ_FILES = ./build/test.o ./build/logging.o

${APP}: ${OBJ_FILES}
	$(CC) $(CFLAGS) -o $(APP) ${LINKS} $^ $(LINK_FLAGS)
	@echo

./build/test.o: ./src/test.c ./src/lib_logging/logging.h
	$(CC) $(CFLAGS) ${INCLUDES} -c $^
	@mv *.o ./build

./build/logging.o: ./src/lib_logging/logging.c ./src/lib_logging/logging.h
	$(CC) $(CFLAGS) ${INCLUDES} -c $^
	@mv *.o ./build


.PHONY: run
run: ${APP}
	@echo Running ${APP} ...
	@./${APP} ${ROM_NAME} && echo "${APP}" exited with: $$?


.PHONY: clean
clean:
	rm -rf $(OBJ_FILES) $(APP)
	rm -rf ./src/*.gch ./src/lib_logging/*.gch
