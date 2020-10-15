#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    errno = 0;
    struct film* films_arr = (struct film*) malloc(sizeof(struct film) * films_count);
    perror("malloc() ");
    fill_arr(films_arr);

    struct film wishes;
    char finding_genre[genre_size - 1];
    float min_score = 0.f;
    float max_score = 10.f;
    int finding_year = 0;

    enter_wishes(finding_genre, &min_score, &max_score, &finding_year);
//    printf("%s %2.1f %2.1f %d\n", finding_genre, min_score, max_score, finding_year);

//    for (size_t i = 0; i < films_count; ++i) {
//        printf("%s\n", films_arr[i].genre);
//    }
    find_films(finding_genre, min_score, max_score, finding_year, films_arr);

    errno = 0;
    free(films_arr);
    perror("free() ");
    return 0;
}
