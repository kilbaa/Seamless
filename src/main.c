#include <net.h>

int send_message(clog_HTTP *http, char receiver_ip){
    char message = ""; // This will be the message content
    clog_AddHeader(&http, "receiver", receiver_ip);
    clog_AddHeader(&http, "image", "Some type of image data");
    clog_AddBody(&http, message);
}

int receive_message(clog_HTTP *http){
    // How does this work? Has to be able to listen for a message and at the same time send a message
}

int main() {
    char ip_host = "83.226.149.233";
    char ip_user = ""; // This will be the ip of receiver
    char port = "8005";
    // Have to figure out a way to store/send images (png or what)
    clog_HTTP http = clog_InitGET(ip_host, port);
    send_message(&http, ip_user);
    clog_GET(&http);
    return 0;
}
