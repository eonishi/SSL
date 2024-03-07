#include"include/Histograma.h" 
 
int main (void){
	
	int histograma[50] = {0};
    GenerarHistograma(stdin, histograma);
    int posicion = histograma[5];
    printf("%d",posicion);
    //PrintHistograma(histograma, '-');

    return 0;
}
