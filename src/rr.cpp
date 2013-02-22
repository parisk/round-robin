#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/resource.h>

#include "rr/process.cpp"

class RRNode {
	public:
		RRProcess* proc;
		RRNode* next;
};

class RRScheduler {
	private:
		RRNode* queue;
	
	public:
		RRScheduler() {
			queue = new RRNode;
		};
		void push ( RRProcess* proc ) {
			/*
			if ( queue -> proc == NULL )
				queue -> proc = proc;
			*/
			queue -> proc = proc;
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
