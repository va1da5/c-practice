#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80

int main(void)
{
    char host[] = "ifconfig.me";

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0)
    {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }

    close(sockfd);

    return 0;
}