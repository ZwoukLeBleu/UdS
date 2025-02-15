//#include <iostream>
#include <cmath>
#include <string>

#include <cstdlib> //rand
#include <time.h> //time
#include <unistd.h> //usleep
#include <map> //map

#include <ncurses.h> // game lib

using namespace std;

#define MAX_BARGRAPH_LENGTH 20
#define MAX_BARGRAPH_VALUE 100.0
#define MAX_KEYPAD_LENGTH 16
#define POTENTIOMETER_RESITANCE 3
#define POTENTIOMETER_KICK 8

map<int, char> keypad_map = {
    {0, '0'},
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
    {10, 'A'},
    {11, 'B'},
    {12, 'C'},
    {13, 'D'},
    {14, '*'},
    {15, '#'}
};

enum ColorPairs {
    RED_ON_BLACK = 1,
    GREEN_ON_BLACK,
    YELLOW_ON_BLACK,
    BLUE_ON_BLACK,
    MAGENTA_ON_BLACK,
    WHITE_ON_BLACK
};

float b_value = 0.0;
time_t start_time = time(NULL);
unsigned int ms = 1000; //1 ms = 1000 us
int r = 0;
int keypad_count = 0;
float p_value = 0.0;
int testCount = 0;

void print_bargraph(float value);
void print_lcd_timer();
int print_keypad(int r);
void print_potentiometer(float bargraph_value, int target);

int main(int argc, char ** argv){
    srand(time(NULL));
    //cout << "Enter a value between 0 and 100: ";
    //cin >> bargraph_value;
    
    
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(YELLOW_ON_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLUE_ON_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair(MAGENTA_ON_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);
    int arr[16];

    for (int i = 0; i < 16; i++){
         arr[i] = rand() % 16;
    }
    r = rand() % 16;

    while (true) {

        clear();
        b_value += 0.1;
        //move(0, b_value);
        //napms(100);
        //printw("Running\n");
        printw("Iteration Count: %d\n", testCount);
        testCount++;
        print_bargraph(b_value);
        //move(5, 40);
        print_lcd_timer();
        if (keypad_count < 2){
            keypad_count += print_keypad(arr[keypad_count]);
        }
        else {
            print_potentiometer(p_value, r);
        }
        refresh();
        usleep(100*ms);
        

    }
    endwin();
    return 0;
}

void print_bargraph(float bargraph_value){
    int bargraph_length = static_cast<int>(ceil(bargraph_value * MAX_BARGRAPH_LENGTH / MAX_BARGRAPH_VALUE));

    printw("bargraphg\n");
    for (int i = 0; i < MAX_BARGRAPH_LENGTH+2; i++){
        printw("-");
    }
    printw("\n|");
    for (int i = 0; i < MAX_BARGRAPH_LENGTH; i++){
        if (i < bargraph_value && i < MAX_BARGRAPH_LENGTH*0.3){
            attron(COLOR_PAIR(GREEN_ON_BLACK));
            printw("#");
            attroff(COLOR_PAIR(GREEN_ON_BLACK));
        } 
        else if (i < bargraph_value && i < MAX_BARGRAPH_LENGTH*0.7){
            attron(COLOR_PAIR(YELLOW_ON_BLACK));
            printw("#");
            attroff(COLOR_PAIR(YELLOW_ON_BLACK));
        }
        else if (i < bargraph_value && i < MAX_BARGRAPH_LENGTH){
            attron(COLOR_PAIR(RED_ON_BLACK));
            printw("#");
            attroff(COLOR_PAIR(RED_ON_BLACK));
        }
        else { printw(" ");}
        
    }
    printw("|\n");
    for (int i = 0; i < MAX_BARGRAPH_LENGTH+2; i++){
        printw("-");
    }
    printw("\n");
}

void print_lcd_timer(){
    printw("LCD Timer\n");
    time_t elapsed_time = time(NULL) - start_time;
    printw("Elapsed time: %ld seconds\n\n", elapsed_time);
}

int print_keypad(int r){
    printw("Keypad\n");
    
    
    
    char c = '!';
    printw("Press ");
    attron(COLOR_PAIR(BLUE_ON_BLACK));
    printw("%c", keypad_map[r]);
    attroff(COLOR_PAIR(BLUE_ON_BLACK));
    printw(" then [ENTER]: ");
    
    nodelay(stdscr, TRUE);
    
    if (getch() == keypad_map[r]){
        attron(COLOR_PAIR(GREEN_ON_BLACK));
        
        printw("Correct!\n");
        attroff(COLOR_PAIR(GREEN_ON_BLACK));
        return 1;
    }
    else if (getch() != ERR){
        attron(COLOR_PAIR(RED_ON_BLACK));
        printw("Incorrect!\n");
        attroff(COLOR_PAIR(RED_ON_BLACK));
        return 0;
    }
    return 0;
}


void print_potentiometer(float potentiometer_value, int target){
    int cursor_length = static_cast<int>(ceil(potentiometer_value * MAX_BARGRAPH_LENGTH / MAX_BARGRAPH_VALUE));

    printw("potentiomenter\n");
    for (int i = 0; i < MAX_BARGRAPH_LENGTH+2; i++){
        printw("-");
    }
    printw("\n|");
    for (int i = 0; i < MAX_BARGRAPH_LENGTH; i++){
        if (i == cursor_length){
            //attron(COLOR_PAIR(GREEN_ON_BLACK));
            printw("#");
            //attroff(COLOR_PAIR(GREEN_ON_BLACK));
        } 
        else if (i == target-1 || i == target+1){
            attron(COLOR_PAIR(MAGENTA_ON_BLACK));
            printw("|");
            attroff(COLOR_PAIR(MAGENTA_ON_BLACK));
            //printw("\033[33m#\033[0m"); // yellow
        }
        
        else { printw(" ");}
        
    }
    printw("|\n");
    for (int i = 0; i < MAX_BARGRAPH_LENGTH+2; i++){
        printw("-");
    }
    printw("\n");


    if (getch() == KEY_RIGHT){
        printw("Right\n");
        p_value += POTENTIOMETER_KICK;
    }
        p_value -= POTENTIOMETER_RESITANCE;
    if (p_value <0){
        p_value = 0;

    }

}