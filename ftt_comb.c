#include <unistd.h>
void write_n(char v[])
{
  if (v[0] == '7' && v[1] == '8' && v[2] == '9')
  {
    write(1, v, 3); //escvra in 3 firts bytes
    write(1, ".\n", 2);
  }
  else
  {
    write(1, v, 5);
  }
}

int main() {
  char v[5]; //Zero-based indexing
  
  v[0] = '0'; // int in 48 
  v[3] = ','; //44 in ASCII = 44 
  v[4] = ' '; // 32 in ASCII 
  
  while(v[0] <= '7') // 48 + 7 
  {
    v[1] = v[0] + 1;
    while(v[1] <= '8')
    {
      v[0]++;
      v[2] = v[1] + 1;
      while(v[2] <= '9')
      {
        write_n(v);
        v[2]++;
        }
        v[1]++;
      }
      v[0]++;
    }
  
  
  //Objective numbers  7  8  9 

  return 0;
}