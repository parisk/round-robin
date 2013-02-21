#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/resource.h>

class RRProcess {
	private:
		int pid;
		void sigProc ( int sig ) {
			kill( pid, sig );
		}
		static void eternalLoop () {
			while (1) {
				std::cout 	<< "Process "
							<< getpid()
							<< "running...\n";
			};
		}

	public:
		RRProcess () {
			pid = fork();
			if ( !pid ) {
				std::cout	<< "Process "
							<< getpid()
							<< " just spawned...\n";
				eternalLoop();
			}
		}
		void activate () {
			sigProc( SIGCONT );
		}
		void halt () {
			sigProc( SIGSTOP );
		}
		void exit () {
			sigProc( SIGKILL );
		}
		int getPID () {
			return pid;
		}

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
