#ifndef CONN_H
#define CONN_H

#include <net.h>

#define IP "192.168.10.189"
#define PORT 8001

#define HEADER_END { NULL, NULL }

typedef struct {
    char *key;
    char *val;
} Header;

typedef struct {
    int conn_status;

    char *data;
    char *body;
} HTTP;

HTTP get(char *body, Header *headers);
int tcpConnect();

#endif /* CONN_H */
