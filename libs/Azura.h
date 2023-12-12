#pragma once

#include <stdio.h>
#include <conio.h>
#include "Colors.h"

#define BUFFER_SIZE 1024

typedef struct {
    char *token;
    int guild;
} dotenv;

char *get_input(const char*);
void exit_failure(void);
void py_prompt(void);
void js_prompt(void);
void create_dotenv_file(dotenv*);
dotenv *create_dotenv_struct(void);
void check_buffer(char**);
void display_ascii(void);

void py_prompt(void) {
    system("cls");

    if(system("python --version") != 0) {
        SetConsoleColor(LIGHT_YELLOW_COLOR);
        printf("* Python is not installed on the device, you must install it from its web page to continue.\n>> https://www.python.org/\n");

        getch();
        SetConsoleColor(RESET_COLOR);
        
        py_prompt();
    }
}

void node_prompt(void) {
    system("cls");

    if(system("node --version") != 0) {
        SetConsoleColor(LIGHT_YELLOW_COLOR);
        printf("* Node.js is not installed on the device, you must install it from its web page to continue.\n>> https://nodejs.org/en\n");

        getch();
        SetConsoleColor(RESET_COLOR);

        node_prompt();
    }
}

void create_dotenv_file(dotenv *env_struct) {
    FILE *env = fopen(".env", "w+");

    fprintf(env, "TOKEN=%s\n", env_struct->token);

    char guild_str[100];
    snprintf(guild_str, sizeof(guild_str), "%d", env_struct->guild);
    fprintf(env, "GUILD=%s", guild_str);

    fclose(env);
}

dotenv *create_dotenv_struct(void) {
    dotenv *env = (dotenv*) malloc(sizeof(dotenv));

    SetConsoleColor(CYAN_COLOR);
    printf("> Guild: ");

    SetConsoleColor(LIGHT_BLUE_COLOR);
    
    if(scanf("%d", &(env->guild)) != 1) {
        SetConsoleColor(RED_COLOR);
        printf("- Invalid guild ID\n");

        SetConsoleColor(RESET_COLOR);

        free(env);
        exit_failure();
    }

    int c;
    while((c = getchar()) != EOF && c != '\n');

    env->token = get_input("> Token: ");

    return env;
}

void exit_failure(void) {
    SetConsoleColor(YELLOW_COLOR);
    printf("// Press any key to close...\n");

    SetConsoleColor(LIGHT_YELLOW_COLOR);
    getch();

    SetConsoleColor(RESET_COLOR);

    exit(EXIT_FAILURE);
}

void check_buffer(char **buffer) {
    if(!(*buffer)) {
        SetConsoleColor(LIGHT_RED_COLOR);
        printf("- An error occurred while trying to store dynamic memory\n");

        SetConsoleColor(RESET_COLOR);

        exit_failure();
    }
}

char *get_input(const char *input) {
    SetConsoleColor(CYAN_COLOR);
    printf(input);
    SetConsoleColor(LIGHT_BLUE_COLOR);

    size_t buffer_size = BUFFER_SIZE;
    char *buffer = (char*) malloc(sizeof(char) * buffer_size);

    check_buffer(&buffer);

    for(int p = 0, c;;p++) {
        c = getchar();

        if(c == EOF || c == '\n') {
            buffer[p] = '\0';
            break;
        }

        buffer[p] = c;

        if(p >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            buffer = (char*) realloc(buffer, sizeof(char) * buffer_size);

            check_buffer(&buffer);
        }
    }

    SetConsoleColor(RESET_COLOR);
    return buffer;
}

void display_ascii(void) {
    SetConsoleColor(CYAN_COLOR);

    printf("                                 \n");
    printf("     /\\                         \n");
    printf("    /  \\    _____   _ _ __ __ _ \n");
    printf("   / /\\ \\  |_  / | | | '__/ _` |\n");
    printf("  / ____ \\  / /| |_| | | | (_| |\n");
    printf(" /_/    \\_\\/___|\\__,_|_|  \\__,_|\n");
    printf("                                \n");
    printf("                                 \n");

    SetConsoleColor(RESET_COLOR);
}

void saiky(void) {
    system("cls");
    SetConsoleColor(MAGENTA_COLOR);

    printf("- ");

    SetConsoleColor(LIGHT_MAGENTA_COLOR);

    printf("You were saikyed\n");
    printf("- Zzz....\n\n1 - Quit\n");

    SetConsoleColor(MAGENTA_COLOR);

    printf("> ");

    char input[10];
    fgets(input, sizeof(input), stdin);

    int opt;

    if(sscanf(input, "%s", &opt) != 1) {
        opt = -1;
    }

    if(opt != 1) {
        SetConsoleColor(LIGHT_RED_COLOR);
        printf("\n- Get funky!\n");

        SetConsoleColor(LIGHT_MAGENTA_COLOR);
        printf("> https://youtu.be/rl7ppuXMfC8?si=NT7WqO2qpcH1sGg6\n");
    } else {
        SetConsoleColor(YELLOW_COLOR);
        printf("// Press any key to continue...\n");
    }

    SetConsoleColor(RESET_COLOR);

    getch();
}