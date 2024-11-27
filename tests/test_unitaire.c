/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** test_unitaire.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"
#include "../include/setting_up.h"
#include "../include/my.h"
#include <stdlib.h>
#include <string.h>

static void redirect_outputs(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Validate map constraints
int validate_map_constraints(stat_buff_t *map, const char *pattern) {
    if (!map || !map->buffer) return 0;
    
    // Check dimensions
    if (map->len_line <= 0 || map->len_column <= 0) return 0;
    if (map->len_line != map->len_column) return 0;
    
    // Validate each character
    for (int i = 0; i < map->len_line; i++) {
        for (int j = 0; j < map->len_column; j++) {
            if (map->buffer[i][j] != pattern[j % strlen(pattern)]) return 0;
        }
    }
    
    return 1;
}

// Test successful map generation
Test(handle_generating, successful_generation, .init = redirect_outputs) {
    char *test_patterns[] = {
        "..o..", 
        ".o...", 
        "o..o."
    };
    
    for (size_t p = 0; p < sizeof(test_patterns)/sizeof(test_patterns[0]); p++) {
        char *size_str = "100";
        char *args[] = {"program", size_str, test_patterns[p], NULL};
        stat_buff_t buffer = {0};
        
        int result = handle_generating(3, args, &buffer);
        
        cr_assert_eq(result, 0, "Handle generating should return 0 for valid input");
    }
}

// Test invalid inputs
Test(handle_generating, invalid_inputs, .init = redirect_outputs) {
    struct {
        char *size;
        char *pattern;
    } invalid_cases[] = {
        {"0", "..o.."},     // Zero size
        {"100", ""},         // Empty pattern
        {"100", "abc"},      // Invalid characters
        {"-10", "..o.."}    // Negative size
    };
    
    for (size_t i = 0; i < sizeof(invalid_cases)/sizeof(invalid_cases[0]); i++) {
        char *args[] = {"program", invalid_cases[i].size, invalid_cases[i].pattern, NULL};
        stat_buff_t buffer = {0};
        
        int result = handle_generating(3, args, &buffer);
        
        cr_assert_eq(result, 84, "Invalid input should return 84");
    }
}

// Test incorrect argument count
Test(handle_generating, incorrect_argument_count, .init = redirect_outputs) {
    char *args[] = {"program", "100", NULL};
    stat_buff_t buffer = {0};
    
    int result = handle_generating(2, args, &buffer);
    
    cr_assert_eq(result, 84, "Incorrect argument count should return 84");
}

Test(verif_error, valid_input, .init = redirect_outputs) {
    char *valid_args[] = {"./setting_up", "example_files/maps/intermediate_map_100_100", NULL};
    
    int result = verif_error(2, valid_args);
    
    cr_assert_eq(result, 0, "Valid input should return 0");
}

// Test: Incorrect number of arguments (fewer)
Test(verif_error_suite, test_fewer_args) {
    char *args[] = {"./setting_up", NULL};
    cr_assert_eq(verif_error(1, args), 84);
}

// Test: Incorrect number of arguments (more)
Test(verif_error_suite, test_more_args) {
    char *args[] = {"./setting_up", "example_files/maps/intermediate_map_100_100", "arg2", NULL};
    cr_assert_eq(verif_error(3, args), 84);
}

// Test: Correct number of arguments
Test(verif_error_suite, test_correct_args) {
    char *args[] = {"./setting_up", "test", NULL};
    cr_assert_eq(verif_error(2, args), 84);
}

// Helper function to create a test file
void create_test_file(const char *filename, const char *content) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(fd, -1, "Failed to create test file");
    write(fd, content, strlen(content));
    close(fd);
}

// Test: Successful reading of a valid file
Test(read_to_string_array_suite, test_valid_file) {
    // Create a test file
    const char *test_filename = "output.txt";
    const char *test_content = "3\nfirst line\nsecond line\nthird line\n";
    create_test_file(test_filename, test_content);

    // Prepare arguments
    char *args[] = {"./setting_up", (char*)test_filename, NULL};

    // Call the function
    stat_buff_t *result = read_to_string_array(args);

    // Assertions
    cr_assert_not_null(result, "Result should not be NULL");
    cr_assert_eq(result->len_line, 3, "Number of lines should match");
    
    // Check content of lines
    cr_assert_str_eq(result->buffer[0], "first line", "First line content incorrect");
    cr_assert_str_eq(result->buffer[1], "second line", "Second line content incorrect");
    cr_assert_str_eq(result->buffer[2], "third line", "Third line content incorrect");
    cr_assert_null(result->buffer[3], "Last element should be NULL");

    // Free memory
    for (int i = 0; i < result->len_line; i++) {
        free(result->buffer[i]);
    }
    free(result->buffer);
    free(result);

    // Clean up test file
    unlink(test_filename);
}

// Test: Empty file
Test(read_to_string_array_suite, test_empty_file) {
    const char *test_filename = "test";
    create_test_file(test_filename, "0\n");

    char *args[] = {"./setting_up", (char*)test_filename, NULL};

    stat_buff_t *result = read_to_string_array(args);
    cr_assert_not_null(result, "Result should not be NULL");
    cr_assert_eq(result->len_line, 0, "Number of lines should be 0");

    // Clean up
    free(result->buffer);
    free(result);
    unlink(test_filename);
}
