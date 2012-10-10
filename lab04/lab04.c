/* Measuring cost of a system call
*/

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char **argv){

	struct timeval begin, end, diff;
	struct timeval btotal, etotal;
	int loops = 5000;

	// time of gettimeofday
	int i = 0;
	for(;i < loops; i++){
		gettimeofday(&begin, NULL);
		gettimeofday(&end, NULL);
		timeradd(&begin, &btotal, &btotal);
		timeradd(&end, &etotal, &etotal);	
	}
	timersub(&etotal, &btotal, &diff);
	diff.tvsec = difftv.sec / loops;
	diff.tvusec = difftv.usec / loops;
	
	struct timeval gettime = diff;
	
	// time of syscall1: fork()
	int i = 0;
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
	diff.tvsec = difftv.sec / loops;
	diff.tvusec = difftv.usec / loops;
	
	struct timeval timefork;
	timersub(&diff;&gettime,&timefork);
}

// for syscall2: 
int i = 0;
	char* name = malloc(sizeof(char));
	size_t len = sizeof(char)*0);
	for(;i < loops; i++){
		gettimeofday(&begin, NULL);
		gettimeofday(&end, NULL);
		timeradd(&begin, &btotal, &btotal);
		gethostname(name,len);
		timeradd(&end, &etotal, &etotal);
	}
	timersub(&etotal, &btotal, &diff);
	diff.tvsec = difftv.sec / loops;
	diff.tvusec = difftv.usec / loops;
	free(name);
	
	struct timeval timehost;
	timersub(&diff;&gettime,&timehost);

printf("Time to execute gettimeofday():\t %d.%d\n", gettime.tv_sec, gettime.tv_usec);
printf("Time to execute fork():\t %d.%d\n", timefork.tv_sec, timefork.tv_usec);
printf("Time to execute fork():\t %d.%d\n", timehost.tv_sec, timehost.tv_usec);

return 0;
}



