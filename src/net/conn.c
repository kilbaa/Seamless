#include <conn.h>
#include <stdio.h>

int sendGet(clog_HTTP *c_http, char *body, Header *headers) {
    if(headers != NULL)
	for(; headers->key != NULL; headers++)
	    clog_AddHeader(c_http, headers->key, headers->val);

    clog_AddBody(c_http, body);
    return clog_GET(c_http);
}

HTTP get(char *body, Header *headers) {
    clog_HTTP c_http = clog_InitGET(IP, PORT);
    int err = sendGet(&c_http, body, headers);

    HTTP http;
    http.conn_status = err;
    http.body = c_http.body;
    http.data = c_http.data;

    return http;
}

int tcpConnect(){
    Clog clog;
    clog_conn("192.168.1.95", 8001, &clog);
    char string[4] = "adsw"; //fk u
    clog_send(&clog, string, sizeof(string));
    while(1){

    }
    return 0;
}
