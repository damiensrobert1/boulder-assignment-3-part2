#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <linux/limits.h>
#include <syslog.h>

int main (int argc,char **argv) {

   setlogmask (LOG_UPTO (LOG_DEBUG));
   
   openlog ("writer_prog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);
   
   syslog (LOG_DEBUG, "Writing %s to %s", argv[2], basename(argv[1]));
   
      
   if (argc != 3) {
      syslog (LOG_ERR, "This program wasn't called with proper arguments");
      closelog ();
      exit(EXIT_FAILURE);
   } else {
      FILE *file;
      char filepath[PATH_MAX] = "";
      char str[ARG_MAX] = "";

      if (strlen(argv[1]) <= PATH_MAX) {
         strcpy(filepath, argv[1]);
      } else {
         syslog (LOG_ERR, "First argument is not suitable.");
         closelog ();
         exit(EXIT_FAILURE);
      }

      if (strlen(argv[1]) <= ARG_MAX) {
         strcpy(str, argv[2]);
      } else {
         syslog (LOG_ERR, "Second argument is not suitable.");
         closelog ();
         exit(EXIT_FAILURE);
      }

      file = fopen(filepath,"w");

      if (file == NULL) {
         syslog (LOG_ERR, "Failed to open the file : %s", filepath);
         closelog ();
	 exit(EXIT_FAILURE);
      } else {
         fprintf(file,"%s", str);
      }

      fclose(file);
   }
   
 

   exit(EXIT_SUCCESS);
}
