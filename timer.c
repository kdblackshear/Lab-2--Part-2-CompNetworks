/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int sound_alarm = 0;
int alarm_count = 0;
time_t start_time, end_time;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sound_alarm = 1;
  alarm_count++;
  //exit(1); //exit after printing
}

void sigint_signal_handler(int signum){
  end_time = time(NULL);
  double total_sys_time = end_time - start_time;
  printf("Total alarms: %d\n", alarm_count);
  printf("Toal time: %.0f seconds.\n", total_sys_time);
  exit(0);
}

int main(int argc, char * argv[])
{
  start_time = time(NULL);

  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, sigint_signal_handler);
  while(1){
    alarm(5); //Schedule a SIGALRM for 5 seconds
    while(!sound_alarm); //busy wait for signal to be delivered
    printf("Turing was right!\n");
  }
  return 0; //never reached
}
