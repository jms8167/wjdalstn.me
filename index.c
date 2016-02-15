#!/usr/bin/cfcf/cfc
#gcc -std=c99 -o %s %s

#include<stdio.h>
#include<cfc_util.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[],char* envp[]){
	int i=0;
	int sum=0;
	char* aaa=param("aaa");
	char* bbb=param("bbb");
	if(aaa && bbb){
		sum=atoi(aaa)+atoi(bbb);
	}
	CGI("Content-Type: text/html; charset=utf-8\n\n");
	CGI("<html>");
	CGI("<head>");
	CGI("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/index.css\">");
	CGI("	<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />");
	CGI("</head>");
	CGI("<body>");
	CGI("<p>%d</p>",sum);
	CGI("	<form action=\"index.c\" method=\"post\">");
	CGI("		<input name=\"aaa\" type=\"text\"></input>");
	CGI("		<input name=\"bbb\" type=\"text\"></input>");
	CGI("		<input type=\"submit\" value=\"plus\"></input>");
	CGI("	</form>");
	CGI("</body>");
	CGI("</html>");
	return 0;
}
