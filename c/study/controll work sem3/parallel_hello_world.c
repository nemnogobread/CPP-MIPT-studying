#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define SUCCESS               0
#define NUM_THREADS          11
#define BAD_MESSAGE         -13


typedef struct someArgs_tag
{
    int id;
    char msg;
} someArgs_t;


void* helloworld( void *args ) 
{
    someArgs_t *arg = ( someArgs_t* ) args;
    if ( arg -> msg == NULL) 
    {
        return BAD_MESSAGE;
    }
    printf( "%c" , arg -> msg );
    
    return SUCCESS;
}


int main( int argc , char** argv )
{
    pthread_t threads[ NUM_THREADS ];
    int status;
    int i;
    someArgs_t args[ NUM_THREADS ];
    int status_addr;
    const char message[] = { "hello world" };

    for ( i = 0 ; i < NUM_THREADS ; i++ ) 
    {
        args[i].id = i;
        args[i].msg = message[i];
    }

    for ( i = 0 ; i < NUM_THREADS ; i++ ) 
    {
        status = pthread_create( &threads[i] , NULL , helloworld , (void*) &args[i] );
        if ( status != 0 ) 
        {
            printf( "main error: can't create thread, status = %d\n" , status );
            exit( ERROR_CREATE_THREAD );
        }
    }
 
    for ( i = 0 ; i < NUM_THREADS ; i++ ) 
    {
        status = pthread_join( threads[i] , (void**)&status_addr );
        if ( status != SUCCESS ) 
        {
            printf("main error: can't join thread, status = %d\n", status);
            exit(ERROR_JOIN_THREAD);
        }
        printf("joined with address %d\n", status_addr);
    }

    return 0;
}


