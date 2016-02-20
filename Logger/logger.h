#ifndef LOGGER_H_
#define LOGGER_H_

typedef struct logger_t LOGGER;

/**
 * Creates a new log file with the set filename
 * @param filename - The filename and path to use
 * @param buffer_size - The desired size of the buffer. a value of 0
 * results in the default 4k buffer
 * @return LOGGER* on success, NULL if malloc,
 * mutex, or thread creation failed
 */
LOGGER *logger_init(const char* filename, unsigned int buffer_size);

/**
 * Adds the message to the logger queue
 * @param log - The logger to use
 * @param message - The message to add
 *    the logger will append the time and data to the
 *    beginning of the line
 * @return -1 if log is NULL, -2 if line malloc fails,
 * -3 if enqueue fails, and 0 on success
 */
int logger_log(LOGGER *log, const char* message);

/**
 * Shuts down the logger and adds the remaining
 * lines to the log file
 * @param log - Logger to shutdown
 * @return -1 if queue not destroyed correctly,
 * 0 on success
 */
int logger_shutdown(LOGGER *log);

#endif
