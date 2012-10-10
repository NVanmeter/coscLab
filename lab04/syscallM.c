/* Measuring cost of a system call
*/

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv){

	struct timeval begin, end, diff;
	struct timeval dtotal;
	int loops = 5000;

	// time of gettimeofday
	int i = 0;
	for(;i < loops; i++){
		gettimeofday(&begin, NULL);
		gettimeofday(&end, NULL);
		timersub(&begin, &end, &diff);
		timeradd(&diff, &dtotal, &dtotal);	
	}
	timersub(&dtotal, &dtotal, &diff);
	diff.tv_sec = diff.tv_sec / loops;
	diff.tv_usec = diff.tv_usec / loops;
	
	struct timeval gettime = diff;
	
	// time of syscall1: fork()
	i = 0;
	pid_t PID = 0;
	for(;i < loops; i++){
		gettimeofday(&begin, NULL);
		gettimeofday(&end, NULL);
		timeradd(&begin, &btotal, &btotal);
		PID = fork();
		timeradd(&end, &etotal, &etotal);
		if(PID == 0){
			return 0;
		}
		else{
			wait();
		}		
	}
	timersub(&etotal, &btotal, &diff);
	diff.tv_sec = diff.tv_sec / loops;
	diff.tv_usec = diff.tv_usec / loops;
	
	struct timeval timefork;
	timersub(&diff,&gettime,&timefork);


// for syscall2: 
	i = 0;
	char* name = malloc(sizeof(char));
	size_t len = sizeof(char);
	for(;i < loops; i++){
		gettimeofday(&begin, NULL);
		gettimeofday(&end, NULL);
		timeradd(&begin, &btotal, &btotal);
		gethostname(name,len);
		timeradd(&end, &etotal, &etotal);
	}
	timersub(&etotal, &btotal, &diff);
	diff.tv_sec = diff.tv_sec / loops;
	diff.tv_usec = diff.tv_usec / loops;
	free(name);
	
	struct timeval timehost;
	timersub(&diff,&gettime,&timehost);

printf("Time to execute gettimeofday():\t %ld.%ld\n", gettime.tv_sec, gettime.tv_usec);
printf("Time to execute fork():\t %ld.%ld\n", timefork.tv_sec, timefork.tv_usec);
printf("Time to execute fork():\t %ld.%ld\n", timehost.tv_sec, timehost.tv_usec);

return 0;
}



