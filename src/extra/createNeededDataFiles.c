#include <stdio.h>
#include <string.h>
struct candidate {
	char name[20];
	char img[100];
};
int main() {
	FILE *fp = fopen("../../data/fptp.txt", "wb+");
	
	if (fp == NULL) {
        printf("File could not be opened\n");
        return 1;
    }
    
	struct candidate fptp[12];
	
	strcpy(fptp[0].name, "Balen Shah");
    strcpy(fptp[0].img, "assets/ppl/Balen.png");

    strcpy(fptp[1].name, "K.P. Oli");
    strcpy(fptp[1].img, "assets/ppl/KPBa.png");

    strcpy(fptp[2].name, "Deuba");
    strcpy(fptp[2].img, "assets/ppl/Deuba.png");

    strcpy(fptp[3].name, "Prachanda");
    strcpy(fptp[3].img, "assets/ppl/Prachanda.png");

    strcpy(fptp[4].name, "Gagan Thapa");
    strcpy(fptp[4].img, "assets/ppl/Gagan.png");

    strcpy(fptp[5].name, "Baburam");
    strcpy(fptp[5].img, "assets/ppl/Baburam.png");

    strcpy(fptp[6].name, "Rabi Lamichhane");
    strcpy(fptp[6].img, "assets/ppl/Rabi.png");

    strcpy(fptp[7].name, "Madhav Nepal");
    strcpy(fptp[7].img, "assets/ppl/Madhav.png");

    strcpy(fptp[8].name, "Shishir Khanal");
    strcpy(fptp[8].img, "assets/ppl/Shishir.png");

    strcpy(fptp[9].name, "Ganesh Parajuli");
    strcpy(fptp[9].img, "assets/ppl/Ganesh.png");

    strcpy(fptp[10].name, "CK Raut");
    strcpy(fptp[10].img, "assets/ppl/CK.png");

    strcpy(fptp[11].name, "Raj. Lingden");
    strcpy(fptp[11].img, "assets/ppl/Rajendra.png");
    
    fwrite(fptp, sizeof(struct candidate), 12, fp);
    
    fclose(fp);
    
    fp = fopen("../../data/fptp.txt", "rb");

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
        printf("Image: %s\n\n", fptp2[i].img);
    }

    return 0;	
}
