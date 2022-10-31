#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

void testCopy(char* fileCopy, char* fileNew)
{
	// find out the file size
	int count;
	FILE* fCopy;
	FILE* fNew;
	char* memory;
	count = 0;
	int read = 0;
	char tmp;

	// Opens the file for reading
	fCopy = fopen(fileCopy, "r");
	if (fCopy)
	{
		// Reads the amount of characters written in the file
		while ((read = fread(&tmp, sizeof(char), 1, fCopy)) > 0)
		{
			count = count + read;
		}
		fclose(fCopy);

		// Takes up space in memory the size of the file
		memory = (char*)malloc(count);

	}
	else
	{
		printf("\nerror - The file does not exist");
		exit(1);
	}



	// read all file into memory
	fCopy = fopen(fileCopy, "r");
	if (fCopy)
	{
		// Copies the string into the pointer
		int readPackages = fread(memory, sizeof(char), count, fCopy);
		fclose(fCopy);
	}
	else
	{
		printf("\nerror - The file does not exist");
		exit(1);
	}

	// write all memory into file
	fNew = fopen(fileNew, "w");
	if (!fNew)
	{
		printf("\nerror - The file did not open");
		exit(1);
	}
	else
	{
		fwrite(memory, sizeof(char), count, fNew);
		fclose(fNew);
		free(memory);
	}
}

int main(int argc, char* argv[])
{
	testCopy("name.txt", "newFile.txt");

	return 0;
}