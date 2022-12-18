#ifndef NET_H
#define NET_H

#include<winsock2.h>

#define CLOG_TCP 1
#define CLOG_UDP 2

/* Errors */
enum {
    CLOG_ERR_INVAL_SOCK
};

/* Actions */
enum {
    CLOG_ACT_IGNORE = 1
};

/* Callback Types */
enum {
    CLOG_ONCONNECTION = 0,

    CLOG_CALLBACK_COUNT
};

typedef struct {
    SOCKET sock_tcp;
    SOCKET sock_udp;

    char *host;
    int port;

    int error;
} Clog;

typedef struct {
    char *key, *value;
} clog_Header;

typedef struct {
    char *data;
    int num_cookies;
} clog_Cookie;

typedef struct {
    char *body;
    char *host;
    int port;

    int content_len;
    int offset;

    int num_headers;
} clog_HTTP;

#define CLOG_HEADER(key, value) (clog_Header){ key, value }
#define CLOG_BEG_HTTP_1_1 "GET / HTTP/1.1\r\nHost: "
#define CLOG_END_HTTP_1_1 "Connection: close\r\n\r\n"

int clog_GET(clog_HTTP *data);
clog_HTTP clog_InitGET(char *host, int port);
void clog_AddHeader(clog_HTTP *data, char *key, char *value);
void clog_AddCookieF(clog_HTTP *data, char *path);
void clog_saveCookies(char *path);
void clog_AddBody(clog_HTTP *data, char *body);

void clog_getStream(Clog *str);
int clog_error();
void clog_listener(int type, void (*callback)());
int clog_send(Clog *stream, char *data, int data_len);
int clog_conn(char *host, int port, Clog *out);
int clog_listen(char *host, int port, int type, Clog *out);
int clog_recv(Clog str, char *msg, int size);
void clog_closeStream(Clog *stream);

/* UDP */
int clog_recvUdp(Clog *stream, char *buf, int data_len);

typedef void(*clog_callback)(Clog stream);

#endif
