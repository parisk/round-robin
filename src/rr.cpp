#include <iostream>
#include <stdlib.h>
#include <signal.h>

class RRProcess {
	private:
		int pid;
	public:
		RRProcess () {
			pid = fork();
			if ( !pid ) {
				raise( SIGSTOP );
				while (1) {};
			}
		}
};

int main () {
}
