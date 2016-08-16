#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dirp;
	char cwd[512];

	if(argc !=2 )
		fprintf(stderr, "Usage: ls directory_name");
	getcwd(cwd, sizeof(cwd));
	printf("cwd: %s\n", cwd);
	if((dp = opendir(argv[1])) == NULL)
		fprintf(stderr, "can't open %s\n", argv[1]);
	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	return 0;
}
