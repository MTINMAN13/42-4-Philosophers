#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_PHILOSOPHERS 10
#define DEFAULT_NUMBER_OF_PHILOSOPHERS 5
#define DEFAULT_OPTIONAL -1
#define DEFAULT_TIME_TO_DIE 1000000 // in microseconds
#define DEFAULT_TIME_TO_EAT 1000000 // in microseconds
#define DEFAULT_TIME_TO_SLEEP 1000000 // in microseconds

pthread_mutex_t forks[MAX_PHILOSOPHERS] = {PTHREAD_MUTEX_INITIALIZER};
pthread_t philosophers[MAX_PHILOSOPHERS];
struct timeval last_meal_time[MAX_PHILOSOPHERS];
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for printing


int number_of_philosophers = DEFAULT_NUMBER_OF_PHILOSOPHERS;
long time_to_die = DEFAULT_TIME_TO_DIE;
long time_to_eat = DEFAULT_TIME_TO_EAT;
long time_to_sleep = DEFAULT_TIME_TO_SLEEP;
int number_of_times_each_philosopher_must_eat = DEFAULT_OPTIONAL;

void timestamp(void)
{
	struct timeval	tv;
	struct tm		*timeinfo;

	gettimeofday(&tv, NULL);
	timeinfo = gmtime(&(tv.tv_sec));
	printf("%02d:%02d:%02d.%06ld | ", timeinfo->tm_hour,
		timeinfo->tm_min, timeinfo->tm_sec, tv.tv_usec);
}

void	print(const char *format, ...)
{
	va_list	args;

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
        // Thinking
        print("Philosopher %d is thinking.\n", philosopher_id);

        // Attempt to pick up either fork
        if (pthread_mutex_trylock(&forks[left_fork]) == 0) {
            print("Philosopher %d picked up left fork.\n", philosopher_id);

            // Attempt to pick up the other fork
            if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
                print("Philosopher %d picked up right fork. Starting to eat.\n", philosopher_id);

                // Eating
                gettimeofday(&last_meal_time[philosopher_id], NULL);
                print("Philosopher %d is eating.\n", philosopher_id);

                // Release right fork
                pthread_mutex_unlock(&forks[right_fork]);
                // Release left fork
				usleep(2);
                pthread_mutex_unlock(&forks[left_fork]);
                print("Philosopher %d released his forks.\n", philosopher_id);

                // Sleeping after eating
                sleepForDuration(time_to_sleep);

                // Check if it's time to die
                struct timeval current_time;
                gettimeofday(&current_time, NULL);
                long elapsed_time = (current_time.tv_sec - last_meal_time[philosopher_id].tv_sec) * 1000000 +
                                    (current_time.tv_usec - last_meal_time[philosopher_id].tv_usec);
                if (elapsed_time >= time_to_die) {
                    print("Philosopher %d died. Ending simulation.\n", philosopher_id);
                    exit(0);
                }
            } else {
                // Release left fork if right fork is not available
                pthread_mutex_unlock(&forks[left_fork]);
            }
        }

        // Attempt to pick up the other fork first
        if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
            print("Philosopher %d picked up right fork.\n", philosopher_id);

            // Attempt to pick up the other fork
            if (pthread_mutex_trylock(&forks[left_fork]) == 0) {
                print("Philosopher %d picked up left fork. Starting to eat.\n", philosopher_id);

                // Eating
                gettimeofday(&last_meal_time[philosopher_id], NULL);
                print("Philosopher %d is eating.\n", philosopher_id);
				usleep(2);

                // Release left fork
                pthread_mutex_unlock(&forks[left_fork]);
                // Release right fork
				usleep(2);
                pthread_mutex_unlock(&forks[right_fork]);
                print("Philosopher %d released his forks.\n", philosopher_id);
				usleep(2);
                // Sleeping after eating
                print("Philosopher %d is sleeping.\n", philosopher_id);
                sleepForDuration(time_to_sleep);

                // Check if it's time to die
                struct timeval current_time;
                gettimeofday(&current_time, NULL);
                long elapsed_time = (current_time.tv_sec - last_meal_time[philosopher_id].tv_sec) * 1000000 +
                                    (current_time.tv_usec - last_meal_time[philosopher_id].tv_usec);
                if (elapsed_time >= time_to_die) {
                    print("Philosopher %d died. Ending simulation.\n", philosopher_id);
                    exit(0);
                }
            } else {
                // Release right fork if left fork is not available
                pthread_mutex_unlock(&forks[right_fork]);
            }
        }

        // Sleeping before retrying
        usleep(time_to_sleep);
    }
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc >= 5) {
        number_of_philosophers = atoi(argv[1]);
        time_to_die = atol(argv[2]);
        time_to_eat = atol(argv[3]);
        time_to_sleep = atol(argv[4]);
		number_of_times_each_philosopher_must_eat = atol(argv[5]);
    } else {
        printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> and optionally <number_of_times_each_philosopher_must_eat>\n", argv[0]);
        return 1;
    }

    if (number_of_philosophers > MAX_PHILOSOPHERS || number_of_philosophers < 1) {
        printf("Invalid number of philosophers. Must be between 1 and %d.\n", MAX_PHILOSOPHERS);
        return 1;
    }

    // Create philosopher threads
    int philosopher_ids[MAX_PHILOSOPHERS];
    for (int i = 0; i < number_of_philosophers; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_thread, &philosopher_ids[i]);
    }

    // Wait for philosopher threads to finish (this won't happen in this example as threads are infinite)
    for (int i = 0; i < number_of_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}
