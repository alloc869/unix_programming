#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define __USE_BSO
#include <termios.h>

int main(void) {
	int fdm;
	int rc;

	system("ls -l /dev/pts");

	fdm = posix_openpt(O_RDWR);
	if(fdm < 0) {
		fprintf(stderr, "Error %d on posix_openpt()\n", errno);
		return 1;
	}

	rc = grantpt(fdm);
	if(rc) {
		fprintf(stderr, "Error %d on grantpt()\n", errno);
		return 1;
	}

	rc = unlockpt(fdm);
	if(rc) {
		fprintf(stderr, "Error %d on unlockpt()\n", errno);
		return 1;
	}

	system("ls -l /dev/pts");

	printf("The slave side is named : %s\n", ptsname(fdm));
	return 0;
}

