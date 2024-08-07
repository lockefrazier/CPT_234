/*
    Example from book.
*/

#include <stdio.h>

int main (void)
{
    unsigned int account; // account number
    char name[ 30 ]; // account name
    double balance; // account balance

    FILE *cfPtr; // cfPtr = clients.dat file pointer

    // fopen opens file. Exit program if unable to create file.
    if ( ( cfPtr = fopen( "clients.dat", "r") ) == NULL ) {
        puts( "File could not be opened." );
    } // end if
    else {
        printf( "%-10s%-13s%s\n", "Account", "Name", "Balance");
        fscanf( cfPtr, "%d%29s%lf", &account, name, &balance );

        // write account, name and balance into file with fprintf
        while ( !feof( cfPtr ) ) {
            printf( "%-10d%-13s%7.2f\n", account, name, balance );
            fscanf( cfPtr, "%d%29s%lf", &account, name, &balance );
        } // end while

        fclose( cfPtr ); // fclose close file
    } // end else
} // end main