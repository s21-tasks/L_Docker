#include <fcgiapp.h>
#include <stdio.h>

int main() {
    while (FCGI_Accept() >= 0) {
        printf("Content-Type: text/html\r\n\r\n");
        printf("<html><head><title>Hello World</title></head><body>");
        printf("<h1>Hello World!</h1>");
        printf("</body></html>");
    }

    return 0;
}