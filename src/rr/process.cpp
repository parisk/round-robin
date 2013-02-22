class RRProcess {
	private:
		int pid;
		void sigProc ( int sig ) {
			kill( pid, sig );
		}
		static void eternalLoop () {
			while (1) {
				/*
				std::cout 	<< "Process "
							<< getpid()
							<< "running...\n";
				*/
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
