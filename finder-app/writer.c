#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <linux/limits.h>

int main (int argc,char **argv) {
   int ret = 0;

   if (argc != 3) {
      ret = 1;
   } else {
      FILE *file;
      char filepath[PATH_MAX] = "";
      char str[ARG_MAX] = "";

      if (strlen(argv[1]) <= PATH_MAX) {
         strcpy(filepath, argv[1]);
      } else {
         ret = 1;
      }

      if (strlen(argv[1]) <= ARG_MAX) {
         strcpy(str, argv[2]);
      } else {
         ret = 1;
      }

      file = fopen(filepath,"w");

      if (file == NULL) {
	 ret = 1;
      } else {
         fprintf(file,"%s", str);
      }

      fclose(file);
   }

   exit(ret);
}
