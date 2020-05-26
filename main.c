/* snippet from https://www.iiitd.edu.in/~jalote/papers/CommonBugs.pdf 
 * 2.1.1 Memory leaks 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* compiled with 'gcc main.c -Wall -pedantic' and 'clang main.c -Wall -pedantic', no warning occurred
 *   prints an empty line
 */

char* foo(int s) {
    char * output ;
    if (s > 0)
        output =(char*) malloc(s);
    
    if (s == 1)
        return NULL;

    /* if s >0 and s ==1 then , * allocated memory for output * is leaked */
    return output; 
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("USAGE: %s <INT>", argv[0]);
        return 1;
    }
    printf("%s\n", foo(atoi(argv[1])));
    return 0;
}
