#include <stdio.h>
#include <string.h>
#define max 1000

int encaixa(const char *s1, const char *s2){
	int i,tam1,tam2,verifica=0;
	tam1=strlen(s1);
	tam2=strlen(s2);
	
	if(tam2 > tam1)
		return 0;
	else{
		for(i=0;i<tam2;i++){
			if ( s1[tam1-tam2+i] != s2[i] )
				return 0;
		}
		return 1;
	}
}

int main(){
	char s1[max],s2[max],tam1,tam2;
	int n,i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s",s1,s2);
		if ( encaixa(s1,s2) )
			printf("encaixa\n");
		else
			printf("nao encaixa\n");
	}
}
