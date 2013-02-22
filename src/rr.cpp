#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/resource.h>

#include "rr/process.cpp"

typedef struct RRQueue {
	RRProcess* proc;
	RRQueue* next;
} RRQueue;

class RRScheduler {
	private:
		RRQueue* queue;
	
	public:
		RRScheduler() {
			queue -> proc = ( RRProcess* )malloc( sizeof RRProcess );
			/*
			queue -> proc = NULL;
			*/
		};
		void push ( RRProcess* proc ) {
			/*
			if ( queue -> proc == NULL )
				queue -> proc = proc;
			*/
		};
		void createNewProcess () {
			RRProcess* proc = new RRProcess();
			std::cout	<< "Started process "
						<< proc -> getPID()
						<< "\n";
			push( proc );
		};
		void activateNext () {
		};
		RRProcess* currentProcess () {
		};
};

int main () {
	/*
	RRProcess* myProcess = new RRProcess();
	std::cout	<< "Parent process "
				<< getpid()
				<< " created process "
				<< myProcess -> getPID()
				<< "\n";
	myProcess -> halt();
	sleep(2);
	myProcess -> activate();
	sleep(2);
	myProcess -> exit();
	std::cout	<< "\n";
	*/
	std::cout	<< "Main program started with PID "
				<< getpid()
				<< "\n";
	RRScheduler* scheduler = new RRScheduler();
	scheduler -> createNewProcess();
}
