#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<iostream>
using namespace std;
int main()
{
    int sid;
    char s[1024]={},s1[1024]={},s2[1024]={},f4;
	int choice;
	string str1,str2;
	char str3[1024],str4[1024];
    struct sockaddr_in ssock,csock;
    sid=socket(AF_INET,SOCK_STREAM,0);
    ssock.sin_family=AF_INET;
    ssock.sin_addr.s_addr=inet_addr("127.0.0.1");
    ssock.sin_port=htons(9734);
    connect(sid,(struct sockaddr *)&ssock,sizeof(ssock));
    
        printf("\n Enter your choice:");
        cin>>s;
	cout<<s<<endl;
	f4=s[0];
        send(sid, &s, 1024, 0);
        
        recv(sid, &s1, sizeof(s1), 0);
        cout<<"Received: "<<s1<<endl;
    	 
	cin.ignore();
	cin.getline(str3,200);
	str1=str3;
	strcpy(s,str1.c_str());
	send(sid, &s, 1024, 0);

if(f4!='4')
       {
        recv(sid, &s1, sizeof(s1), 0);
        cout<<"Received: "<<s1<<endl;
	 if(f4=='2')
	{
	cin>>str4;

	}
	else {
	cin.getline(str4,200);}
	str2=str4;
	

	strcpy(s1,str2.c_str());
	send(sid, &s1, 1024, 0);
}

recv(sid, &s2, sizeof(s2), 0);
        cout<<"Received: "<<s2<<endl;

    close(sid);
return 0;
}
