#include <errors.h>
#include <stdio.h>

void errorMessage(char *msg, ...) {
    printf("ERROR: ");

    va_list ptr;
    va_start(ptr, msg);
    vfprintf(stderr, msg, ptr);
    va_end(ptr);
}

int httpErrorHandle(HTTP http) {
    // Handle errors made while connecting to server
    if(http.conn_status < 0) {
	int err = WSAGetLastError();
	switch(err) {
	    case WSAECONNREFUSED: errorMessage("Connection refused, server might be down.\n"); break;
	    default: errorMessage("WSA Error %d\n", err); break;
	}
	return HTTP_ERROR;
    }

    // Handle errors the server have returned
    char code = http.body[0];

    if(code != '0') {
	printf("%s\n", http.body + 1);
	return HTTP_ERROR;
    }

    return 0;
}
