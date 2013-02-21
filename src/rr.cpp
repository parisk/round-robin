#include <iostream>
#include <stdlib.h>
#include <signal.h>

class RRProcess {
	private:
		int pid;
		void signal ( int sig ) {
			kill( pid, sig );
		}
	public:
		RRProcess () {
			pid = fork();
			if ( !pid ) {
				raise( SIGSTOP );
				while (1) {};
			}
		}
		void exit () {
			this -> signal( SIGSTOP );
		}
		int getPID () {
			return this -> pid;
		}

};

int main () {
}
