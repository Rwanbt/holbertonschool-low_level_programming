#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
    clock_t t_global_start, t_global_end;
    clock_t t_start, t_end;
    double d_total, d_build, d_process, d_reduce;	
    unsigned long checksum;

    t_global_start = clock();/* Students must add clock-based timing and print required lines. */

    t_start = clock();
    build_dataset();
    t_end = clock();
    d_build = (double)(t_end - t_start) / CLOCKS_PER_SEC;

    t_start = clock();
    process_dataset();
    t_end = clock();
    d_process = (double)(t_end - t_start) / CLOCKS_PER_SEC;

    t_start = clock();
    checksum = reduce_checksum();
    t_end = clock();
    d_reduce = (double)(t_end - t_start) / CLOCKS_PER_SEC;

    if (checksum == 0ul)
        printf("impossible\n");

    t_global_end = clock();
    d_total = (double)(t_global_end - t_global_start) / CLOCKS_PER_SEC;

    /* Required output (exact format, no extra lines):
     * TOTAL seconds: <float>
     * BUILD_DATA seconds: <float>
     * PROCESS seconds: <float>
     * REDUCE seconds: <float>
     */
    printf("TOTAL seconds: %.6f\n", d_total);
    printf("BUILD_DATA seconds: %.6f\n", d_build);
    printf("PROCESS seconds: %.6f\n", d_process);
    printf("REDUCE seconds: %.6f\n", d_reduce);

    return 0;
}
