/*
 * CSC112 Lab 2: Hofstra Bus System
 * Student starter file
 */

struct station {
    int available_seats;
    int waiting_students;
    int next_ticket;
    int next_student;
    pthread_mutex_t lock;
    pthread_cond_t bus_arrive_cond;
    pthread_cond_t bus_loaded_cond;
};

void
station_init(struct station *station)
{
    station->waiting_students = 0;
    station->available_seats = 0;
    station->next_ticket = 1;
    station->next_student = 1;
    pthread_mutex_init(&station->lock, NULL);
    pthread_cond_init(&station->bus_arrive_cond, NULL);
    pthread_cond_init(&station->bus_loaded_cond, NULL);
}

void
station_load_bus(struct station *station, int count)
{
    pthread_mutex_lock(&station->lock);
    station->available_seats = count;

    /* Wake waiting students so eligible students can board. */
    /* TODO */

    /* Wait until the bus is full or no students remain waiting. */
    /* TODO */

    /* The bus leaves. Reset the number of available seats. */
    /* TODO */
}

int
station_wait_for_bus(struct station *station, int myticket)
{
    pthread_mutex_lock(&station->lock);
    station->waiting_students++;

    /* Wait for a free seat and the student's ticket turn. */
    /* TODO */

    /* Board the bus and determine the student's boarding turn. */
    /* TODO */

    /* Notify the bus and allow the next eligible student to proceed. */
    /* TODO */

    return myturn;
}
