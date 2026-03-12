#include "main.h"
#include "db.h"
#include <string.h>

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

int readCandidateVoteData() {
	FILE* fp = fopen("data/votes.txt", "rb");
	if (fp == NULL) {
		printf("Unable to Read votes.txt\n\n");
		return 1;
	}

	fread(readCandidateVotes, sizeof(struct CandidateVote), CANDIDATE_NUM, fp);

	fclose(fp);
	printf("Successfully Read votes.txt\n");
	return 0;
}

int updateCandidateVoteData(int type, int n) {
	FILE* fp = fopen("data/votes.txt", "wb");
	if (fp == NULL) {
		printf("Unable to Open votes.txt\n\n");
		return 1;
	}

	int i;
	
	for (i = 0; i < CANDIDATE_NUM; i++) {
		if (i == n) {
			if (type == 1) {
				readCandidateVotes[i].fptp += 1;
			}
			else if (type == 2) {
				readCandidateVotes[i].pr += 1;
			}
		}
	}
	fwrite(readCandidateVotes, sizeof(struct CandidateVote), CANDIDATE_NUM, fp);

	fclose(fp);
	printf("Successfully Updates votes.txt\n");
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

unsigned long hashFunction(const char* password) {
	unsigned long hash = 6767;
	int c;

	// DJB2 Algorithm (5381)

	while ((c = *password++)) {
		hash = ((hash << 5) + hash) + c;
	}

	return hash;
}

int checkLogin(const char* voterid, const char* pin) {
	FILE* fp = fopen("data/users.txt", "rb");
	if (fp == NULL) {
		printf("\nFailed to open users.txt\n");
	}
	struct user a;
	while (fread(&a, sizeof(struct user), 1, fp) == 1) {
		if (strcmp(a.voterId, voterid) == 0) {
			if (a.hash == hashFunction(pin)) {
				printf("\nLogged In Successfully\n");
				strcpy(voterid, "");
				strcpy(pin, "");
				incorrectLogin = false;
				return 0;
			}
		}
	}
	fclose(fp);
	incorrectLogin = true;
	return 1;
}