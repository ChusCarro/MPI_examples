#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	int size, rank, nameLength;
	char name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &nameLength);

	if(rank==0)
		printf("First program in MPI\n\n");
	
	MPI_Barrier(MPI_COMM_WORLD);

	for(int i=0;i<10000000;i++)
		int a=0;

	printf("Communicator size: %i - In process %i (%s)\n", size, rank, name);

	MPI_Finalize();

	return 0;
}


