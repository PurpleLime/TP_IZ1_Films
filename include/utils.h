#ifndef TP_IZ1_FILMS_UTILS_H
#define TP_IZ1_FILMS_UTILS_H

#include <string.h>
#include <stdio.h>
#include <errno.h>

#define title_size 50
#define genre_size 25
#define films_count 5

struct film {
    float avg_score;
    int year;
    char genre[genre_size];
    char title[title_size];
};

int fill_arr(struct film* films_arr) {
    strncpy(films_arr[0].title, "Побег из Шоушенка", title_size - 1);
    strncpy(films_arr[0].genre, "драма", genre_size - 1);
    films_arr[0].avg_score = 9.1f;
    films_arr[0].year = 1994;

    strncpy(films_arr[1].title, "Зеленая миля", title_size - 1);
    strncpy(films_arr[1].genre, "фантастика", genre_size - 1);
    films_arr[1].avg_score = 9.1f;
    films_arr[1].year = 1999;

    strncpy(films_arr[2].title, "Форрест Гамп", title_size - 1);
    strncpy(films_arr[2].genre, "мелодрама", genre_size - 1);
    films_arr[2].avg_score = 8.9f;
    films_arr[2].year = 1994;

    strncpy(films_arr[3].title, "1+1", title_size - 1);
    strncpy(films_arr[3].genre, "комедия", genre_size - 1);
    films_arr[3].avg_score = 8.8f;
    films_arr[3].year = 2011;

    strncpy(films_arr[4].title, "Начало", title_size - 1);
    strncpy(films_arr[4].genre, "фантастика", genre_size - 1);
    films_arr[4].avg_score = 8.7f;
    films_arr[4].year = 2010;

    return 0;
}

int enter_wishes(char* finding_genre, float* min_score, float* max_score, int* finding_year) {
    errno = 0;
    printf("%s", "Введите жанр, минимальную и максимальную оценку и год выхода желаемого фильма "
                 "в описанной последовательности (каждое значение с новой строки). Если не знаете, что написать, "
                 "введите \"-1\".\n");
    perror("printf() ");

    errno = 0;
    scanf("%19s%f%f%d", finding_genre, &*min_score, &*max_score, &*finding_year);
    perror("scanf() ");
    return 0;
}

int find_films(char* finding_genre, float min_score, float max_score, int finding_year, struct film* films_arr) {
    for (size_t i = 0; i < films_count; ++i) {
        if ((strcmp(finding_genre, films_arr[i].genre) == 0 || strcmp(finding_genre, "-1") == 0)
            && (min_score <= films_arr[i].avg_score)
            && ((max_score >= films_arr[i].avg_score) || (max_score == -1))
            && ((finding_year == films_arr[i].year) || finding_year == -1)) {

            errno = 0;
            printf("Название:%s Жанр:%s Оценка:%2.1f Год:%d\n", films_arr[i].title, films_arr[i].genre,
                    films_arr[i].avg_score, films_arr[i].year);
            perror("printf() ");
        }
    }
    return 0;
}



#endif //TP_IZ1_FILMS_UTILS_H
