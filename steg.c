// steg so far. 

// ./steg -(bB) -(sr) -o<val> [-i<val>] -w<val> [-h<val>]
// ./steg -B -s -o1024 -i256 -wimage.jpg -hsecret.jpg > new.jpg
// ./steg -B -r -o1024 -i256 -wnew.jpg > extracted.jpg
// above is what the command line will look like


//stuff to include libraries for certain functions, esp. math and system arguments and image stuff

//#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
//#include <math.h>

int sentinel[] = {0x0, 0xff, 0x0, 0x0, 0xff, 0x0};

void main (int argc, char* argv[])
{
	// update: not doing separate functions for bit/byte. Gonna use a lot of if statements in main. It's easier that way.
	
	if (argc < 6)
		printf("Not enough arguments.\n\n");
	
	// gets offset value from command line by taking substring, converting to int
	char* num = argv[3];
	char *to = "-o";
	char *o = strtok(num, to);
	int offset = atoi( o );
	printf("offset: %d\n", offset);

	// gets interval value from command line by taking substring, converting to int
	char* mun = argv[4];
	char *ot = "-i";
	char *i = strtok(mun, ot);
	int interval = atoi( i );
	printf("interval: %d\n", interval);
	
	//gets wrapper file name by seeking substring beyond a certain token, coverting to FILE
	char* wraps = argv[5];
	char *w = "-w";
	char* wr = strtok(wraps, w);
	printf("%s\n", wr);
	// opens file that matches char* variable above, and reads binary
	//FILE* fopen(wr, rb);
	
		//gets hidden file name by seeking substring beyond a certain token, coverting to FILE
	char* hide = argv[6];
	char *h = "-h";
	char* hi = strtok(hide, h);
	printf("%s\n", hi);
	// opens file that matches char* variable above, and reads binary
	//FILE* fopen(hi, rb);
	
	// will execute for byte
	if (strcmp(argv[1], "-B") == 0) 
	{
		//for (int i=0; i < argc; i++)
		//	printf("%s\n",argv[i]);
		
		// store
		if (strcmp(argv[2], "-s") == 0)
		{
			printf("Storage\n");
			int i = 0;
			/*
			while i < length(H):
				W[o] = H[i];
				o += I;
				i++;*/
		}
		
		// retrieve
		if (strcmp(argv[2], "-r") == 0)
		{
			printf("Retrieval\n");
			int i = 0;
			// put more here
		}
		
		printf("This will be the byte function\n");
	}
	
	// will execute for bit
    else if (strcmp(argv[1], "-b") == 0)
	{
		//for (int i=0; i < argc; i++)
		//	printf("%s\n",argv[i]);
		
		// store
		if (strcmp(argv[2], "-s") == 0)
		{
			printf("Storage\n");
			/*
			i = 0;
			j = 0;
			while j < length(H):
				for k = 0..7:
					W[i] &= 11111110
					W[i] |= ((H[j] & 10000000 >> 7))
					H[j] <<= 1
					i += I
				j++
			end while
			*/

		}
		
		// retrieve
		if (strcmp(argv[2], "-r") == 0)
		{
			printf("Retrieval\n");
			// put more here
			/*
			i = 0;
			j = 0;
			while j < length(W):
				for k = 0..7:
					// put more here
				
	 		 */
		}
		printf("this will be the bit function\n");
	}
	
	// if something incorrect is printed
	else
	    printf("%s is not a valid method type.\n", argv[1]);
}
