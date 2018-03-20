/*
*@author: Nuru Nurdil
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <pwd.h>

#define FALSE 0
#define TRUE 1


short option = 0; //this short integer stores information about the selected options
int optionWarning = FALSE; // this boolean is needed to know if displaying a warning about the options limitation is required
int statValue;
char *path;
char *fileName;
static void setOption(char opt);
static void addFileToList(struct stat *statValue, char * path);


struct fileEntry{
	char path[255];
	char fileType;
	int linksCount;
	long inodeNumber;
};

//In fact this method adds info (stat) about a file to the list. Not the file itself.
//Named addFileToList in order to be more convenient.
void addFileToList(struct stat *statValue, char * path){
	


}


//Set the option of the ls command
void setOption(char opt) {
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
			option = option & (65535 ^ (1<<13)); // overrides the -u bit to zero using a bit mask
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
			option = option & (65535 ^ (1<<4)); // overrides the -c bit to zero using a bit mask			
			break;
		default:
			optionWarning = TRUE;	
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
	struct stat buf;

	//set the option for each paramaeter
	while((opt = getopt(argc,argv,"AacdFfhilnRrStu")) != -1){
		setOption(opt);
	}

	if(argc==1){
		//This is how we check if the -d flag is set. The -d flag is the 5th. Therefore 2^5=32.
		if(option > (option ^ 32)){
			statValue = lstat(".",&buf);
			if(statValue<0){
				fprintf(stderr,"LStat error occured\n");
				exit(1);
			}
		addFileToList(&buf,".");
		}

		//R Functionality
		if(option > (option ^ 2)){
			if((fd = open("."))<0){
				fprintf(stderr, "Open error occured\n");
				close(fd);
				exit(1);
			}

			if(close(fd) == -1){
				fprintf(stderr, "Close error occured\n");
				exit(1);
			}
		}

	}

	if(optionWarning==TRUE)
		printf("Only AacdFfhilnRrStu are used as options for the scope of this project\n");
	int fileNeeded = checkFileNameNecessity(option, argc);
	getList(fileNeeded, fileName);

	exit(0);
}