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
		RRNode* queueTail;
		RRNode* queueCursor;
	
	public:
		RRScheduler() {
			queue = new RRNode;
			queueTail = queue;
		};
		void push ( RRProcess* proc ) {
			if ( queueTail -> proc == NULL )
				queueTail -> proc = proc;
			else { 
				queueTail -> next = new RRNode;
				queueTail = queueTail -> next;
				queueTail -> proc = proc;
			}
		};
		void createNewProcess () {
			RRProcess* proc = new RRProcess();
			proc -> halt();
			std::cout	<< "Started process "
						<< proc -> getPID()
						<< "\n";
			push( proc );
		};
		void drawQueue () {
			queueCursor = queue;
			std::cout << "Start -> ";
			while ( queueCursor != NULL ) {
				std::cout	<< queueCursor -> proc -> getPID()
							<< " --> ";
				queueCursor = queueCursor -> next;
			}
			std::cout << "End\n";
		}
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
	RRScheduler* scheduler = new RRScheduler;
	scheduler -> createNewProcess();
	scheduler -> createNewProcess();
	scheduler -> createNewProcess();
	scheduler -> drawQueue();
}
