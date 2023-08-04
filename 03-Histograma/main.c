#include"include/Histograma.h" 
 
int main (void){
	
	int histograma[100] = {0};
    GenerarHistograma(stdin, histograma);
    //int posicion = histograma[4];
    //printf("%d",posicion);
    PrintHistograma(histograma);

    return 0;
}
