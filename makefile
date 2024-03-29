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
	@echo
	@./${APP} ${ROM_NAME} && echo && echo "${APP}" exited with: $$?


.PHONY: genlib
genlib: ./build/logging.o
	rm -rf ./release
	mkdir ./release
	mkdir ./release/liblogging
	mkdir ./release/liblogging/lib
	mkdir ./release/liblogging/include
	cp ./src/lib_logging/logging.h ./release/liblogging/include
	ar -rcs ./release/liblogging/lib/liblogging.a ./build/logging.o
	cd ./release && tar -czvf liblogging.tar.gz liblogging


.PHONY: clean
clean:
	rm -rf $(OBJ_FILES) $(APP)
	rm -rf ./src/*.gch ./src/lib_logging/*.gch
	rm -rf ./release
