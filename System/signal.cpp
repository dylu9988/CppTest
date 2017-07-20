

#include "comm/comm.hpp"
#include <signal.h>

void hup_handler(int sig)
{
	switch(sig)
	{
	case SIGHUP:
		Log("signal handler:SIGHUP");
		break;
	case SIGINT:
		Log("signal handler:SIGINT");
		break;
	case SIGSTOP:
		Log("signal handler:SIGTSTOP");
		break;
	case SIGTSTP:
		Log("signl handler:SIGTSTP");
		break;
	default:
		Log("signal handler:%d", sig);
		break;
	}
}

void ignore_signal()
{
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	Log("signal errno:%d", errno);

	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = hup_handler;
	sigaction(SIGHUP, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGSTOP, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);
}



