#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "MyMPI.h"
#define dtype double

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    if (argc != 4)
    {
        printf("usage: mpi-run -np <p> %s <in data file> <out data file> <out data file from halo array> \n", argv[0]);
        MPI_Finalize();
        exit(1);
    }

    dtype **A, *Adata, **A2, *A2data;
    int rows, cols, rows2, cols2;

    // void read_row_striped_matrix (
    //   char        *s,        /* IN - File name */
    //   void      ***subs,     /* OUT - 2D submatrix indices */
    //   void       **storage,  /* OUT - Submatrix stored here */
    //   MPI_Datatype dtype,    /* IN - Matrix element type */
    //   int         *m,        /* OUT - Matrix rows */
    //   int         *n,        /* OUT - Matrix cols */
    //   MPI_Comm     comm)     /* IN - Communicator */
    read_row_striped_matrix(argv[1], (void ***)&A, (void **)&Adata, MPI_DOUBLE, &rows, &cols, MPI_COMM_WORLD);

    // void print_row_striped_matrix (
    //    void **a,            /* IN - 2D array */
    //    MPI_Datatype dtype,  /* IN - Matrix element type */
    //    int m,               /* IN - Matrix rows */
    //    int n,               /* IN - Matrix cols */
    //    MPI_Comm comm)       /* IN - Communicator */
    print_row_striped_matrix((void **)A, MPI_DOUBLE, rows, cols, MPI_COMM_WORLD);

    // void write_row_striped_matrix (
    //    char* outFile,       /* IN - output file name */
    //    void **a,            /* IN - 2D array */
    //    MPI_Datatype dtype,  /* IN - Matrix element type */
    //    int m,               /* IN - Matrix rows */
    //    int n,               /* IN - Matrix cols */
    //    MPI_Comm comm)       /* IN - Communicator */
    write_row_striped_matrix(argv[2], (void **)A, MPI_DOUBLE, rows, cols, MPI_COMM_WORLD);

    // void read_row_striped_matrix_halo(   
    //   char        *s,        /* IN - File name */
    //   void      ***subs,     /* OUT - 2D submatrix indices */
    //   void       **storage,  /* OUT - Submatrix stored here */
    //   MPI_Datatype dtype,    /* IN - Matrix element type */
    //   int         *m,        /* OUT - Matrix rows */
    //   int         *n,        /* OUT - Matrix cols */
    //   MPI_Comm     comm)     /* IN - Communicator */ 
    read_row_striped_matrix_halo(argv[1], (void ***)&A2, (void **)&A2data, MPI_DOUBLE, &rows2, &cols2, MPI_COMM_WORLD);

    // void print_row_striped_matrix_halo(
    //    void **a,            /* IN - 2D array */
    //    MPI_Datatype dtype,  /* IN - Matrix element type */
    //    int m,               /* IN - Matrix rows */
    //    int n,               /* IN - Matrix cols */
    //    MPI_Comm comm)       /* IN - Communicator */
    print_row_striped_matrix_halo((void**)A2, MPI_DOUBLE, rows2, cols2, MPI_COMM_WORLD);

    // void exchange_row_striped_matix_halo(
    //void **a,           /* IN - 2D array */
    //MPI_Datatype dtype, /* IN - Matrix element type */
    //int m,              /* IN - Matrix rows */
    //int n,              /* IN - Matrix cols */
    //MPI_Comm comm)      /* IN - Communicator */
    //exchange_row_striped_matix_halo((void **)A2, MPI_DOUBLE, rows2, cols2, MPI_COMM_WORLD);

    // void print_row_striped_matrix_halo(
    //    void **a,            /* IN - 2D array */
    //    MPI_Datatype dtype,  /* IN - Matrix element type */
    //    int m,               /* IN - Matrix rows */
    //    int n,               /* IN - Matrix cols */
    //    MPI_Comm comm)       /* IN - Communicator */
    //print_row_striped_matrix_halo((void**)A2, MPI_DOUBLE, rows2, cols2, MPI_COMM_WORLD);

    // void write_row_striped_matrix (
    //    char* outFile,       /* IN - output file name */
    //    void **a,            /* IN - 2D array */
    //    MPI_Datatype dtype,  /* IN - Matrix element type */
    //    int m,               /* IN - Matrix rows */
    //    int n,               /* IN - Matrix cols */
    //    MPI_Comm comm)       /* IN - Communicator */
    //write_row_striped_matrix_halo(argv[3], (void**)A2, MPI_DOUBLE, rows, cols, MPI_COMM_WORLD);

    MPI_Finalize();

    return 0;
}
