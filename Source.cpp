#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


/*En esta funcion hacemos dividir dos valores en registro de pila en asm con fdivp y mantener unico valor st(1)*/
float dividir(float a, float b){
	float c;
	float d = a;
	float e = b;
	_asm{
		fld d
		fld e
		fdivp st(1), st
		fstp c
	}
	return c;
}
/*En esta funcion hacemos sumar dos valores en registro de pila en asm con faddp y mantener unico valor st(1)*/
float suma(float a, float b){
	float a1 = a;
	float b1 = b;
	float c;

	_asm{
		fld a1
		fld b1
		faddp st(1), st
		fstp c

	}
	return c;
}
/*En esta funcion hacemos multiplicar dos valores en registro de pila en asm con fmulp y mantener unico valor st(1)*/
float multiplicar(float a, float b){
	float numero3;
	float numero1 = a;
	float numero2 = b;
	_asm{
		fld numero1
		fld numero2
		fmulp st(1), st
		fstp numero3
	}
	return numero3;
}
/*En esta funcion hacemos restar dos valores en registro de pila en asm con fsubp y mantener unico valor st(1)*/
float resta(float a, float b){
	float resultado = 0;
	float valor1 = a;
	float valor2 = b;

	_asm{
		fld valor1
		fld valor2
		fsubp st(1), st
		fstp resultado
	}

	return resultado;
}

/*Calcula la densidad*/
float CalcularDensidad(float pres, float temp){
	if (temp == 0){ temp = 1; }
	float res;
	res = dividir(pres, temp);
	return res;
}
/*Calcula la Velocidad*/
float calcularVelocidad(float combu, float motor){
	float velo;
	velo = suma(combu, motor);
	return velo;
}

/*calcula el angulo de las alas tomando el area de la presion de abajo del avion y su velocidad maxima*/
float CalcularAngulo(float press, float max){
	float resultado;
	float a = 20;
	float valor1, valor2;
	valor1 = dividir(press, max);
	valor2 = suma(valor1, a);
	resultado = valor2;
	return resultado;
}
/*Calcula la inclinacion de nariz con la presion maxima de abajo*/
float CalculaNariz(float presion, float maxima){
	float total;
	float a1 = 6;/*tomamos el tiempo en que se esta despegando el avion*/
	float valor1;
	float valor2;
	float valor3;

	valor1 = dividir(presion, maxima);
	valor2 = multiplicar(valor1, a1);
	valor3 = suma(valor2, a1);
	total = valor3;
	return total;
}

/*Calcula los angulos de las alas manteniendolos estables en gravedad cero*/
float CalcularAnguloEnGravedad(float preArri, float VeloMaxi){
	float valortotal = 0;
	float estable = 0;
	float minima = 2;/*el angulo estable es el promedio del 50% cuando se encuentra en gravedad cero*/
	float valor1 = preArri;
	float valor2 = VeloMaxi;
	valortotal = resta(valor1, valor2);
	estable = dividir(valortotal, minima);
	return estable;
}
/*Calcula el angulo de la nariz atra vez de la presion de arriba y abajo*/
float MantenerEstable(float arriba, float abajo){
	float resultado = 0;
	float a = arriba;
	float b = abajo;
	float tiempo = 7;
	resultado = dividir(a, b);
	float contrapeso = multiplicar(tiempo, multiplicar(resultado, tiempo));
	return contrapeso;
}

/*Calcula la turbolencia a travez de la velocidad y tiempo en que tarda en salir del estado de las fuerzas del viento*/
float CalcularTurbolencia(float veloviento, float velocidad){
	float mul = 0;
	float a = veloviento;
	float b = velocidad;
	float a1 = 20.00;
	mul = multiplicar(a, b);
	/*float resultado = dividir(mul,a1);*/
	return mul;
}

/*Calcular la velocidad del avion en la que va en la gravedad*/
float calcularvelocidadAvion(float velocidad){
	float velo = 0;
	float a = velocidad;
	velo = rand() % 7 + 1;
	float resultado = multiplicar(a, velo);
	return resultado;
}
/*calcula la disminucion del combustible con la velocidad*/
float calcularvelocidadAvion1(float velocidad){
	float velo = velocidad;
	velo = rand() % 3 + 1;
	return velo;
}
/*Calcula la presion en gravedad cero*/
float calcularPresion(float presArri, float presAba){
	float resultado = 0;
	float a1 = 2;
	float a = presArri, b = presAba;
	resultado = suma(a, b);
	float resultado2 = dividir(resultado, a1);
	return resultado2;
}
/*Calcula la potencia de los motores*/
float CalcularMotores(float velomax, float combu){
	float resultado = 0;
	float a = velomax;
	float b = combu;
	resultado = resta(a, b);
	float obtener = dividir(resultado, b);
	return obtener;
}
/*calcula la fuerza del motor atravez de la potencia y velocidad*/
float CalcularFuerzaMotor(float poten, float velo){
	float resultado = 0;
	float a = poten, b = velo;
	resultado = multiplicar(a, b);
	b = rand() % 9 + 1;
	float obtener = dividir(resultado, b);
	return obtener;
}

int main(){
	float FuerzaMotor = 0, presion, tiempTotal, velocidadV, altitud, Densidad, velocidad_despegue, temperatura, potenMotor, IncliDer, IncliIzq, TiVuelo, Combustible, VeloViento, PresArri,
		PresAba, TieDespegue, SimuGravedad, TieAterrizaje, VeloMaxima, AltitudMaxima, IncliNariz, Incli_AlaDer, Incli_AlaIzq, velocidad;
	int tiempo1 = 7;
	velocidadV = 0;
	velocidad = 0;
	presion = 0;
	Densidad = 0;
	AltitudMaxima = 15000;/*mil pies*/
	velocidad_despegue = 0;
	Combustible = 155.40;
	potenMotor = 115.67;
	VeloViento = 5;
	temperatura = 18;
	VeloMaxima = 910;
	altitud = 0;
	Incli_AlaDer = 0;
	Incli_AlaIzq = 0;
	IncliIzq = 0;
	IncliDer = 0;
	IncliNariz = 0;
	TieDespegue = 0;
	TieAterrizaje = 0;
	TiVuelo = 0;
	PresAba = 1011;
	PresArri = 1008;
	float turbolencia = 0;
	float autom = 7.2; /*Es el tiempo que tomara el piloto automatico para simular procesos y elementos mecanicos del avion*/
	float CarreraDespegue = 620;
	float apro = 200;
	float apro1 = 2;
	float caidaAl = 40;
	srand(time(NULL));
	velocidad = (rand() % 500) + 501;
	printf(" PREPARANDO DESPEGUE (BOING 747)\n\n");
	printf("VELOCIDAD DEL DESPEGUE A ALCANZAR: %.2f\n\n", velocidad);
	printf("TEMPERATURA: %.2f\n\n", temperatura);
	printf("POTENCIA DE MOTOR: %.2f\n\n", potenMotor);
	printf("INCLINACION DERECHA: %.2f\n\n", IncliDer);
	printf("INCLINACION IZQUIERDA: %.2f\n\n", IncliIzq);
	printf("PRESION ARRIBA: %.2f\n\n", PresArri);
	printf("PRESION ABAJO: %.2f\n\n", PresAba);
	printf("COMBUSTIBLE: %.2f\n\n", Combustible);
	printf("ANGULO DE INCLINACION DEL ALA DERECHA: %.2f\n\n", Incli_AlaDer);
	printf("ANGULO DE INCLINACION DEL ALA IZQUIERDA: %.2f\n\n", Incli_AlaIzq);
	printf("ANGULO DE INCLINACION DE NARIZ: %.2f\n\n", IncliNariz);
	presion = suma(PresAba, PresArri);/*sumamos la presion de arriba y la de abajo para tener la total de la zona al despegar*/
	system("pause");
	system("cls");
	while (tiempo1 >= 0){
		printf(" DESPEGANDO BOING 747\n\n");
		printf("ALTITUD: %.2f\n\n", altitud);
		altitud += 1850.20;
		printf("TEMPERATURA: %.2f\n\n", temperatura);
		temperatura = temperatura - 1.67;
		printf("DENSIDAD: %.2f\n\n", Densidad);
		Densidad = CalcularDensidad(PresArri, temperatura);
		printf("VELOCIDAD DEL DESPEGUE: %.2f\n\n", velocidad_despegue);
		if (velocidad_despegue<velocidad){ velocidad_despegue = velocidad_despegue + calcularVelocidad(Combustible, potenMotor); }
		printf("TIEMPO DEL DESPEGUE: %.2f\n\n", TieDespegue);
		TieDespegue += 2.1612;
		printf("COMBUSTIBLE: %.2f\n\n", Combustible);
		Combustible -= 4.12;
		printf("ANGULO DE INCLINACION DEL ALA DERECHA: %.2f\n\n", Incli_AlaDer);
		if (Incli_AlaDer < 60 && Incli_AlaDer < 70){ Incli_AlaDer += CalcularAngulo(PresAba, VeloMaxima); }
		printf("ANGULO DE INCLINACION DEL ALA IZQUIERDA: %.2f\n\n", Incli_AlaIzq);
		if (Incli_AlaIzq < 60 && Incli_AlaIzq < 70){ Incli_AlaIzq += CalcularAngulo(PresAba, VeloMaxima); }
		printf("INCLINACION DE NARIZ: %.2f\n\n", IncliNariz);
		if (IncliNariz < 55){ IncliNariz += CalculaNariz(presion, VeloMaxima); }
		--tiempo1;
		Sleep(2400);
		system("cls");
	}
	printf("ACERCANDOSE A GRAVEDAD CERO...\n");
	Sleep(1800);
	float flota = 5;/*flota es la medida del ala pequeña que mide las velocidades y los giros y densidad del avion*/
	float tqm = -1;
	float promedio = 50.23;
	boolean entrar = true;
	float aut = 7.2;
	while (autom >= 0){
		printf("PILOTO AUTOMATICO PROBANDO EN %.2f", aut);
		printf(" SEGUNDOS TIEMPO: %.2f\n\n", autom);
		printf("ANGULO DE INCLINACION DERECHA: %.2f\n\n", IncliDer);
		IncliDer = (resta(autom, CalcularAnguloEnGravedad(PresAba, VeloMaxima)))*(-1);
		printf("ANGULO DE INCLINACION IZQUIERDA: %.2f\n\n", IncliIzq);
		IncliIzq = (resta(autom, CalcularAnguloEnGravedad(PresAba, VeloMaxima)))*(-1);
		printf("ANGULO DE INCLINACION NARIZ: %.2f\n\n", IncliNariz);
		if (IncliNariz >= 48){ IncliNariz = MantenerEstable(PresArri, PresAba); }
		IncliNariz -= 0.91;
		printf("VELOCIDAD: %.2f\n\n", velocidad);
		velocidad += dividir(promedio, calcularvelocidadAvion(velocidad_despegue));
		printf("NIVEL DE TURBULENCIA ESTABLE: %.2f\n\n", turbolencia);
		if (entrar == true && turbolencia <= 500){ turbolencia = CalcularTurbolencia(VeloViento, velocidad); }
		if (turbolencia > 1000 || turbolencia > 500){ turbolencia = dividir(turbolencia, promedio); }/*debe mantenerse debajo de 100 el nivel sino el avion no podra soportarlo*/
		printf("COMBUSTILE: %.2f\n\n", Combustible);
		Combustible = resta(Combustible, calcularvelocidadAvion1(velocidad));
		printf("TEMPERATURA: %2.f\n\n", temperatura);
		if (temperatura < 7 && entrar == true){ temperatura = resta(temperatura, flota); }
		else{ printf("SE MANTIENE ESTABLE\n\n"); }
		printf("DENSIDAD EN GRAVEDAD CERO: %.2f\n\n", Densidad);
		Densidad = resta(multiplicar(PresArri, CalcularDensidad(PresArri, temperatura)), PresArri) / 20 * (-1);
		if (Densidad <= 30000 || entrar == true){ printf("SE MANTIENE ESTABLE ALREDEDOR DE LAS FUERZAS DEL VIENTO\n\n"); }
		else{ printf("DEBE DISMINUIR\n\n"); }
		printf("PRESION EN GRAVEDAD CERO: %.2f\n\n", presion);
		presion += calcularPresion(PresArri, PresAba) / 20;
		printf("VELOCIDAD DEL VIENTO BAJO PRESION: %.2f\n\n", VeloViento);
		VeloViento = calcularVelocidad(calcularPresion(velocidadV, presion), velocidad);
		if (entrar == false){ printf("NO SE ENCUENTRA CHOQUE DE EMPUJE.\n"); }
		if (VeloViento > 2600){ printf("SE ENCUENTRAN CHOQUES DE EMPUJE DEBE DISMINUIR.\n"); }
		printf("POTENCIA DE MOTORES: %.2f\n\n", potenMotor);
		potenMotor += CalcularMotores(VeloMaxima, Combustible);
		printf("ALTITUD MAXIMA: %.2f\n\n", altitud);
		if (altitud<AltitudMaxima){ altitud += 1821.20; }
		printf("FUERZA DE MOTOR: %.2f\n\n", FuerzaMotor);
		FuerzaMotor += dividir(dividir(CalcularFuerzaMotor(potenMotor, velocidad), promedio), apro);
		if (autom < 1 && entrar == true){
			system("cls");
			printf("SUPERADOS LOS 7 SEGUNDOS DEL PILOTO AUTOMATICO.\n");
			printf("SIMULANDO AHORA PARA LOS 12 SEGUNDOS EL PILOTO AUTOMATICO.\n");
			autom = 12.2;
			entrar = false;
			aut = 12.2;
		}
		autom = autom - 1.2;
		Sleep(2400);
		system("cls");
	}
	system("cls");
	if (entrar == false){
		printf("12 SEGUNDOS COMPLETADOS, PREPARANDO ATERRIZAJE...\n");
		printf("PILOTO AUTOMATICO SUPERADO EN GRAVEDAD CERO PARA LOS 7 Y 12 SEGUNDOS\n");
	}
	Sleep(1800);
	int aterr = 9;
	float aterr1 = 0.8;
	float aterr2 = 5.35;
	while (aterr > 0){
		printf("ATERRIZANDO.\n\n");
		printf("ANGULO DE INCLINACION DERECHA: %.2f\n\n", IncliDer);
		IncliDer = dividir((suma(aterr, CalcularAnguloEnGravedad(PresAba, VeloMaxima))),apro1);
		printf("ANGULO DE INCLINACION IZQUIERDA: %.2f\n\n", IncliIzq);
		IncliIzq = dividir((suma(aterr, CalcularAnguloEnGravedad(PresAba, VeloMaxima))), apro1);
		printf("ANGULO DE INCLINACION NARIZ DE ATAQUE: %.2f\n\n", IncliNariz);
		IncliNariz = dividir((suma(aterr, CalcularAnguloEnGravedad(PresAba, VeloMaxima))), apro1);
		IncliNariz -= 0.91;
		printf("VELOCIDAD: %.2f\n\n", velocidad);
		velocidad = velocidad - suma(multiplicar(dividir(PresAba, PresArri), potenMotor),caidaAl);/*784,36*/
		printf("COMBUSTILE: %.2f\n\n", Combustible);
		Combustible = resta(Combustible, calcularvelocidadAvion1(velocidad));
		printf("TEMPERATURA: %2.f\n\n", temperatura);
		if(temperatura < 20)temperatura += 17;
		printf("DENSIDAD DE ATAQUE: %.2f\n\n", Densidad);
		Densidad = dividir(Densidad,flota);
		printf("PRESION: %.2f\n\n", presion);
		presion = resta(presion,apro);
		printf("VELOCIDAD DEL VIENTO BAJO PRESION: %.2f\n\n", VeloViento);
		VeloViento = calcularVelocidad(calcularPresion(velocidadV, aterr), velocidad);
		printf("POTENCIA DE MOTORES: %.2f\n\n", potenMotor);
		potenMotor = CalcularMotores(VeloMaxima, Combustible)/aterr;
		printf("ALTITUD DISMINUYENDO: %.2f\n\n", altitud);
		altitud = altitud / 2;
		--aterr;
		Sleep(3000);
		system("cls");
	}

	system("pause");
	return 0;
}