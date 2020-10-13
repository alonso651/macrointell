bool buffIn [11] = {0,0,0,0,0,0,0,0,0,0};
bool buffOut [22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Byte dato;

int p_buff [10];
int sum = 0;
bool ok;



// for (int i = 0; i < 10; ++i)
// {
// 	sum = sum + p_buff [i];
// }
// if (sum == 11) { dato = decodificador();}


Byte decodificador(){
	int j = 0;
	bool limpiar = false;
	int pos = 99;
	for (int i = 0; i < 10; ++i)
	{
		int tBit = p_buff [i];
		switch (tBit){
			case 0 : 
				if (j >= 11) {ok=true;}
				else {ok=false;}
				break;
			case 1 : 
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 2:
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 3:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;

			case 4:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 5:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 6:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 7:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 8:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 9:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;
			case 10:
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;			
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 1;
				j++;
				buffOut [j] = 0;
				j++;
				buffOut [j+1] = 2;
				break;

			default: break;				
		}
	}
	for (int i = 0; i < 11; ++i){
		buffIn[i] = buffOut[i];
	}
	for (int i = 11; i < 22; ++i){
		if (buffOut[i] == 2) {
			limpiar = true;
			pos = i;
		}
	}
	if (limpiar){
		int pos1 = pos;
		for (int i = pos; i < 22; ++i)
		{	

			buffOut[pos1-pos] = buffOut[i]; 
			pos1++;
		}
	}


	bool b[8] = {0,0,0,0,0,0,0,0};
	for (int i = 1; i < 9; ++i)	{	
			int ii = 8-i;
			b[ii] = buffOut[i];
	}
	int num = 0;
	for (int i = 0; i < 8; ++i)	{
		if (b[i]){
			int aux = pow(2.00, (float)i);
			num = num + aux;
		}
	}

	Byte salida = (Byte)num;
	return salida;
}

