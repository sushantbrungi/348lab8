#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if (score == 1) {
            printf("Program terminated.\n");
            break;
        }
        if (score < 2) {
            printf("Invalid score. Please enter a score of 2 or more.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Loops for all scoring combinations
        for (int td2 = 0; td2 * 8 <= score; td2++) {                 
            for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {   
                for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) {  
                    for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) { 
                        for (int s = 0; s * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; s++) { 
                            if (td2 * 8 + td1 * 7 + td * 6 + fg * 3 + s * 2 == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, s);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
