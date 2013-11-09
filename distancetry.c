//Cc, Cr, Cd, Ci][Ct, Ck
//retorna a matriz de custo e a matriz de operação

		int *T;
		char *op;
   T = (int*) malloc (m*sizeof(int));
   for (i=0;i<m;i++){
				T[i] = (int*) malloc (n*sizeof(int));
		}
		op = (char*) malloc (m*sizeof(char));
   for (i=0;i<m;i++){
				op[i] = (char*) malloc (n*sizeof(char));
		}
		
EDIT-DISTANCE(x, y, m, n){
	//coloca custo de delete em todas as colunas 0
	for(i=0;i<m;i++){
			T[i][0] = i * Cd;//Custo delete
			op[i][0] = "d";
	}
	//coloca custo de insert em todas as linhas 0
	for(j=0;j<n;j++){
			T[0][j] = j * Ci;//Custo insert
			op[0][j] = "i";
	}
			//percorre a matriz de custo 
	for(i=1;i<m;i++){
			for (j=1;j<n;j++){
					T[i][j] = 444;//como colocar um peso maior que os custos????
					if (x[i] == y[j]){//se as letras forem iguais copia
							T[i][j] = T[i-1][j-1] + Cc;//Custo copy
							op[i][j] = 'c';
					}		
					//se o custo de troca for menor
					if ((x[i] != y[j]) && ((T[i-1][j-1] + Cr) < T[i][j])){//Custo replace
							T[i][j] = T[i-1][j-1] + Cr;//Custo replace
							op[i][j] = 'r';//REPLACE(by y[j]);
					}				
					//	
					if (( i >= 2) && (j >= 2) && (x[i] == y[j-1]) && 
					(x[i-1] == y[j]) && ((T[i-2][j-2] + Ct) < T[i][j])){//Custo twiddle
							T[i][j] = T[i-2][j-2] + Ct;//Custo twiddle
							op[i][j] = 't';
					}
					//				
					if ((T[i-1][j] + cost(delete)) < T[i][j]){
							T[i][j] = T[i-1][j] + Cd//Custo delete
							op[i][j] = 'd';
					}
					if (T[i][j-1] + Ci < T[i][j]){
							T[i][j] = T[i][j-1] + Ci//Custo insert
							op[i][j] = 'i';//INSERT(y[j]);
					}
			}
	}		
	for(i=0;i<m-1;i++){
			if (T[i][n] + Ck < T[m][n]){
					T[m][n] = T[i][n] + Ck;//Custo
					op[m][n] = 'k';//KILL(i);
			}
	}
	return;// T and op;
}



//imprime a operação que está sendo realizada
OP-SEQUENCE(op, i, j){
if (i == 0 && j == 0) 		return;
if ((op[i][j] == "c") || (op[i][j] == "r")){
		aux_i = i − 1;
		aux_j = j − 1;
}else if (op[i][j] == "t"){
		aux_i = i − 2;
		aux_j = j − 2;
}else if ()op[i][j] == "d"){
		aux_i = i − 1;
		aux_j = j;
}elseif (op[i][j] == "i"){
		aux_i = i;
		aux_j = j − 1;
}else{
		op[i][j] == "k";
		aux_i = m;
		aux_j = j;
}
	OP-SEQUENCE(op, aux_i , aux_j);
	if ((op[i][j] == "c") printf("%d %d Copy %c", i, j, vetory[j]);
	if ((op[i][j] == "r") printf("%d %d Replace %c", i, j, vetory[j]);
	if ((op[i][j] == "t") printf("%d %d Twiddle %c%c", i, j, vetory[j-1],vetory[j]);
	if ((op[i][j] == "d") printf("%d %d Delete _", i, j);
	if ((op[i][j] == "i") printf("%d %d Insert %c", i, j, vetory[j]);
	if ((op[i][j] == "k") printf("%d %d Kill *", i, j);
}


//acha a resposta certa percorrendo a matrix de custo
//T[i][j] = min 
//---- acho que essa parte ele só explica o que é T[i,j] não é codigo---
int Minim(T,i,j,m,n){
del = T[i − 1][j] + Cd;//Custo delete
ins = T[i][j − 1] + Ci;//custo insert

	if (x[i]==y[j]){
			cop = T[i − 1][j − 1] + Cc;//Custo copy
	}
	if (x[i] != y[j]){
			rep = T[i − 1][j − 1] + Cr;//Custo replace
		}
	if ((i>=2) && (j >= 2) && (x[i] == y[j−1]) && (x[i−1] == y[j])){
			twid = T[i − 2][j − 2] + Ct; //Custo twiddle
	}
	if ((i == m) && (j == n)){
			aux = T[0][n];	
			for (k=1;k<m;k++){
					if ( T[k][n]<aux){
							aux = T[k][n];			
						}
			}
			kil = T[k][n] + cost(kill(m-k))//Custo kill
	}
	//retorna o menor custo NAO SEI FAZER MELHOR
	if ((del<ins)&&(del<cop)&&(del<rep)&&(del<twid)&&(del<kil)) return del;
	if ((ins<del)&&(ins<cop)&&(ins<rep)&&(ins<twid)&&(ins<kil)) return ins;
	if ((cop<ins)&&(cop<del)&&(cop<rep)&&(cop<twid)&&(cop<kil)) return cop;
	if ((rep<ins)&&(rep<cop)&&(rep<del)&&(rep<twid)&&(rep<kil)) return rep;
  if ((twid<ins)&&(twid<cop)&&(twid<rep)&&(twid<del)&&(twid<kil)) return twid;	
	if ((kil<ins)&&(kil<cop)&&(kil<rep)&&(kil<twid)&&(kil<del)) return kil;
}
}
---------------------------------------------------------*/
