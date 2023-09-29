#pragma once

#include <stdint.h>

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
    LOG_DEBUG       // Least important
} LogType_t;

int Log_MSG(LogType_t logType, const char* msgFormat, ...);
int Log_Nest(LogType_t logType, uint8_t nestingLevel, const char* msgFormat, ...);
