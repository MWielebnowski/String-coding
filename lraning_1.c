#include <stdio.h>
#include <limits.h>
#include <ctype.h>

char* kodowanie(char input[]);
char* dekodowanie(char input[]);


int main(){
	char input[] = {'A','W','W','C','X','X'};

	char *a;
	a = kodowanie(input);
	char *b;
	b = dekodowanie(a);

	int i = 0;
	size_t n = sizeof(a)/sizeof(a[0]);

	//printf("%d\n",n);

	printf("KOD:");
	for(i = 0; i < n ; i++){
		printf("%c", a[i]);
	}

	n = sizeof(b)/sizeof(b[0]);

	printf("\nDEKOD:");
		for(i = 0; i < n ; i++){
			printf("%c", b[i]);
		}

	free(a);
	free(b);
	return 0;
}

char* kodowanie(char input[]){
	int i = 0;
		int n1 = 1;
		int m = 1;
		char temp = input [0];
		size_t n = strlen(input);
		char *a = (char*)malloc(sizeof(char));
		//printf("to jest n:%d", n);
		a[0] = input[0];
		//printf("%c\n",a[0]);
		for(i = 1; i < n; ++i){
			//printf("Inter %d: \n",i);
			if(temp == input [i]){
				m++;
				//printf("m:%d\n",m);
			}
			if(m != 1 && temp != input[i]){
				n1 ++;
				a = realloc(a, n1 * sizeof(char));
				a[n1] = m + '0';
				m = 1;
				//printf("zapis powtorka, n1:%d, a[n1-1]:%c, a[n1]:%c\n ",n1,a[n1-1],a[n1]);
			}
			if (m == 1  && temp != input[i]){
				n1++;
				a = realloc(a, n1 * sizeof(char));
				a[n1] = input[i];
				//printf("brak powtorka, n1:%d, a[%d]: %c\n",n1,n1,a[n1]);
			}
			temp = input[i];
		}
		return a;
}

char* dekodowanie(char input[]){
	size_t n = LENGTH;
	char *a = (char*)malloc(sizeof(char));
	int i, j, num = 0;
	int n1 = 0;
	a[0] = input[0];
	char temp = input[0];
	//printf("n dekod: %d\n",n);

	for(i = 1; i < n; i++){
		//printf("Iter %d: \n",i);
		if(isdigit(input[i])){ //jesli jest lb
			num = input[i]-'0';
			//printf("Jest to lb i wynosiii: %d\n",num);
			n1 += num - 1;
			a = realloc(a, n1 * sizeof(char));
			a[n1 - 1] = temp;
			//printf("a[%d]: %c\n",n1-1, a[n1-1]);
			for(j = 0; j < num -1; j++)
				a[n1 - j] = temp;
				//printf("Iterka na j a[%d]: %c",n1 -j,a[n1 - j]);
		}else{
			n1++;
			a[n1] = input[i];
			//printf("To nie lb a[%d]: %c \n",n1,a[n1]);
		}
		temp = input[i];
	}

	return a;
}
