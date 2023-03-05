#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
#include<ctime>
#include<iostream>
#define PORT	 8080
#define MAXLINE 1024
using namespace std;

int main() {
	int sock_FD;
	char buffer[MAXLINE];
	char buffer1[MAXLINE];
	char buffer2[MAXLINE];
	
char buffer3[MAXLINE];
char *ip_addr1;
char myIP1[20];

char myIP2[20];
char myIP3[20];
//char *ip_addr2;
//char *ip_addr3;
	char hello[] = "";
	struct sockaddr_in servaddr, cliaddr;
	
	
	if ( (sock_FD = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	
	
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Binding
	if ( bind(sock_FD, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("binding failed");
		exit(EXIT_FAILURE);
	}
	srand(time(0));
	int n,choice=0,ran1=0,ran2=0,ran3=0;
	int amount=0,balance=0;
	string s1,s2,s3,f1="0",f2="0",f3="0";
	socklen_t len;
	
	again:
	cout<<"<===>  ATM Functions which are to be performed  <===>\n\n"<<endl;
	cout<<"1.  Card Reading"<<endl;
	cout<<"2.  Pin Verification"<<endl;
	cout<<"3.  Cash Withdraw\n\n\n"<<endl;

	cout<<"<=====>    Main Menu    <=====>\n\n"<<endl;
	cout<<"Press 1 if you want to Withdraw Cash."<<endl;
	cout<<"press 2 to exit the system\n\n"<<endl;
	cin>>choice;
	if(choice==2)
	exit(0);
	else if(choice==1)
	{
	balance=rand()%50000;
	cout<<"Enter Amount to withdraw: "<<endl;
	cin>>amount;
		while(amount<0||amount>25000)
		{
		cout<<"\nWrong input--☹️\n"<<endl;
		cout<<"Your current balance is: "<<balance<<endl;
		cout<<"Enter Amount to withdraw again: "<<endl;
		cin>>amount;
		}

		while(amount>balance)
		{
		cout<<"\nEntered Amount is greater then the balance--☹️\n"<<endl;
		cout<<"Your current balance is: "<<balance<<endl;
		cout<<"Enter Amount to withdraw again: "<<endl;
		cin>>amount;
		}
	goto start;
	
	}
	else
	{
	cout<<"Wrong input--☹️"<<endl;
	goto again;
	}


start:
	len = sizeof(cliaddr); 

	
	
		//for(int i=0;i<10;i++)
		//{
			
		ran1=rand()%4;
		while(ran1==0)
		{
		cout<<"Transection Failed---☹️\n"<<endl;
		ran1=rand()%4;
		}
		ran2=rand()%4;
		while(ran2==0||ran2==ran1)
		{
		ran2=rand()%4;
		}
		ran3=rand()%4;
		while(ran3==0||ran3==ran2||ran3==ran1)
		{
		ran3=rand()%4;
		}


s1=to_string(ran1);
s1=s1+"-";
s1=s1+to_string(balance);
s1=s1+"-";
s1=s1+to_string(amount);
char const *str1=s1.c_str();




s2=to_string(ran2);
s2=s2+"-";
s2=s2+to_string(balance);
s2=s2+"-";
s2=s2+to_string(amount);
char const *str2=s2.c_str();



s3=to_string(ran3);
s3=s3+"-";
s3=s3+to_string(balance);
s3=s3+"-";
s3=s3+to_string(amount);
char const *str3=s3.c_str();
	
cout<<"\n\nCurrent Balance is: "<<balance<<endl;
cout<<"Amount to withdraw is: "<<amount<<endl;	
cout<<"Clients will handle the requests in the following sequence"<<endl;
		cout<<"Client 1 will perform task: "<<str1[0]<<endl;
		cout<<"Client 2 will perform task: "<<str2[0]<<endl;
		cout<<"Client 3 will perform task: "<<str3[0]<<endl;

		//}



		
again1:

									//client1
		n = recvfrom(sock_FD, (char *)buffer, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
		cout<<buffer<<endl;
if(buffer[20]=='2')
goto cl2;
if(buffer[20]=='3')
goto cl3;

cl1:
		sendto(sock_FD, str1, strlen(str1),
			0, (const struct sockaddr *) &cliaddr,
				len);


			n = recvfrom(sock_FD, (char *)buffer1, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
     inet_ntop(AF_INET, &cliaddr.sin_addr, myIP1, sizeof(myIP1));
//cout<<myIP1<<endl;
	// ip_addr1=inet_ntoa(servaddr.sin_addr);
//cout<<ip_addr1<<endl;
		
f1=buffer1;
	
if(f2[0]!='0'&&f3[0]!='0')
goto end;
             





									//client 2


		n = recvfrom(sock_FD, (char *)buffer, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
cout<<buffer<<endl;
if(buffer[20]=='1')
goto cl1;
if(buffer[20]=='3')
goto cl3;		
cl2:
		sendto(sock_FD, str2, strlen(str2),
			0, (const struct sockaddr *) &cliaddr,
				len);

			n = recvfrom(sock_FD, (char *)buffer2, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
 inet_ntop(AF_INET, &cliaddr.sin_addr, myIP2, sizeof(myIP2));
//cout<<myIP2<<endl;
//ip_addr2=inet_ntoa(servaddr.sin_addr);
		f2=buffer2;


	
if(f1[0]!='0'&&f3[0]!='0')
goto end;




									//client 3

		n = recvfrom(sock_FD, (char *)buffer, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
		cout<<buffer<<endl;
if(buffer[20]=='1')
goto cl1;
if(buffer[20]=='2')
goto cl2; 
cl3:  
		sendto(sock_FD, str3, strlen(str3),
			0, (const struct sockaddr *) &cliaddr,
				len);

			n = recvfrom(sock_FD, (char *)buffer3, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
//ip_addr3=inet_ntoa(servaddr.sin_addr);
 inet_ntop(AF_INET, &cliaddr.sin_addr, myIP3, sizeof(myIP3));
//cout<<myIP3<<endl;
		f3=buffer3;
end:
	
if(f1[0]!='0'&&f2[0]!='0')
	{cout<<"\n\n"<<f1<<endl;
	cout<<f2<<endl;
	cout<<f3<<endl;
	cout<<"IP Address Client 1 is: "<<myIP1<<endl;
	cout<<"IP Address Client 2 is: "<<myIP2<<endl;
	cout<<"IP Address Client 3 is: "<<myIP3<<endl;
}
else
goto again1;
 
    
 	


		
	
	return 0;
}
