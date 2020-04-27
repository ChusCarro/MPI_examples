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
		
		for(int i=1;i<groupSize;i++){
			int value = i*i + 1;
			MPI_Send(&value,1,MPI_INT,i,1,MPI_COMM_WORLD);
		}
	}
        else{	
		MPI_Get_processor_name(processorName, &nameLength);
		int buffer = -1;
		MPI_Status status;
		MPI_Recv(&buffer,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("Message received: %i - Message at: %i (%s)\n",buffer, rank, processorName);

	}

	MPI_Finalize();

	return 0;
}
