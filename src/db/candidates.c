#include "main.h"
#include "db.h"

int readCandidateData() {
	FILE *fp = fopen("data/fptp.txt", "rb");
	if (fp == NULL) {
		printf("Unable to Read fptp.txt\n\n");
		return 1;
	}

	fread(readCandidates, sizeof(struct Candidate), CANDIDATE_NUM, fp);

	fclose(fp);
	printf("Successfully Read fptp.txt\n");
	return 0;
}

int readCandidatePfps() {
	int i, f = 0;
	for (i = 0; i < CANDIDATE_NUM; i++) {
		CandidatePfp[i] = LoadTexture(readCandidates[i].img);
		if (CandidatePfp[i].id == 0) {
			printf("Failed to import Image for Candidate %d.", i + 1);
			f++;
		}
	}
	if (f != 0) {
		return 1;
	}
	return 0;
}