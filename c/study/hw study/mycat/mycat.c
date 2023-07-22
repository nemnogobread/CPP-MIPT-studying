#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int check_files( int argc, char* argv[] );

int cat_with_args();

int cat_without_args();

int main( int argc , char* argv[] )
{
    if ( argc == 1 )
    {
        return cat_without_args();
    }

    int index_err_file = check_files( argc , argv );
    
    if ( index_err_file )
    {
        char err_msg[200] = "";
        strcat( err_msg , "cat: " );
        strcat( err_msg , argv[index_err_file] );
        strcat( err_msg , ": Нет такого файла в каталоге или нет необходимых прав доступа к нему \0" );
        puts( err_msg );
        return 1;
    }

    cat_with_args( argc , argv );

    return 0;
}


int check_files( int argc , char* argv[] )
{
    for ( int i = 1 ; i < argc ; i++ )
    {
        if ( access( argv[i] , R_OK ) != 0 )
            return i;
    }
    return 0;
}


int cat_with_args( int argc , char* argv[] )
{
    for ( int i = 1 ; i < argc ; i++ )
    {
        char line[ 4096 ] = { 0 };
        int fd = open( argv[i] , O_RDONLY );
        
        while ( read( fd , line , 4096 ) )
            write( 1 , line , 4096 );

        close( fd );
    }
    return 0;
}


int cat_without_args()
{
    
    while ( 1 )
    {
        char line[ 4096 ] = { 0 };
        read( 0 , line , 4096 );
        write( 1 , line , 4096);
    }

    return 0;
}