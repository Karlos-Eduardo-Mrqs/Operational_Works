#include <cstdio>
#include <string>

using namespace std;

bool TrianguloAceito(int ang1, int ang2, int ang3){
	bool retorno;
	bool st1Ok=false;
	bool st2Ok=false;
	bool st3Ok=false;

	st1Ok=ang1 < ang2+ang3 ? true:false;
	st2Ok=ang2 < ang1+ang3 ? true:false;
	st3Ok=ang3 < ang1+ang2 ? true:false;
	
	if(st1Ok && st2Ok && st3Ok){
		retorno = true;
	}else {
		retorno = false;
	}
	return retorno;
}

int main(){
	int ang1=0,ang2=0,ang3=0;
	string tipoT;
	printf("\n Digite todos os tres angulos do triangulo:");
	printf("(");
		scanf("%d %d %d",&ang1, &ang2, &ang3);
	printf(")");
	if(TrianguloAceito(ang1,ang2,ang3)){
		if(ang1 == ang2 && ang2 == ang3){
			tipoT="Equilatero";
		}else if(ang1 == ang2 || ang2== ang3 || ang3==ang1){
			tipoT="Isosceles";	
		}else{
			tipoT="Escaleno";	
		}
	}else {
		tipoT="Invalido com esses angulos";
	}
	printf("O tipo desse triangulo e %s !",tipoT.c_str());
	return 0;
}