#include "raylib.h"
#include<stdio.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TARGET_FPS 100
#define CANDIDATE_NUM 12

#ifndef GLOBALS
#define GLOBALS
extern int currentPos;
extern bool windowClosed;
extern bool mouseOnText;
extern bool incorrectLogin;
struct Candidate {
	char name[20];
	char img[100];
};
struct CandidateVote {
	char name[20];
	int fptp;
	int pr;
};
struct user {
	char voterId[8];
	unsigned long hash;
};
extern struct Candidate readCandidates[CANDIDATE_NUM];
extern struct CandidateVote readCandidateVotes[CANDIDATE_NUM];
extern Texture2D CandidatePfp[CANDIDATE_NUM];
#endif

#define WELCOME_PADDING 50