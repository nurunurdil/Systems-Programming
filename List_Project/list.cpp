/*
*@author: Nuru Nurdil
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <pwd.h>

short option = 0;
char *path;
char *fileName;
void setOption(char opt);

//Set the option of the ls command
static void setOption(char opt) {
	switch(opt){
		//Upper-case letters set the last 3 bits of the short number 'option'
		case 'A':
			option = option | (1<<0);
			break;
		case 'R':
			option = option | (1<<1);
			break;
		case 'S':
			option = option | (1<<2);
			break;
		
		//Lower-case letters set the other 11 bits of the short number 'option'
		case 'a':
			option = option | (1<<3);
			break;
		case 'c':
			option = option | (1<<4);
			break;
		case 'd':
			option = option | (1<<5);
			break;
		case 'f':
			option = option | (1<<6);
			break;
		case 'h':
			option = option | (1<<7);
			break;
		case 'i':
			option = option | (1<<8);
			break;
		case 'l':
			option = option | (1<<9);
			break;
		case 'n':
			option = option | (1<<10);
			break;
		case 'r':
			option = option | (1<<11);
			break;
		case 't':
			option = option | (1<<12);
			break;
		case 'u':
			option = option | (1<<13);
			break;	
	}
}

//Check if the option requires additional fileName
static int checkFileNameNecessity(char option, int argc) {
	return 0;
}

//Print the list
static void getList(int fileNeeded, char *fileName) {

}

int		main(int argc, char *argv []) {
	int opt;
	//The following is the main class for the 'LS' project in Systems Programming class

	/*
	//Checking the number of inputted parameters
	if (argc < 1) {
		printf("Not enough parameters for list function\n");
		//exit(1);
		return 0;
	}
	*/

	while((opt = getopt(argc,argv,"AacdFfhilnRrStu")) != -1){
		setOption(opt);
	}


	int fileNeeded = checkFileNameNecessity(option, argc);
	getList(fileNeeded, fileName);
	
}