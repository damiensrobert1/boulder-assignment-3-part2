#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <linux/limits.h>

int main (int argc,char **argv) {

   if (argc != 3) {
      exit(EXIT_FAILURE);
   } else {
      FILE *file;
      char filepath[PATH_MAX] = "";
      char str[ARG_MAX] = "";

      if (strlen(argv[1]) <= PATH_MAX) {
         strcpy(filepath, argv[1]);
      } else {
         exit(EXIT_FAILURE);
      }

      if (strlen(argv[1]) <= ARG_MAX) {
         strcpy(str, argv[2]);
      } else {
         exit(EXIT_FAILURE);
      }

      file = fopen(filepath,"w");

      if (file == NULL) {
	 exit(EXIT_FAILURE);
      } else {
         fprintf(file,"%s", str);
      }

      fclose(file);
   }

   exit(EXIT_SUCCESS);
}
