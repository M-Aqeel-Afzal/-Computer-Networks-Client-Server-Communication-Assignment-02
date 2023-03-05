#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include<iostream>
#include <signal.h>
#include<string.h>
#include <unistd.h>
using namespace std;
int main()
{
int ser_FD, cli_FD;
socklen_t ser_len, cli_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;
char ch[1024]={};
char str1[1024]={};
char str2[1024]={};
char ch1[]="Please Enter String one";
char ch2[]="Please Enter String two";
char ch3[]="Please Enter the String";
char ch4[]="Please Enter the character you want to search";
char ch5[]="Please Enter first number in string form";
char ch6[]="Please Enter second number in String form";
ser_FD = socket(AF_INET, SOCK_STREAM, 0);

server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = htonl(INADDR_ANY);
server_address.sin_port = htons(9734);
ser_len = sizeof(server_address);
bind(ser_FD, (struct sockaddr *)&server_address,ser_len);



listen(ser_FD, 5);
signal(SIGCHLD, SIG_IGN);
cout<<"        <====> Main Menu <====>     "<<endl;
cout<<"1: Concatenate two strings"<<endl;
cout<<"2: Find the first occurrence of a character in a string"<<endl;
cout<<"3: Compares two strings"<<endl;
cout<<"4: Checks whether string is palindrome or not"<<endl;
cout<<"5: String Number Addition"<<endl;


while(1) {
//char ch;

cli_len = sizeof(client_address);
cli_FD = accept(ser_FD,(struct sockaddr *)&client_address, &cli_len);




if(fork() == 0) {



 recv(cli_FD, &ch, sizeof(ch), 0);

if(ch[0]=='1')
{
 send(cli_FD, &ch1, 1024, 0);

 recv(cli_FD, &str1, sizeof(str1), 0);

 send(cli_FD, &ch2, 1024, 0);

 recv(cli_FD, &str2, sizeof(str2), 0);



string f1(str1),f2(str2);
f1=f1+f2;
strcpy(ch1,f1.c_str());
send(cli_FD, &ch1, 1024, 0);
}



else if(ch[0]=='2')
{
 send(cli_FD, &ch3, 1024, 0);

 recv(cli_FD, &str1, sizeof(str1), 0);

 send(cli_FD, &ch4, 1024, 0);

 recv(cli_FD, &str2, sizeof(str2), 0);
string s5;
string s4="$";

for(int i=0;i<5;i++)
{

if(str2[0]==str1[i])
{

s4=to_string(i);

break;
}

}

if(s4[0]=='$')
 s5="Character not found";
else
 s5="character is found at index: "+s4;
strcpy(ch1,s5.c_str());
send(cli_FD, &ch1, 1024, 0);
}


else if(ch[0]=='3')
{
 send(cli_FD, &ch1, 1024, 0);

 recv(cli_FD, &str1, sizeof(str1), 0);

 send(cli_FD, &ch2, 1024, 0);

 recv(cli_FD, &str2, sizeof(str2), 0);

string f1=str1,f2=str2,s5;

if (strcasecmp(f1.c_str(), f2.c_str()) == 0)
{
   s5="True";
}
else
s5="False";
strcpy(ch1,s5.c_str());
send(cli_FD, &ch1, 1024, 0);
}


else if(ch[0]=='4')
{
 send(cli_FD, &ch3, 1024, 0);

 recv(cli_FD, &str1, sizeof(str1), 0);

 
string f1=str1,f2=str2,s5="True";

int l = strlen(str1);
   
    for(int i=0;i < l ;i++){
        if(str1[i] != str1[l-i-1]){
            s5="False";
            break;
   }
}
strcpy(ch1,s5.c_str());
send(cli_FD, &ch1, 1024, 0);
}



else if(ch[0]=='5')
{
 send(cli_FD, &ch5, 1024, 0);

 recv(cli_FD, &str1, sizeof(str1), 0);

 send(cli_FD, &ch6, 1024, 0);

 recv(cli_FD, &str2, sizeof(str2), 0);
string f1=str1,f2=str2,s5;
int i1,i2;
if(f1=="zero"||f1=="Zero")
i1=0;
else if(f1=="one"||f1=="One")
i1=1;
else if(f1=="two"||f1=="Two")
i1=2;
else if(f1=="three"||f1=="Three")
i1=3;
else if(f1=="four"||f1=="Four")
i1=4;
else if(f1=="five"||f1=="Five")
i1=5;
else if(f1=="six"||f1=="Six")
i1=6;
else if(f1=="seven"||f1=="Seven")
i1=7;
else if(f1=="eight"||f1=="Eight")
i1=8;
else if(f1=="nine"||f1=="Nine")
i1=9;
else
i1=0;

if(f2=="zero"||f2=="Zero")
i2=0;
else if(f2=="one"||f2=="One")
i2=1;
else if(f2=="two"||f2=="Two")
i2=2;
else if(f2=="three"||f2=="Three")
i2=3;
else if(f2=="four"||f2=="Four")
i2=4;
else if(f2=="five"||f2=="Five")
i2=5;
else if(f2=="six"||f2=="Six")
i2=6;
else if(f2=="seven"||f2=="Seven")
i2=7;
else if(f2=="eight"||f2=="Eight")
i2=8;
else if(f2=="nine"||f2=="Nine")
i2=9;
else
i2=0;
i1=i1+i2;
if(i1==0)
f1="Zero";
if(i1==1)
f1="One";
if(i1==2)
f1="Two";
if(i1==3)
f1="Three";
if(i1==4)
f1="Four";
if(i1==5)
f1="Five";
if(i1==6)
f1="Six";
if(i1==7)
f1="Seven";
if(i1==8)
f1="Eight";
if(i1==9)
f1="Nine";
if(i1==10)
f1="Ten";
if(i1==11)
f1="Eleven";
if(i1==12)
f1="Twelve";
if(i1==13)
f1="thirteen";
if(i1==14)
f1="Fourteen";
if(i1==15)
f1="Fifteen";
if(i1==16)
f1="Sixteen";
if(i1==17)
f1="Seventeen";
if(i1==18)
f1="Eighteen";
strcpy(ch1,f1.c_str());
send(cli_FD, &ch1, 1024, 0);
}










cout<<"Information sent "<<endl;
close(cli_FD);
exit(0);
}



else {
close(cli_FD);
}

}
}
