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

        if ( !meta_set_field( &value, "new_field", &(meta_value) { .type = META_VALUETYPE_NULL } ) ) {
                fprintf( stderr, "Failed to set field\n" );
                return -1;
        }

        meta_value more_field = { 0 };

        if ( !meta_get_field( &value, "more", &more_field ) ) {
                fprintf( stderr, "Failed to fetch field\n" );
                return -1;
        }

        if ( more_field.type != META_VALUETYPE_INT || more_field.data.integer != 10 ) {
                fprintf( stderr, "Invalid data\n" );
                return -1;
        }

        meta_compose( value, buffer, sizeof( buffer ) );

        meta_free( value );

        printf( "Composed:\n%s\n", buffer );

        return 0;
}
