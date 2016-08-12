#include <stdio.h>

int main(void) {
	char login_name[150];
	char password[150];

	fprintf(stdout, "Login : ");
	if(fgets(login_name, sizeof(login_name), stdin) == NULL) {
		fprintf(stderr, "No login name\n");
		return 1;
	}
	/* flush standard input */
	fseek(stdin, 0, SEEK_END);
	fprintf(stdout, "Password : ");
	if(fgets(password, sizeof(password), stdin) == NULL) {
		fprintf(stderr, "No password\n");
		return 1;
	}
	fprintf(stdout, "Result:\n%s%s\n", login_name, password);
	return 0;
}
