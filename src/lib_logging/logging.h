#pragma once

#include <stdint.h>

/*
    Definitions:
        - LogType_t
            + The type of log to display
        - nestingLevel
            + How many indentations to indent a nested log
        - msgFormat
            + printf() formatted message
        - ...
            + args for the printf() formatted message
    
    Defaults:
        ~ These can be changed in the global g_LogState struct in
          logging.c
        
        - LOG_ERROR
            + identifier:           [-]
            + nested identifier:    \_
            + color:                red
        - LOG_WARNING
            + identifier:           [!]
            + nested identifier:    \_
            + color:                yellow
        - LOG_INFO
            + identifier:           [+]
            + nested identifier:    \_
            + color:                green
        - LOG_DEBUG
            + identifier:           [debug]
            + nested identifier:    \_
            + color:                cyan
*/

typedef enum {
    LOG_ERROR = 0,  // Most important
    LOG_WARNING,    //      |
    LOG_INFO,       //     \|/
    LOG_DEBUG       // Least important
} LogType_t;

LogType_t Log_MSG(LogType_t logType, const char* msgFormat, ...);
LogType_t Log_Nest(LogType_t logType, uint8_t nestingLevel, const char* msgFormat, ...);
