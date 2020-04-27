#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	
	int groupSize, rank, nameLength;
	char processorName[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc,&argv); 

	MPI_Comm_size(MPI_COMM_WORLD, &groupSize); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank==0){
		printf("\n\n----------------------------\n");
		printf(" - First program with MPI - \n");
		printf("----------------------------\n\n");
		printf("Group size: %i\n", groupSize);
	}	
		
	int value = 1023;
	MPI_Bcast(&value,1,MPI_INT,0,MPI_COMM_WORLD);

	if(rank!=0){
		MPI_Get_processor_name(processorName, &nameLength);
		printf("Message received: %i - Message at: %i (%s)\n",value, rank, processorName);
	}

	MPI_Finalize();

	return 0;
}
