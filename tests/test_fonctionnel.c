/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** test_unitaire.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_file_content(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = malloc(length + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }
    size_t read_size = fread(content, 1, length, file);
    content[read_size] = '\0';
    fclose(file);
    return content;
}

static void redirect_outputs(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void verify_program_output(const char *input_file, const char *expected_output_file) {
    char command[256];
    snprintf(command, sizeof(command), "./setting_up %s", input_file);
    int result = system(command);
    cr_assert_eq(result, 0, "Program execution failed for input: %s", input_file);
    char *expected_output = read_file_content(expected_output_file);
    cr_assert_not_null(expected_output, "Could not read expected output file");
    cr_assert_stdout_eq_str(expected_output, "Output mismatch for input: %s", input_file);
    free(expected_output);
}

Test(setting_up, test_case_1, .init = redirect_outputs) {
    verify_program_output(
        "example_files/maps/intermediate_map_100_100", 
        "example_files/solved/intermediate_map_100_100"
    );
}

Test(setting_up, test_case_2, .init = redirect_outputs) {
    verify_program_output(
        "example_files/maps/intermediate_map_34_137_with_obstacles_25pc", 
        "example_files/solved/intermediate_map_34_137_with_obstacles_25pc"
    );
}
