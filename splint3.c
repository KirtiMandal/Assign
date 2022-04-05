#include<stdio.h>

const char *into_string(int value){
	const char *ret;
	switch(value){
	case 1:
		ret = "one";
		break;
		
	case 2:
		ret ="two";
		//;
		
	case 3:
		ret="three";
		break;
		
	default:
		ret="Less than 1 or more than 3";
		break;
	}
	
	return ret;
}

int main(){

	printf("into_string(2)=%s\n",(char*)into_string(2));
	return 0;

}



//splint will show fall through case, no preceding case[fall through means no preceding case.]
//while gcc will complie it with no error
