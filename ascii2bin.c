/********************************/
/* Program Name: Checksum.c     */
/* Author: Garrette Clarke      */
/* Date:    3/4/21             */
/********************************/
/* Description: Reads in binary digits as ASCII digits and outputs the equivalent unsigned decimal number. */
/* Validation Checks: Checks that each ASCII input character is one of the following characters 0,1, or \n. 
Checks that the calculated number does not exceed 2^32. */
/* Enhancements:                */
/********************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <string.h>
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {


    int offset = 0x30;
    int number = 0;
    int retval;
    int digit;
    byte ascii_value;
    
    retval = read(STDIN_FILENO, &ascii_value, 1);
    while (retval == 1){
    
        if (digit == 0 || digit == 1) { 
            digit = ascii_value - offset;
            number = (number << 1) + digit;  
            retval = read(STDIN_FILENO, &ascii_value, 1);
        } 
        else return 1; 
    }
    
    if (number < 4294967296){    
      printf("%u\n", number);
      return 0;
    }
    
}