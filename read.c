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
   char *data;
   // char *infile = "/mnt/data/alignment/hg38.fa.gz.bwt";
   char *infile = getenv("BIGFILE");

   if ((fd = open(infile,O_RDONLY)) < 0) 
      err(EX_NOINPUT, "%s", infile);

   if ((data = malloc(bytes_expected)) == NULL)
      err(EX_OSERR, "data malloc");
   printf("chunk size: %d after malloc", sizeof(data));

   bytes_read = read(fd, data, bytes_expected);
   printf("chunk size: %d after read", sizeof(data));

   if (bytes_read != bytes_expected) 
      err(EX_DATAERR, "Read only %d of %d bytes", 
         bytes_read, bytes_expected);

   /* ... operate on data ... */
   int toSleep = 10;
   int slept = 0;

   int i;
   for (i=0; i<toSleep; i++) {
      sleep(1);
      slept++;
      printf("sleeping %d of %d\n", slept, 10);
   }

   printf("chunk size: %d", sizeof(data));

   free(data);

   exit(EX_OK);
}