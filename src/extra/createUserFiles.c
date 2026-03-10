#include <stdio.h>
#include <string.h>
struct user {
	char voterId[8];
	unsigned long hash;
};
struct userSrc {
	char voterId[8];
	char pin[6];
};
unsigned long hashFunction(const char* password) {
	unsigned long hash = 6767;
	int c;

	while ((c = *password++)) {
		hash = ((hash << 5) + hash) + c;
	}

	return hash;
}
int main() {
	FILE *fp = fopen("../../data/users.txt", "wb+");
	if(fp == NULL) {
		printf("Failed to Create file.");
		return 0;
	}
	
	struct userSrc a[2];
	struct user b[2];
	
	strcpy(a[0].voterId, "123456");
	strcpy(a[0].pin, "1234");
	
	strcpy(a[1].voterId, "987654");
	strcpy(a[1].pin, "9876");
	
	int i;
	for(i=0; i<2; i++) {
		strcpy(b[i].voterId, a[i].voterId);
		b[i].hash = hashFunction(a[i].pin);
		
		printf("VoterID: %s\n", b[i].voterId);
		printf("Hash: %lu\n\n", b[i].hash);
	}
	
	fwrite(b, sizeof(struct user), 2, fp);
	
	fclose(fp);
	
	fp = fopen("../../data/users.txt", "rb");
	
	struct user c[2];
	
	fread(c, sizeof(struct user), 2, fp);
	
	printf("\n\nRead Vals.\n");
	
	for(i=0; i<2; i++) {		
		printf("VoterID: %s\n", c[i].voterId);
		printf("Hash: %lu\n\n", c[i].hash);
	}
	
	return 0;
}
