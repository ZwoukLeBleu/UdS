// CODE BASED ON : https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/

#include <cmath>

#include <stdio.h>
#include <string.h>
// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

//#define MINI_SIMON 

int open_port();

int main() {

    int serial_port = open_port();

    char msg[] = "Hello, world!";
    write(serial_port, msg, sizeof(msg));

    char read_buf [256];
    // Normally you wouldn't do this memset() call, but since we will just receive
    // ASCII data for this example, we'll set everything to 0 so we can
    // call printf() easily.
    memset(&read_buf, '\0', sizeof(read_buf));
    int num_bytes = read(serial_port, &read_buf, sizeof(read_buf)); // behaviour depends on VMIN and VTIME (see open_port())
    
    // Here we assume we received ASCII data, but you might be sending raw bytes (in that case, don't try and
    // print it to the screen like this!)
    printf("Read %i bytes. Received message: %s", num_bytes, read_buf);

    close(serial_port);

  return 0;
}

int open_port(){
    int serial_port = open("/dev/ttyACM0", O_RDWR); //ttyUSB0? ttyACM1? 

    if (serial_port < 0) {
        printf("Error %i from open: %s\n", errno, strerror(errno));
        return serial_port;
    }
    // Create new termios struct, we call it 'tty' for convention
    // No need for "= {0}" at the end as we'll immediately write the existing
    // config to this struct
    struct termios tty;

    // Read in existing settings, and handle any error
    // NOTE: This is important! POSIX states that the struct passed to tcsetattr()
    // must have been initialized with a call to tcgetattr() overwise behaviour
    // is undefined
    if(tcgetattr(serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }

    tty.c_cflag &= ~PARENB; // CLEAR parity bit
    tty.c_cflag &= ~CSTOPB; // CLEAR 2nd stop bit
    tty.c_cflag &= ~CSIZE; // CLEAR current size
    tty.c_cflag |= CS8; // SET 8 bits per byte
    tty.c_cflag &= ~CRTSCTS; // CLEAR RTS/CTS hardware flow control
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    tty.c_lflag &= ~ICANON; // Disable canonical mode 
    // ^ !!!THIS COULD BE A PROBLEM FOR OUR USE CASE!!!

    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds)
    tty.c_cc[VMIN] = 0; // return from read() as soon as any data is received. VMIN > 0 returns only when the number (bytes) of data is received

    cfsetspeed(&tty, B9600); // Set baud rate to 9600

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
    

    return serial_port;
}

int rumbleDetection(float x, float y, float z){
    //TODO
    
    double magnitude = sqrt(x*x + y*y + z*z);
    

    return 0;
}
