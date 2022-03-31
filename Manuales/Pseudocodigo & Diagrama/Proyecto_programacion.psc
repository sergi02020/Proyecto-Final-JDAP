Algoritmo Proyecto_programacion
	Definir m,n,p,m1,n1,m2,n2 Como Entero
	Definir s,cord,step Como Caracter
	Definir c Como Entero
	Leer m,n
	Leer c
	Leer m1,n1
	Leer m2,n2
	Leer cord
	Leer p
	Leer step
	Para i<-1 Hasta p Hacer
		Si step='D' Entonces
			Si cord='N' Entonces
				cord <- 'E'
			SiNo
				cord <- 'S'
				cord <- 'O'
			FinSi
			Si cord='E' Entonces
				cord <- 'S'
			SiNo
				cord <- 'o'
				cord <- 'N'
			FinSi
		SiNo
			step <- 'I'
			Si cord='N' Entonces
				cord <- 'O'
			SiNo
				cord <- 'S'
				cord <- 'E'
			FinSi
			Si cord='E' Entonces
				cord <- 'N'
			SiNo
				cord <- 'O'
				cord <- 'S'
			FinSi
		FinSi
		Si step='A' Entonces
			Si cord='N' Entonces
				Si c<>0 Entonces
					s <- 'E'
					Escribir s
				SiNo
					m1 <- m1-1
				FinSi
			FinSi
			Si cord='S' Entonces
				Si c<>0 Entonces
					s <- 'E'
					Escribir s
				SiNo
					m1 <- m1+1
				FinSi
				Si cord='E' Entonces
					Si c<>0 Entonces
						s <- 'E'
						Escribir s
					SiNo
						n1 <- n1+1
					FinSi
				FinSi
				Si cord='O' Entonces
					Si c<>0 Entonces
						s <- 'E'
						Escribir s
					SiNo
						n1 <- n1-1
					FinSi
				FinSi
			FinSi
		FinSi
	FinPara
	Si m1=m2 Y n1=n2 Entonces
		s <- 'C'
		Escribir s
	FinSi
FinAlgoritmo
