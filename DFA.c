//Program:-Checks L(m) , for DFA
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main(void){
	char state,F[10],d[10][10],ip[10];
	int sl,ipl,n,i,j,temp;
	int il,jl;
	int status=0;

	clrscr();

	printf("Enter The no: Of States: ");
	scanf("%d",&sl);
	for(temp = 1 ;temp <=sl ; temp++){/*loop to get States*/
		scanf(" %c",&d[temp][0]);
	}

	printf("Enter The no: Of Inputs: ");
	scanf("%d",&ipl);
	for(temp = 1 ;temp <=ipl ; temp++){
		scanf(" %c",&d[0][temp]);
	}

	printf("Enter The Starting States: ");
	scanf(" %c",&state);

	printf("Enter The Set Of Final States: ");
	scanf("%s",&F);

	for( i=1 ; i <= sl ; i++ ){
		for(j=1 ; j <= ipl ; j++ ){
			  printf("State %c on Input %c: ",d[i][0],d[0][j]);
			  scanf(" %c",&d[i][j]);
		}
	}
	printf("\nq:%c\nF:%s\n",state,F);

	printf("Enter The Input String: ");
	scanf("%s",&ip);
	printf("Input %s",ip);

	while( ip[n] != '\0' ){

		for( i=1 ; i <= sl ; i++ ){
			if( state == d[i][0]){//presence of state
				il = i;
			}
		}
		for(j=1 ; j <= ipl ; j++ ){
			if( ip[n] == d[0][j] ){//precence of input
				jl = j;
			}
		}
		if( state != '*' ){
			state = d[il][jl];
		}else{
			break;
		}
		n++;
	}
	for(temp =0; temp<=strlen(F);temp++){
		if(F[temp] == state ){
			status = 1;
			break;
		}else{
			status = 0;
		}
	}
	(status)?printf(" is accepted"):printf(" is not accepted");
	getch();
}
/*
Enter The no: Of States: 3
State 1: abc
State 2: State 3: Enter The no: Of Inputs: 2
Input 1: 01
Input 2: Set Of Starting States: a
Set Of Final States: c
State a on Input 0: *
State a on Input 1: b
State b on Input 0: *
State b on Input 1: c
State c on Input 0: *
State c on Input 1: *

q:a
F:c
	      0       1
a       *       b
b       *       c
c       *       *
Enter The Input String: 11
Input 11 is accepted
*/
