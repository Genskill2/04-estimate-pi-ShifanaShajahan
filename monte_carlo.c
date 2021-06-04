
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(void){
double mc_pi
{
	double x, y, val, error;
	unsigned long sampled = 0, hit = 0, i;
 
	do {
		/* don't check error every turn, make loop tight */
		for (i = 1000000; i; i--, sampled++) {
			x = rand() / (RAND_MAX + 1.0);
			y = rand() / (RAND_MAX + 1.0);
			if (x * x + y * y < 1) hit ++;
		}
 
		val = (double) hit / sampled;
		error = sqrt(val * (1 - val) / sampled) * 4;
		val *= 4;
 
		/* some feedback, or user gets bored */
		fprintf(stderr, "Pi = %f +/- %5.3e at %ldM samples.\r",
			val, error, sampled/1000000);
	} while (!hit || error > tolerance);
              /* !hit is for completeness's sake; if no hit after 1M samples,
                 your rand() is BROKEN */
 
	return val;
}
 

{
	printf("Pi is %f\n", pi(3e-4)); /* set to 1e-4 for some fun */
	return 0;
}



float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }
  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
    }
    }
