#ifndef LOG_H
#define LOG_H

#include <time.h>
#include <cstring>



// DEFAULT LOG LEVEL 
#ifndef LOG_LEVEL
#define LOG_LEVEL DEBUG_LEVEL
#endif


// ===== auxillary function 
static inline char* timenow();

#define NO_LOG         0x00
#define ERROR_LEVEL    0x01
#define INFO_LEVEL     0x02
#define DEBUG_LEVEL    0x03

#define _FILE strrchr(__FILE__, '/')? strrchr(__FILE__, '/') + 1 : __FILE__


// format the log 
#define LOG_FMT "%s | %-7s | %-15s | %s:%d |"
#define LOG_ARGS( LOG_TAG )   timenow(), LOG_TAG, _FILE, __func__, __LINE__

// print function
#define PRINTFUNCTION(format, ...)   printf( format, __VA_ARGS__ )

// strings 
#define NEWLINE "\n"
#define ERROR_TAG  "ERROR"
#define INFO_TAG   "INFO"
#define DEBUG_TAG  "DEBUG"

// DEBUG 
#if LOG_LEVEL >= DEBUG_LEVEL
#define LOG_DEBUG(message, args...)    PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(DEBUG_TAG), ## args)
#else
#define LOG_DEBUG(message, args...)
#endif

// INFO 
#if LOG_LEVEL >= INFO_LEVEL
#define LOG_INFO(message, args...)    PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(INFO_TAG), ## args)
#else
#define LOG_INFO(message, args...)
#endif

// ERROR
#if LOG_LEVEL >= ERROR_LEVEL
#define LOG_ERROR(message, args...)    PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), ## args)
#else
#define LOG_ERROR(message, args...)
#endif

// NO LOGGING 
#if LOG_LEVEL >=  NO_LOG
#define LOG_IF_ERROR(condition, message, args...) \
  if (condition)  PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), ## args)
#else
#define LOG_IF_ERROR(condition, message, args...)
#endif

// aux log 
#define LOG(msg) \
  std::cout<<__FILE__<<" ("<< __LINE__<<"): "<<msg<<std::endl


static inline char* timenow() {

  static char buffer[64];
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime (buffer, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
  return buffer;
}

#endif
