
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<iostream>
#define PORT	 8080
#define MAXLINE 1024
using namespace std;
int main() {
	int sock_FD;
	char buffer[MAXLINE];
	char hello[] ="Message from Client 3... I am Active---😊️";
	struct sockaddr_in	 servaddr;

	                                                      // Creating socket
	if ( (sock_FD = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n;
	socklen_t len;
	char choice,choice1;
	string amount="",balance="",ret="";
	char cr[1024];
	
		

  		
//while(1)
//{

		sendto(sock_FD, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));
		cout<<"Message has been sent.\n"<<endl;
			
		n = recvfrom(sock_FD, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
		
		cout<<buffer[0]<<endl;
		if(buffer[0]=='1')
		{
		
		ret="(Client 3)==> Card has been varified!";
		}
		if(buffer[0]=='2')
		{
	
		ret="(Client 3)==> Pin has been varified!";
		}
		if(buffer[0]=='3')
		{int a,b;
		char *pk;
    		char *tk = strtok(buffer, "-");
		      tk = strtok(NULL, "-");
                balance=tk;
		      tk = strtok(NULL, "-");
                amount=tk;
		b=stoi(balance);
		a=stoi(amount);
		b=b-a;
		cout<<"Balance: "<<b<<"    Amount: "<<a<<endl;
		ret="(Client 3)==> Deposit Successful!...Your new account balance is: "+to_string(b);
		}

strcpy(cr,ret.c_str());
sendto(sock_FD, cr, strlen(cr),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));
		cout<<"Message has been sent.\n"<<endl;

//}
	close(sock_FD);
	return 0;
}
