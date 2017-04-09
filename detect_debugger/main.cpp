#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <errno.h>

static bool is_debugger_present()
{
	int name[4];
	struct kinfo_proc info;
	size_t kinfo_size = sizeof(info);

	name[0] = CTL_KERN;
	name[1] = KERN_PROC;
	name[2] = KERN_PROC_PID;
	name[3] = getpid();

	info.kp_proc.p_flag = 0;
	
	if (sysctl(name, 4, &info, &kinfo_size, NULL, 0)) {
		printf("call sysctl error:%d string:%s\n", 
				errno, strerror(errno));
		abort();
	}

	return info.kp_proc.p_flag & P_TRACED;	
}

int main(int argc, const char *argv[]) 
{
	printf("detect_debugger start...\n");

	while(true) {

		if (is_debugger_present()) {
			printf("found a debugger attached, ready to exit!!!\n");
			
			getchar();  exit(0):
		}

		sleep(1);  /*avoid cpu full used*/
	}


	return 0;
}
