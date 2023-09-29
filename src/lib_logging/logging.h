#pragma once

/*
    setupLogging(
        logLevel    -> Level of logs to display 0 -> errors only, ..., 3 -> all up to debug
    );
*/
// set_log(flags);
/*
    output_dest     -> destination of output: stdout, stderr
    space_above     -> puts a space above each un-nested log
*/

typedef enum {
    LOG_ERROR = 0,  // Most important
    LOG_WARNING,    //      |
    LOG_INFO,       //     \|/
    DEBUG       // Least important
} LogType_t;

typedef enum
{
    RESET = 0,
    BLACK = 30,
    DARK_RED = 31,
    DARK_GREEN = 32,
    DARK_YELLOW = 33,
    DARK_BLUE = 34,
    DARK_MAGENTA = 35,
    DARK_CYAN = 36,
    GRAY = 37,
    DARK_GRAY = 90,
    RED = 91,
    GREEN = 92,
    YELLOW = 93,
    BLUE = 94,
    MAGENTA = 95,
    CYAN = 96,
    WHITE = 97
} ColorCodes_t;

void setTerminalColor(ColorCodes_t ColorCode);
int Log_MSG(LogType_t logType, const char* format, ...);
int Log_Nest(LogType_t logType, int nestingLevel, char* format, ...);
char* itoa(int val, int base);