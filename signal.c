#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler (int signo);

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  char *c = "Anthony";
  while (1){
    printf("This never stops. My name is %s and the pid is %d. \n", c, getpid());
    sleep(1);
  }
}

void sighandler(int signum){
  if (signum == SIGINT){
    printf("Caught signal %d, exiting...\n", signum);
    int d = open("sig.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    write(d, "\nFile exited due to SIGINT", 25);
    close(d);
    exit(1);
  } else if (signum == SIGUSR1) {
    printf("The pid of parent process is %d \n", getppid());
  }
}
