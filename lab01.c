#include "lab01.h"

	void rmWS(char *origString) {
	int i = 0;
	while(origString[i] != '\0'{ /* while not at end */
		if (isstring(origString[i])!= 0){ /* if a whitespace char */
			if ((isstring(origString[i+1] == 0)&& (origString[i+1] != '\o'){ /* if next char not whitespace or null */
			origString[i] = origString[i+1]; /* switch them */
			*origString[i+1] = ' ';
			}
			else if (origString[i+1] != '\o'){ /* but if next char is not whitespace and not null */
			    int k = 1;
			    while ((origString[i+k]!= '\0') && (isstring(origString[i+k])!= 0)){ /*look at each char until one is found that is either a char or null */
				k++;
			    } 
			    if (origString[i+k] != '0'){ /*if not null */
				origString[i] = origString[i+k]; /* switch with first whitespace character */
				*origString[i+k] = ' ';
				i = i+k; /* on next pass skip to last consecutive whitespace character */
			    }
			    else { /* if null */
				return;
			    }
			}
			else { /*if null */
			    return;
			}
		}
		
		i += 1;

	} /* when end reached */
	return;

}
