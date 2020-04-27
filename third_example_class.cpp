#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	int size, rank, nameLength;
	char name[MPI_MAX_PROCESSOR_NAME];

	MPI_Status status;
	
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &nameLength);

	int value = -1;

	if(rank==0){
		printf("First program in MPI\n\n");
		
		printf("Group size: %i\n", size);
		value = 1023;
	}


	MPI_Bcast(name, MPI_MAX_PROCESSOR_NAME, MPI_CHAR, 0, MPI_COMM_WORLD);


	if(rank!=0) {

		printf("Messgate received: %s\n",  name);


//		buffer = -buffer;
//		MPI_Send(&buffer, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);

	}



	MPI_Finalize();

	return 0;
}


