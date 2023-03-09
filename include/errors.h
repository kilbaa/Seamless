#ifndef ERRORS_H
#define ERRORS_H

#include <conn.h>

#define HTTP_ERROR 1

void errorMessage(char *msg, ...);
int httpErrorHandle(HTTP http);

#endif /* ERRORS_H */
