/*

hasznald : ./exor kulcs <tiszta.txt> titkos.szoveg


*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_KULCS 10
#define BUFFER_MERET 256

int main (int argc, char **argv)
{

  char kulcs[MAX_KULCS]; // a kulcs tárolására szolgáló chartömb
  char buffer[BUFFER_MERET]; // a buffer betöltésére szolgáló chartömb

  int kulcs_index = 0;
  int olvasott_bajtok = 0;

  int kulcs_meret = strlen (argv[1]); //./exor <kulcs> hosszának tárolása
  strncpy (kulcs, argv[1], MAX_KULCS); //kulcs másolása a terminálból ./exor <kulcs>

  while ((olvasott_bajtok = read (0, (void *) buffer, BUFFER_MERET)))
    {

      for (int i = 0; i < olvasott_bajtok; ++i)
        {

      	  buffer[i] = buffer[i] ^ kulcs[kulcs_index];
      	  kulcs_index = (kulcs_index + 1) % kulcs_meret;

        }

      write (1, buffer, olvasott_bajtok);

    }
}
