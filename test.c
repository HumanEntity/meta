#include <stdio.h>

#include "meta.h"

const char *test_meta_source = "(\n"
                               "\ttest: \"Data\"\n"
                               "\tmore: 10\n"
                               ")";

int main ( void ) {
        meta_value value = meta_parse_string( test_meta_source );

        if ( value.type != META_VALUETYPE_OBJ ) {
                fprintf( stderr, "Should be obj\n" );
                return -1;
        }

        char buffer[1024] = { 0 };

        meta_compose( value, buffer, sizeof( buffer ) );

        printf( "Composed:\n%s\n", buffer );

        return 0;
}
