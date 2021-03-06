#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>


struct region {        /* Defines "structure" of shared memory */
	int len;
	char buf[100];
};

#define MAX_LEN sizeof(struct region)*3

int main()
{
	void *shm_area;
	struct region *rptr;
	int fd;

	/* Create shared memory object and set its size */
	
	
	fd = shm_open("./myshm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1)
	    printf("\n Failed to open shared memory object\n");


	if (ftruncate(fd,  MAX_LEN) == -1)
	    printf("\n Failed to set the size of the shared memory object\n");
	getchar();
	/* Map shared memory object */
	shm_area = mmap(NULL,  MAX_LEN,PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (shm_area == MAP_FAILED)
	    printf("\n Failed to map the shared memory\n");
	
	rptr = (struct region *)shm_area;	
	strcpy(rptr->buf,"Message One");
	rptr->len=strlen("Message One");
	rptr++;
	strcpy(rptr->buf,"Message Two");
	rptr->len=strlen("Message Two");
	rptr++;
	strcpy(rptr->buf,"Message Three");
	rptr->len=strlen("Message Three");
	getchar();
	if (munmap (shm_area, MAX_LEN))
       	    printf("\n Failed to map the shared memory\n");
	getchar();
	close(fd);

}
