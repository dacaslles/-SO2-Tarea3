#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
<<<<<<< HEAD
int main(void) {
/* Our process ID and Session ID */
pid_t pid, sid;
/* Fork off the parent process */
pid = fork();
if (pid < 0) {
exit(EXIT_FAILURE);
}
/* If we got a good PID, then
we can exit the parent process. */
if (pid > 0) {
exit(EXIT_SUCCESS);
}
/* Change the file mode mask */
umask(0);
/* Open any logs here */
/* Create a new SID for the child process */
sid = setsid();
if (sid < 0) {
/* Log the failure */
exit(EXIT_FAILURE);
}
/* Change the current working directory */
if ((chdir("/")) < 0) {
/* Log the failure */
exit(EXIT_FAILURE);
}
/* Close out the standard file descriptors */
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
/* Daemon-specific initialization goes here */
time_t tiempo;
char cad[80];
struct tm *tmptr;
FILE *f;
/* The Big Loop */
while (1) {
tiempo = time(NULL);
tmptr = localtime(&tiempo);
strftime(cad,80,"%H:%M:%S, %A, %B %Y",tmptr);
f = fopen("/home/david/hora","w");
fprintf(f,"%s", cad);
fclose(f);
sleep(15); /* wait 30 seconds */
}
exit(EXIT_SUCCESS);
=======

int main(void) {
        
        /* Our process ID and Session ID */
        pid_t pid, sid;
        
        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);
                
        /* Open any logs here */        
                
        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        

        
        /* Change the current working directory */
        if ((chdir("/")) < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        
        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
        /* Daemon-specific initialization goes here */
        time_t tiempo;
    char cad[80];
    struct tm *tmptr;
    FILE *f;
        /* The Big Loop */
        while (1) {
           tiempo = time(NULL);
    	tmptr = localtime(&tiempo);
    	strftime(cad,80,"%H:%M:%S, %A de %B de %Y",tmptr);
	f = fopen("/home/david/hora","w");
	fprintf(f,"%s", cad);
	fclose(f);
           
           sleep(30); /* wait 30 seconds */
        }
   exit(EXIT_SUCCESS);
>>>>>>> e0781d87e73b7178fe77486c5b2e8de8caa8730b
}
