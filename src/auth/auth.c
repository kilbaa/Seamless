#include <auth/auth.h>
#include <errors.h>
#include <stdio.h>
#include <conn.h>
#include <net.h>

void loginAccount() {
}

void createAccount() {
    HTTP http;
    Header headers[] = {
	{ "Type", "Create" },
	{ "User", "Henry" },
	{ "Pass", "123abc" },
	HEADER_END
    };

    http = get(NULL, headers);
    if(httpErrorHandle(http)) return;
    http = get("4321", headers);
    if(httpErrorHandle(http)) return;
}
