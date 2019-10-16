#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <fcntl.h>
#include <sysexits.h>
#include <unistd.h>

int
main()
{
   int fd; 
   size_t bytes_read, bytes_expected = 100000000*sizeof(double); 
   double *data;
   char *infile = "file.dat";

   if ((fd = open(infile,O_RDONLY)) < 0) 
      err(EX_NOINPUT, "%s", infile);

   if ((data = malloc(bytes_expected)) == NULL)
      err(EX_OSERR, "data malloc");

   bytes_read = read(fd, data, bytes_expected);

   if (bytes_read != bytes_expected) 
      err(EX_DATAERR, "Read only %d of %d bytes", 
         bytes_read, bytes_expected);

   /* ... operate on data ... */

   free(data);

   exit(EX_OK);
}