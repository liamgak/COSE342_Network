//2017320229.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define SERVER_PORT 47500
int main(){

	struct sockaddr_in sin;
	char tdata[]="2017320229\0";
	int tdatalen=strlen(tdata);
	int s;
	
	/* build address data structure */
	//bzero((char *)sin, sizeof(sin));
	memset(&sin, 0, sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_port=htons(SERVER_PORT);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");

	/* active open */
	/* socket for accessing server */
        if((s=socket(PF_INET,SOCK_STREAM,0)) < 0 ){
		perror("simplex-talk: socket");
		exit(1);
	}
	if(connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0){
		perror("simplex-talk: connect");
		close(s);
		exit(1);
	}
	
	/*send lines of text*/
	send(s,tdata,tdatalen+1,0);

	return 0;
}
