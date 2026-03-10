#include <stdio.h>
#include <string.h>
struct candidate {
	char name[20];
	int fptp;
	int pr;
};
int main() {
	FILE *fp = fopen("../../data/votes.txt", "wb+");
	
	if (fp == NULL) {
        printf("File could not be opened\n");
        return 1;
    }
    
	struct candidate fptp[12];
	
	strcpy(fptp[0].name, "Balen Shah");
    fptp[0].fptp = 99999;
    fptp[0].pr = 99999;

    strcpy(fptp[1].name, "K.P. Oli");
    fptp[1].fptp = 99999;
    fptp[1].pr = 99999;

    strcpy(fptp[2].name, "Deuba");
    fptp[2].fptp = 99999;
    fptp[2].pr = 99999;

    strcpy(fptp[3].name, "Prachanda");
    fptp[3].fptp = 99999;
    fptp[3].pr = 99999;

    strcpy(fptp[4].name, "Gagan Thapa");
    fptp[4].fptp = 99999;
    fptp[4].pr = 99999;

    strcpy(fptp[5].name, "Baburam");
    fptp[5].fptp = 99999;
    fptp[5].pr = 99999;

    strcpy(fptp[6].name, "Rabi Lamichhane");
    fptp[6].fptp = 99999;
    fptp[6].pr = 99999;

    strcpy(fptp[7].name, "Madhav Nepal");
    fptp[7].fptp = 99999;
    fptp[7].pr = 99999;

    strcpy(fptp[8].name, "Shishir Khanal");
    fptp[8].fptp = 99999;
    fptp[8].pr = 99999;

    strcpy(fptp[9].name, "Ganesh Parajuli");
    fptp[9].fptp = 99999;
    fptp[9].pr = 99999;

    strcpy(fptp[10].name, "CK Raut");
    fptp[10].fptp = 99999;
    fptp[10].pr = 99999;

    strcpy(fptp[11].name, "Raj. Lingden");
    fptp[11].fptp = 99999;
    fptp[11].pr = 99999;
    
    fwrite(fptp, sizeof(struct candidate), 12, fp);
    
    fclose(fp);
    
    fp = fopen("../../data/votes.txt", "rb");

    if (fp == NULL) {
        printf("File could not be opened\n");
        return 1;
    }

    struct candidate fptp2[12];

    fread(fptp2, sizeof(struct candidate), 12, fp);

    fclose(fp);
    
    int i;

    for (i = 0; i < 12; i++) {
        printf("Candidate %d\n", i + 1);
        printf("Name: %s\n", fptp2[i].name);
        printf("FPTP: %d\n", fptp2[i].fptp);
        printf("PR: %d\n\n", fptp2[i].pr);
    }

    return 0;	
}
