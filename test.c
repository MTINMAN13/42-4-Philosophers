#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_PHILOSOPHERS 11
#define DEFAULT_NUMBER_OF_PHILOSOPHERS 5
#define DEFAULT_OPTIONAL -1
#define DEFAULT_TIME_TO_DIE 1000000
#define DEFAULT_TIME_TO_EAT 1000000
#define DEFAULT_TIME_TO_SLEEP 1000000

pthread_mutex_t forks[MAX_PHILOSOPHERS] = { PTHREAD_MUTEX_INITIALIZER };
pthread_t philosophers[MAX_PHILOSOPHERS];
struct timeval last_meal_time[MAX_PHILOSOPHERS];
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
int *eat_counter;

int number_of_philosophers = DEFAULT_NUMBER_OF_PHILOSOPHERS;
long time_to_die = DEFAULT_TIME_TO_DIE;
long time_to_eat = DEFAULT_TIME_TO_EAT;
long time_to_sleep = DEFAULT_TIME_TO_SLEEP;
int number_of_times_each_philosopher_must_eat = DEFAULT_OPTIONAL;

void timestamp(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("%02d:%02d:%02d.%06ld | ", gmtime(&tv.tv_sec)->tm_hour,
        gmtime(&tv.tv_sec)->tm_min, gmtime(&tv.tv_sec)->tm_sec, tv.tv_usec);
}

void print(const char *format, ...) {
    va_list args;
    pthread_mutex_lock(&print_mutex);
    timestamp();
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    pthread_mutex_unlock(&print_mutex);
}

void sleepForDuration(long duration) {
    usleep(duration);
}

void *philosopher_thread(void *arg) {
    int philosopher_id = *(int *)arg + 1;
    int left_fork = philosopher_id - 1;
    int right_fork = philosopher_id % number_of_philosophers;

    while (1) {
        print("Philosopher %d is thinking.\n", philosopher_id);

        if (pthread_mutex_trylock(&forks[left_fork]) == 0) {
            print("Philosopher %d picked up left fork.\n", philosopher_id);

            if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
                print("Philosopher %d picked up right fork. Starting to eat.\n", philosopher_id);
                gettimeofday(&last_meal_time[philosopher_id], NULL);
                print("Philosopher %d is eating.\n", philosopher_id);
                eat_counter[philosopher_id - 1] += 1;
                pthread_mutex_unlock(&forks[right_fork]);
                usleep(2);
                pthread_mutex_unlock(&forks[left_fork]);
                print("Philosopher %d released his forks.\n", philosopher_id);
                sleepForDuration(time_to_sleep);

                struct timeval current_time;
                gettimeofday(&current_time, NULL);
                long elapsed_time = (current_time.tv_sec - last_meal_time[philosopher_id].tv_sec) * 1000000 +
                    (current_time.tv_usec - last_meal_time[philosopher_id].tv_usec);
                if (elapsed_time >= time_to_die) {
                    print("Philosopher %d died. Ending simulation.\n", philosopher_id);
                    exit(0);
                }
            } else {
                pthread_mutex_unlock(&forks[left_fork]);
            }
        }

        if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
            print("Philosopher %d picked up right fork.\n", philosopher_id);

            if (pthread_mutex_trylock(&forks[left_fork]) == 0) {
                print("Philosopher %d picked up left fork. Starting to eat.\n", philosopher_id);
                gettimeofday(&last_meal_time[philosopher_id], NULL);
                print("Philosopher %d is eating.\n", philosopher_id);
                eat_counter[philosopher_id - 1] += 1;
                usleep(2);
                pthread_mutex_unlock(&forks[left_fork]);
                usleep(2);
                pthread_mutex_unlock(&forks[right_fork]);
                print("Philosopher %d released his forks.\n", philosopher_id);
                usleep(2);
                print("Philosopher %d is sleeping.\n", philosopher_id);
                sleepForDuration(time_to_sleep);

                struct timeval current_time;
                gettimeofday(&current_time, NULL);
                long elapsed_time = (current_time.tv_sec - last_meal_time[philosopher_id].tv_sec) * 1000000 +
                    (current_time.tv_usec - last_meal_time[philosopher_id].tv_usec);
                if (elapsed_time >= time_to_die) {
                    print("Philosopher %d died. Ending simulation.\n", philosopher_id);
                    exit(0);
                }
            } else {
                pthread_mutex_unlock(&forks[right_fork]);
            }
        }

        if (number_of_times_each_philosopher_must_eat != DEFAULT_OPTIONAL &&
            eat_counter[philosopher_id - 1] >= number_of_times_each_philosopher_must_eat) {
            print("Philosopher %d has eaten %d times. Ending simulation.\n", philosopher_id, number_of_times_each_philosopher_must_eat);
            exit(0);
        }

        usleep(time_to_sleep);
    }
}

int main(int argc, char *argv[]) {
    if (argc >= 5) {
        number_of_philosophers = atoi(argv[1]);
        time_to_die = atol(argv[2]);
        time_to_eat = atol(argv[3]);
        time_to_sleep = atol(argv[4]);
        number_of_times_each_philosopher_must_eat = atoi(argv[5]);
		eat_counter = calloc(MAX_PHILOSOPHERS, sizeof(int));
    } else {
        printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> and optionally <number_of_times_each_philosopher_must_eat>\n", argv[0]);
        return 1;
    }

    if (number_of_philosophers > MAX_PHILOSOPHERS || number_of_philosophers < 1) {
        printf("Invalid number of philosophers. Must be between 1 and %d.\n", MAX_PHILOSOPHERS);
        return 1;
    }

    int philosopher_ids[MAX_PHILOSOPHERS];
    for (int i = 0; i < number_of_philosophers; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_thread, &philosopher_ids[i]);
    }

    for (int i = 0; i < number_of_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }
	free(eat_counter);
    return 0;
}
