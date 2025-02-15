//#include <iostream>
#include <cmath>
#include <string>

#include <cstdlib> //rand
#include <time.h> //time
#include <unistd.h> //usleep
#include <map> //map

//NON BLOCKING INPUT ??
#include <future>
#include <thread>
#include <chrono>
#include <atomic>

#include <ncurses.h> // ?????

using namespace std;

atomic<bool> input_received(false);
char user_input;

unsigned int ms = 1000; //1 ms = 1000 us



#define MAX_BARGRAPH_LENGTH 20
#define MAX_BARGRAPH_VALUE 100.0
float b_value = 0.0;

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

void print_bargraph(float value);
void print_lcd_timer(time_t base_time);
void print_keypad();
void getInput();

int main(){
    srand(time(NULL));
    //cout << "Enter a value between 0 and 100: ";
    //cin >> bargraph_value;
    time_t start_time = time(NULL);
    while (true){

        for (int j = 0; j < 10; j++){
            //cout << endl;
        }
        b_value += 1;
        //bargraph_value = 96;
        //bargraph_value = rand() % 101;
        //cout << endl << string(MAX_BARGRAPH_LENGTH,'\u0305') << endl;
        print_bargraph(b_value);
        print_lcd_timer(start_time);
        print_keypad();


        usleep(100*ms);
        
    }
    return 0;
}

void print_bargraph(float bargraph_value){
    // int bargraph_length = static_cast<int>(ceil(bargraph_value * MAX_BARGRAPH_LENGTH / MAX_BARGRAPH_VALUE));

    // cout << "bargraphg" << endl;

    // cout << string(MAX_BARGRAPH_LENGTH+2,'_') << endl;
    // cout << "|";
    // for (int i = 0; i < MAX_BARGRAPH_LENGTH; i++){
    //     if (i < bargraph_length && i < MAX_BARGRAPH_LENGTH*0.3){
    //         cout << "\033[32m#\033[0m"; // green
    //     } 
    //     else if (i < bargraph_length && i < MAX_BARGRAPH_LENGTH*0.7){
    //         cout << "\033[33m#\033[0m"; // yellow
    //     }
    //     else if (i < bargraph_length && i < MAX_BARGRAPH_LENGTH){
    //         cout << "\033[31m#\033[0m"; // red
    //     }
    //     else { cout << " ";}
        
    // }
    // cout << "|" << endl;
    // for (int i = 0; i < MAX_BARGRAPH_LENGTH+2; i++){
    //     cout << "\u0305";
    // }
    // cout << endl;
}

void print_lcd_timer(time_t base_time){
    // cout << "LCD Timer" << endl;
    // time_t current_time = time(NULL);
    // time_t elapsed_time = current_time - base_time;
    // cout << "Elapsed time: " << elapsed_time << " seconds" << endl << endl;

}

void print_keypad(){
    //cout << "Keypad" << endl;
    int r = rand() % 16;
    char c = '!';
    printw("Press \033[1;4;36m%c\033[0m then [ENTER]: ", keypad_map[r]);
    
    //cin >> c;
    //cin.clear();
    //cin.ignore(10000, '\n');
    // cout << "Press \033[1;4;36m" << keypad_map[r] << "\033[0m then [ENTER]: " 
    // cout << endl;
    // if (!input_received) {
    //     cout << "\033[31mTimeout!\033[0m" << endl; // red
    // }
    // else if ( keypad_map[r] == c){
    //     cout << "\033[32mCorrect!\033[0m" << endl; // green
    // }
    // else {
    //     cout << "\033[31mIncorrect!\033[0m" << endl; // red
    // }
}

void getInput() {
    // cin >> user_input;
    // input_received = true;
}
