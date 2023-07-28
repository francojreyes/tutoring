#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int zid;
    char *name;
} Student;

#define N 20

void sort(Student students[], int n);

int main(void) {
    Student f12b[N] = {
        { .zid = 5476230, .name = "Anna Dong" },
        { .zid = 5488854, .name = "Ryan Chen" },
        { .zid = 5477273, .name = "Liam Murphy" },
        { .zid = 5242658, .name = "Ding Zhong" },
        { .zid = 5364836, .name = "Addy Qin" },
        { .zid = 5477755, .name = "Nathan Lue" },
        { .zid = 5477651, .name = "Armaan Sharma" },
        { .zid = 5476303, .name = "Zimo Luo" },
        { .zid = 5479931, .name = "Jason Tang" },
        { .zid = 5482360, .name = "Quoc Dat Ngo" },
        { .zid = 5476431, .name = "Hanshi Tang" },
        { .zid = 5306160, .name = "Qiyao Zhou" },
        { .zid = 5476427, .name = "Angela Cai" },
        { .zid = 5478228, .name = "Nathan Choi" },
        { .zid = 5422452, .name = "Ivan Zhang" },
        { .zid = 5480281, .name = "Ishman Singh" },
        { .zid = 5482203, .name = "Sebastian Zgheyb" },
        { .zid = 5477507, .name = "Kathleen Trinh" },
        { .zid = 5213658, .name = "Tony Nguyen" },
        { .zid = 5358426, .name = "Mary Shen" }
    };

    sort(f12b, N);

    for (int i = 0; i < N; i++) {
        printf("z%d %s\n", f12b[i].zid, f12b[i].name);
    }
}

void sort(Student students[], int n) {

}