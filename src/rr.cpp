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
	RRProcess* next;
} RRQueue;

class RRScheduler {
	private:
		RRQueue* queue;
	
	public:
		RRScheduler() {
		};
		void push ( RRProcess* proc ) {
		};
		void create () {
		};
		void activateNext () {
		};
		RRProcess* currentProcess () {
		};
};

int main () {
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
}
