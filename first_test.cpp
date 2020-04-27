#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){

	int groupSize, rank, nameLength;
	char* processorName;

	MPI_Init(&argc,&argv); 

	MPI_Comm_size(MPI_COMM_WORLD, &groupSize); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank==0){
		printf("\n\n----------------------------\n");
		printf(" - First program with MPI - \n");
		printf("----------------------------\n\n");
		printf("Group size: %i\n", groupSize);
	}
	
	MPI_Barrier(MPI_COMM_WORLD);
	
	MPI_Get_processor_name(processorName, &nameLength);
	 
	printf("Rank: %i (%s)\n", rank, processorName);

	MPI_Finalize();

	return 0;
}
