#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/resource.h>

void eternalLoop () {
	while (1) {
		std::cout 	<< "\n\nProcess "
					<< getpid()
					<< "running...\n";
	};
}

class RRProcess {
	private:
		int pid;
		void sigProc ( int sig ) {
			std::cout 	<< "SigProc: "
						<< sig
						<< ", "
						<< pid
						<< "\n\n";
			kill( pid, sig );
		}
	public:
		RRProcess () {
			pid = fork();
			if ( !pid ) {
				std::cout	<< "Process "
							<< getpid()
							<< " just spawned...\n";
			}
		}
		void activate () {
			std::cout << "Activate me!\n";
			sigProc( SIGCONT );
		}
		void halt () {
			std::cout << "Halt me!\n";
			sigProc( SIGSTOP );
		}
		void exit () {
			std::cout << "Exit me!\n";
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
	//waitpid( myProcess -> getPID(), 0, 0 );
	sleep(2);
	myProcess -> activate();
	wait();
	sleep(2);
	myProcess -> exit();
}
