#ifndef TESTER_H

#define TESTER_H



#include <string.h>

#include <stdio.h>



/* External variable used in tests */

/*extern int tests_run; */



/* Function prototypes for test cases */

char *test_string_length();

char *test_is_valid_character();

char *test_find_word_start();

char *test_find_word_terminator();

char *test_count_words();

char *test_tokenize();

char *test_add_history();

char *test_get_history();

char *all_tests();



#endif /* TESTER_H */
