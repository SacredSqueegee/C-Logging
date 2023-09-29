#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "logging.h"


// Define terminal colors via escape sequences
// typedef enum
// {
//     RESET = 0,
//     BLACK = 30,
//     DARK_RED = 31,
//     DARK_GREEN = 32,
//     DARK_YELLOW = 33,
//     DARK_BLUE = 34,
//     DARK_MAGENTA = 35,
//     DARK_CYAN = 36,
//     GRAY = 37,
//     DARK_GRAY = 90,
//     RED = 91,
//     GREEN = 92,
//     YELLOW = 93,
//     BLUE = 94,
//     MAGENTA = 95,
//     CYAN = 96,
//     WHITE = 97
// } ColorCodes_t;


void setTerminalColor(ColorCodes_t colorCode)
{
    // char fullColorCode[12] = "\033[0;";
    // strcat(fullColorCode, itoa(colorCode, 10));
    // strcat(fullColorCode, ";30m");
    // printf("%s", fullColorCode);
    printf("%s%i%s", "\033[0;", colorCode, "m");
}

char* itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;
	
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];	
}
	