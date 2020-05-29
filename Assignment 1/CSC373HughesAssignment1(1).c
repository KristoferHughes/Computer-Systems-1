#include   <stdlib.h>
#include   <stdio.h>
#include   <limits.h>

const int   LINE_LEN   = 256;
const int   MIN_LENGTH   = 2;
const int   MAX_LENGTH   = 16;




// PURPOSE: To ask the user to enter an integer between 'MIN_LENGTH' and
//   'max'. Repeated asks user until such an integer has been entered.
//   Returns entered integer.
int       getLength   (int   max
               )
{
        int   toReturn;
        char   line[LINE_LEN];
        do {
                printf("Enter an array length (%d to %d): ", MIN_LENGTH, max);
                scanf("%d", &toReturn);

        } while(toReturn < MIN_LENGTH || toReturn > max);
		const int MAX_LENGTH = toReturn;
        return(toReturn);
}


// PURPOSE: To create an array on integers on the heap of length 'length',
//   and let user enter each integer. Returns array.
int*       createArray   (int   length
               )
{
        int*   array   = (int*)calloc(length,sizeof(int));
        int   i;
        char   line[LINE_LEN];

        for(i=0; i<length; i++) {
                printf("Enter element %d: ", i);
                scanf("%d", &array[i]);
        }

        return(array);
}


// PURPOSE: To iterate over the 'length' integers of
//   'array', and set '*lowest1stPtr' to the lowest integer and set
//   'lowest2ndPtr' equal to the second lowest integer. (They may be the
//   same number if the lowest appears twice.) If the lowest does appear
//   twice then it returns '1', otherwise it returns '0'.
int       areLowestEqual   (const int*   array,
               int       length,
               int*       lowest1stPtr,
               int*       lowest2ndPtr
               )
{
        int varEqual = 0;
        int   i;
        *lowest1stPtr = INT_MAX;
        *lowest2ndPtr = INT_MAX;

        for(i=0; i<length; i++) {
                
                if(array[i] <= *lowest1stPtr) {
                        if(array[i] == *lowest1stPtr) {
                                *lowest2ndPtr = array[i];
                                varEqual = 1;
                        } else {
                                *lowest2ndPtr = *lowest1stPtr;
                                *lowest1stPtr = array[i];
                        }
                } else if(array[i] < *lowest2ndPtr) {
                        *lowest2ndPtr = array[i];
                }

        }

        return varEqual;
}


int       main       ()
{
        int       length   = getLength(MAX_LENGTH);
        int*       array   = createArray(length);
        int       lowest;
        int       secondLowest;
        int       areEqual= areLowestEqual(array,length,&lowest,&secondLowest);

        printf("The 1st lowest is: %d\n"
        "The 2nd lowest is: %d\n"
           "They %sare equal.\n",
           lowest,secondLowest,
           areEqual ? "" : "not "
           );
        free(array);
}