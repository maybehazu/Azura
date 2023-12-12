#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "libs/Azura.h"

void dotenv_setup(void);
void bot_setup(void);
void web_setup(void);
void execute_option(int);
void invalid_option(void);
void display(void);
int display_menu(void);

int main(int argc, char *argv[]) {
    system("title Azura");

    display();

    for(;;) {
        if(display_menu() != 0) {
            invalid_option();
            continue;
        }
        
        break;
    }

    return EXIT_SUCCESS;
}

void display(void) {
    display_ascii();

    SetConsoleColor(YELLOW_COLOR);
    printf("- ");

    SetConsoleColor(LIGHT_YELLOW_COLOR);
    printf("Azura is a small project designed to communicate discord with a computer in order to make dynamic streams programmed by RiothDev.\n");

    SetConsoleColor(LIGHT_BLUE_COLOR);
    printf("> ");

    SetConsoleColor(LIGHT_CYAN_COLOR);
    printf("https://github.com/RiothDev/Azura\n\n");

    SetConsoleColor(YELLOW_COLOR);
    printf("// Press any key to continue...\n");

    getch();

    system("cls");
}

void invalid_option() {
    SetConsoleColor(LIGHT_RED_COLOR);
    printf("\n- The option is not valid.\n");

    SetConsoleColor(YELLOW_COLOR);
    printf("// Press any key to continue...\n");

    getch();

    SetConsoleColor(RESET_COLOR);
    system("cls");
}

void execute_option(int opt) {
    switch(opt) {
        case 1: system("cls"); dotenv_setup(); break;
        case 2: system("cls"); bot_setup(); break;
        case 3: system("cls"); web_setup(); break;
        case 4:
        system("cls");

        dotenv_setup();
        bot_setup();
        web_setup();

        case 5:
        system("cls"); 

        display_ascii();

        SetConsoleColor(LIGHT_BLUE_COLOR); printf("1 - ");
        SetConsoleColor(LIGHT_CYAN_COLOR); printf("Start project (This will run the bot and the website)\n");

        SetConsoleColor(LIGHT_BLUE_COLOR); printf("2 - ");
        SetConsoleColor(LIGHT_CYAN_COLOR); printf("Start bot\n");

        SetConsoleColor(LIGHT_BLUE_COLOR); printf("3 - ");
        SetConsoleColor(LIGHT_CYAN_COLOR); printf("Start website\n");

        SetConsoleColor(LIGHT_BLUE_COLOR);
        printf("> ");

        SetConsoleColor(LIGHT_CYAN_COLOR);

        char input[10];
        fgets(input, sizeof(input), stdin);

        int opt;

        if(sscanf(input, "%d", &opt) != 1) {
            opt = -1;
        }

        SetConsoleColor(RESET_COLOR);

        if(opt > 3 || opt < 1) {
            invalid_option();
            execute_option(opt);

            break;
        }

        if(opt == 1) {
            system("start python.exe Main.py");

            SetConsoleColor(LIGHT_YELLOW_COLOR);
            printf("\n- Server: http://localhost:8080\n");

            SetConsoleColor(RESET_COLOR);

            system("cd web & npm start & title Azura");

        } else if(opt == 2) {
            system("python.exe Main.py");

        } else if(opt == 3) {
            SetConsoleColor(LIGHT_YELLOW_COLOR);
            printf("\n- Server: http://localhost:8080\n");

            SetConsoleColor(RESET_COLOR);

            system("cd web & npm start");
        }

        break;

        case 6: saiky();
    }
}

int display_menu(void) {
    display_ascii();

    SetConsoleColor(LIGHT_BLUE_COLOR); printf("1 - ");
    SetConsoleColor(LIGHT_CYAN_COLOR); printf(".env setup\n");

    SetConsoleColor(LIGHT_BLUE_COLOR); printf("2 - ");
    SetConsoleColor(LIGHT_CYAN_COLOR); printf("Project setup\n");

    SetConsoleColor(LIGHT_BLUE_COLOR); printf("3 - ");
    SetConsoleColor(LIGHT_CYAN_COLOR); printf("Website setup\n");

    SetConsoleColor(LIGHT_BLUE_COLOR); printf("4 - ");
    SetConsoleColor(LIGHT_CYAN_COLOR); printf("Complete project setup\n");

    SetConsoleColor(LIGHT_BLUE_COLOR); printf("5 - ");
    SetConsoleColor(LIGHT_CYAN_COLOR); printf("Run project\n");

    SetConsoleColor(LIGHT_BLUE_COLOR); printf("> ");
    SetConsoleColor(LIGHT_CYAN_COLOR);

    char input[10];
    fgets(input, sizeof(input), stdin);

    int opt;

    if(sscanf(input, "%d", &opt) != 1) {
        opt = -1;
    }

    if(opt > 6 || opt < 1) return 1;

    SetConsoleColor(RESET_COLOR);
    execute_option(opt);

    return 0;
}

void web_setup(void) {
    node_prompt();
    system("cls");

    display_ascii();

    system("cd web");

    SetConsoleColor(YELLOW_COLOR);
    printf("\n* Installing the website dependencies...\n");

    SetConsoleColor(LIGHT_BLUE_COLOR);
    system("npm install");

    SetConsoleColor(LIGHT_GREEN_COLOR);
    printf("\n- The website was installed, press any key to continue...\n");

    getch();

    SetConsoleColor(RESET_COLOR);
}

void dotenv_setup(void) {
    system("cls");

    display_ascii();

    dotenv *env = create_dotenv_struct();
    create_dotenv_file(env);

    free(env->token);
    free(env);

    SetConsoleColor(LIGHT_GREEN_COLOR);
    printf("\n- The .env file has been configured, press any key to continue...\n");

    getch();

    SetConsoleColor(RESET_COLOR);
}

void bot_setup(void) {
    py_prompt();
    system("cls");

    display_ascii();

    SetConsoleColor(YELLOW_COLOR);
    printf("\n* Installing the project dependencies...\n");

    SetConsoleColor(LIGHT_BLUE_COLOR);
    system("pip install -r requirements.txt");

    SetConsoleColor(RESET_COLOR);

    SetConsoleColor(LIGHT_GREEN_COLOR);
    printf("\n- The project was installed, press any key to continue...\n");

    getch();

    SetConsoleColor(RESET_COLOR);
}