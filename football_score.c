#include <stdio.h>

void findCombinations(int score) {
    int td = 0, fg = 0, safety = 0, td2pt = 0, td1pt = 0;

    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
    for (td2pt = 0; td2pt * 8 <= score; td2pt++) {
        for (td1pt = 0; td1pt * 7 + td2pt * 8 <= score; td1pt++) {
            for (td = 0; td * 6 + td1pt * 7 + td2pt * 8 <= score; td++) {
                for (fg = 0; fg * 3 + td * 6 + td1pt * 7 + td2pt * 8 <= score; fg++) {
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td1pt * 7 + td2pt * 8 <= score; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + td1pt * 7 + td2pt * 8 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    printf("Enter 0 or 1 to STOP\n");

    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        findCombinations(score);
    }

    return 0;
}
