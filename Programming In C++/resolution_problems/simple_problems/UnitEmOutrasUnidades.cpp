#include <cstdio>

int main(){
	int cmunit,unit;
	printf("Uma unidade em metros");
	scanf("%d",&unit);
	printf("%d m = ",unit);
	cmunit= unit*100;
	printf("%d cm",cmunit);
}