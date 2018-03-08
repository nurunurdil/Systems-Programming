/*
*@author: Nuru Nurdil
*/

#include <stdio.h>
#include <sys/stat.h>
/*
#include <sys/ioctl.h>
#include <dirent.h>
#include <pwd.h>
*/
char option;
char *path;
char *fileName;

//Set the option of the ls command
static void setOption(char *argv) {
	option = *argv;
}

//Check if the option requires additional fileName
static int checkFileNameNecessity(char option, int argc) {
	return 0;
}

//Print the list
static void getList(int fileNeeded, char *fileName) {

}

int		main(int argc, char *argv []) {
	//The following is the main class for the 'LS' project in Systems Programming class

	/*
	//Checking the number of inputted parameters
	if (argc < 1) {
		printf("Not enough parameters for list function\n");
		//exit(1);
		return 0;
	}
	*/


	setOption(argv[1]);
	int fileNeeded = checkFileNameNecessity(option, argc);
	getList(fileNeeded, fileName);
	
}