#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int isLower( char c ) {
    int ASCIICode = ( int )c;
    if ( ASCIICode >= 97 && ASCIICode <= 122 ) {
        return 1;
    } else {
        return 0;
    }
}

int isUpper( char c ) {
    int ASCIICode = ( int )c;
    if ( ASCIICode >= 65 && ASCIICode <= 90 ) {
        return 1;
    } else {
        return 0;
    }
}

char *longestNiceSubstring( char *s ) {
    char *ns = NULL;
    int maxLen = 0;

    for ( int i = 0; s[i] != '\0'; i++ ) {
        int upper[26] = {0};
        int lower[26] = {0};

        for ( int j = i; s[j] != '\0'; j++ ) {
            if ( isLower( s[j] ) ) {
                lower[(int)s[j] - 97] = 1;
            } else if ( isUpper( s[j] ) ) {
                upper[(int)s[j] - 65] = 1;
            }

            int isNice = 1;
            for ( int k = 0; k < 26; k++ ) {
                if ( ( lower[k] && !upper[k] ) || ( !lower[k] && upper[k] ) ) {
                    isNice = 0;
                    break;
                }
            }

            if ( isNice && ( j - i + 1 ) > maxLen ) {
                maxLen = j - i + 1;
                free( ns );
                ns = ( char * )malloc( sizeof( char ) * ( maxLen + 1 ) );
                strncpy( ns, s + i, maxLen );
                ns[maxLen] = '\0';
            }
        }
    }

    if ( ns == NULL ) {
        ns = malloc( sizeof( char ) );
        ns[0] = '\0';
    }

    return ns;
}

int main() {
    char test[8] = "abB";

    printf( "%s\n", longestNiceSubstring( test ) );

    return 0;
}