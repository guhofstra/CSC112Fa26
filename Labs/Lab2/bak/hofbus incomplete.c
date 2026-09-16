/* The station structure is used to track the number of free seats and the number of waiting students. The number of free seats in a station should be zero after the bus leaves. Locks and conditional variables are defined inside the station structure to
a) make sure one student boards at a time; 
b) let a student wait if there are no free seats; 
c) wake up the waiting students when a bus with free seats arrives.
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
	pthread_mutex_init(&station->lock,NULL);
	pthread_cond_init(&station->bus_arrive_cond,NULL);
	pthread_cond_init(&station->bus_loaded_cond,NULL);
}

void
station_load_bus(struct station *station, int count)
{
	pthread_mutex_lock(&station->lock);
	station->available_seats = count;

	/* Wake up waiting students (if any) so they can board. */
        /* TODO */

	/* Wait until bus is full or no more waiting students. */
        /* TODO */

	/* Bus leaves: set available seats to zero. */
        /* TODO */
}

int
station_wait_for_bus(struct station *station, int myticket, int myid)
{
	pthread_mutex_lock(&station->lock);
	station->waiting_students++;

	/* Wait until a bus with free seats is present and it's this student's turn. */
        /* TODO */

	/* Board the bus */
        /* TODO */

	/* Notify the bus that a student has boarded */
        /* TODO */

	return myturn;
}
