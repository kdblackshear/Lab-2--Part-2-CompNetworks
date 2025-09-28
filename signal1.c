/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int sound_alarm = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sound_alarm = 1;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(!sound_alarm); //busy wait for signal to be delivered
  printf("Turing was right!\n");
  return 0; //never reached
}# Lab-2--Part-2-CompNetworks
