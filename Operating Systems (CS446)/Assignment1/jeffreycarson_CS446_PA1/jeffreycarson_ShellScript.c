//Jeffrey Carson Shell Script
//The purpose of this project is to create your own custom shell, with functionality for commands such as cd, help, exit, write copy, and any execvp() executable command. The part of this project that pertains to operating systems mostly is the use of the fork() command, which launches a new process running in parallel to main. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

//Prototypes
void promptUser(bool isBatch);
void printError();
int parseInput(char *input, char *splitWords[]);
char *redirectCommand(char *cmd, char *line, bool *isRedirect, char *tokens[], char *outputTokens[]);
char *executeCommand(char *cmd, bool *isRedirect, char* tokens[], char* outputTokens[],  bool *isExits);

bool exitProgram(char *tokens[], int numTokens);

void launchProcesses(char *tokens[], int numTokens, bool isRedirect);

void changeDirectories(char *tokens[], int numTokens);

bool multipleArrows(char * arr);

void printHelp(char *tokens[]);

char * removeWhiteSpace(char * arr);



int main(int argc, char * argv[]){

	bool isBatchFile = 0; //not batch file by default
	bool * isRedirect = false; 
	_Bool isExits = false;
	char batchArr[10][300];
	char * parsedArr[100];
	char * tempParsed[100];
	char tester[80] = {0};
	int tempNum, temp;
	char command[20];
	int numParsed = 0;
	int numBatchArgs = 0;
	
	FILE * ifp; //input file pointer (read)
	
	if (argc == 1){	
		//isBatchFile is already 0.
	}
	else{
		isBatchFile = 1; //true
		
	}
	promptUser(isBatchFile);
	
	if (isBatchFile){
		//read from file, loop for how many lines present in file and execute commands sequentially in loop
		
		
		ifp = fopen(argv[1], "r");
		
		if (ifp == NULL){
			printf("File cannot be opened\n");
			return 1;
		}
		int i = 0;
		while(fgets(tester, 100, ifp)){

			strcpy(batchArr[i], tester);
			i++;
        }
		fclose(ifp);
		for (int j = 0; j < i; j++){
			printf("%s", batchArr[j]);
			executeCommand(batchArr[j], false, NULL, NULL, false);
		}	
	}
	else{
		//get user input, execute command, repeat until exit is recieved
		while(isExits == 0){
			fgets(command, 100, stdin);
			char * cmdDupl = strdup(command);
			temp = parseInput(cmdDupl, tempParsed);
			isExits = exitProgram(tempParsed, temp);
			if (isExits){
				kill(0, SIGKILL);
			}
			executeCommand(command, false, NULL, NULL, false);
			promptUser(isBatchFile);
		}
	}
	return 0;
}

void promptUser(bool isBatch){
	if (!isBatch){
		char hostname[50];
		char currWorkingDir[100];
		gethostname(hostname, sizeof(hostname));
		getcwd(currWorkingDir, sizeof(currWorkingDir));
		printf("%s@%s:%s$ ", getenv("USER"), hostname, currWorkingDir);
	}
}

void printError(){
	printf("Shell Program Error Encountered\n");
}

//GIVEN BY INSTRUCTOR
//It takes any character array, checks that there are contents in it, then fills the splitWords 2d char array with each argument. It returns the number of arguments that were parsed for use elsewhere. It will be used in redirectCommand() and executeCommand()

int parseInput(char *input, char *splitWords[]){
	int wordInd = 0;
      splitWords[0] = strtok(input, " ");
      while(splitWords[wordInd] != NULL){
              splitWords[++wordInd] = strtok(NULL, " ");
      }

      return wordInd;
}


char *redirectCommand(char *cmd, char *line, bool *isRedirect, char *tokens[], char *outputTokens[]){
	char * cmdDup = strdup(cmd);
	char * inputFile;
	char * outputFile;
	char * inpFile;
	char * outFile;
	char * buffer;
	char temp;
	FILE *iPtr, *oPtr;
	if (!multipleArrows(cmd)){
		inpFile = strtok(cmdDup, ">");
		inputFile = removeWhiteSpace(inpFile);
		//printf("%sX\n", inputFile);
		
		outFile = strtok(NULL, "\n");
		outputFile = removeWhiteSpace(outFile);
		//printf("%sX\n", outputFile);
		
		iPtr = fopen(inputFile, "r");
		if (iPtr == NULL){
			printf("Cannot open input file\n");
		}
		oPtr = fopen(outputFile, "w");
		if (oPtr == NULL){
			printf("Cannot open output file\n");
		}
		
		temp = fgetc(iPtr);
		while (!feof(iPtr)){
			fputc(temp, oPtr);
			temp = fgetc(iPtr);
		}
		printf("Success");
		fclose(iPtr);
		fclose(oPtr);

		return outputFile;
	}
	else{
		printError();
	}
}

char *executeCommand(char *cmd, bool *isRedirect, char* tokens[], char* outputTokens[],  bool *isExits){
	int temp;
	int numTokens = 0;
	
	char * cmdDup = strdup(cmd); //duplicate of *cmd
	
	temp = strlen(cmdDup);
		
	cmdDup[temp-1] = '\0';

	char * parsedCmd[10];
	
	if (strchr(cmdDup, '>') != NULL){
		//*isRedirect == true;
		redirectCommand(cmdDup, NULL, false, NULL, NULL);
		
	}
	else{
		//Not redirect
		*isRedirect == false;
		
		numTokens = parseInput(cmdDup, parsedCmd);
		
		
		
		if (numTokens == 0){
			return NULL;
		}
		exitProgram(parsedCmd, numTokens);
		changeDirectories(parsedCmd, numTokens);
		printHelp(parsedCmd);
		launchProcesses(parsedCmd, numTokens, isRedirect);
		
		return '\0';	
	}
}

bool exitProgram(char *tokens[], int numTokens){
	if (strcmp(tokens[0], "exit\n") == 0){ //if they match
		if (numTokens > 1){
			printError();
			//printf("IN exitProg\n");
		}
		else{
			return 1;
		}
	}
	else{
		return 0;
	}
}

void launchProcesses(char *tokens[], int numTokens, bool isRedirect){
	if (strcmp(tokens[0], "cd") != 0 || strcmp(tokens[0], "help") != 0){
	
		
		int pid = fork();
		int statusCode;
		
		
		
		if (pid != 0){ 
			//main process
			wait(NULL);
		}
		
		if (pid == 0){
			//Child Process
			statusCode = execvp(tokens[0], tokens);
			
			if (statusCode == -1){
				if(strcmp(tokens[0], "cd") == 0 || strcmp(tokens[0], "help") == 0 || strcmp(tokens[0], "exit") == 0){
					
				}else{
					printError();
			//		printf("IN launchProc\n");
				}
			}
		}
	}
}


void changeDirectories(char *tokens[], int numTokens){
	if (strcmp(tokens[0], "cd") == 0){ //if they match
		if (tokens[1] == NULL){
			printError();
			//printf("IN changeDir\n");
		}
		else{
			chdir(tokens[1]);
		}
	}
	
}

void printHelp(char *tokens[]){
	if (strcmp(tokens[0], "help") == 0){ //if they match
		if (tokens[1] != NULL){
			printError();
			//printf("IN printhelp\n");
		}
		else{
			printf("Jeffs linux shell.\n");
			printf("These shell commands are defined internally.\n");
			printf("help\t-prints this screen so you can see available shell commands.\n");
			printf("cd\t-changes directories to specified path; if not given, defaults to home.\n");
			printf("exit\t-closes the example shell\n");
			printf("[input] > [output] -pipes input file into output file\n\n");
			printf("If it's not explicitly defined here, then the command should try to be executed by launchProcesses\n");
			
		}
	}	
}
//custom remove white space func
char * removeWhiteSpace(char * arr){
	int i = 0, j = 0;
	while (arr[i]){
		if (arr[i] != ' ')
          arr[j++] = arr[i];
		i++;
	}
	arr[j] = '\0';
	return arr;
}

bool multipleArrows(char * arr){
	int i = 0, num = 0;
	while (arr[i]){
		if (arr[i] == '>'){
			num++;
		}
		i++;
	}
	if (num > 1){
		return 1;
	} else{
		return 0;
	}


}
