import random
import os
import copy
import csv

#ParaLimpiarLaConsola
limpiar = lambda: os.system('cls' if os.name in ('nt', 'dos') else 'clear')

#Botones
inicio=["(a)","(A)","a","aa","aaa","A","AA","AAA"]
salir=["(b)","(B)","b","bb","bbb","B","BB","BBB"]
final=["(c)","(C)","c","cc","ccc","C","CC","CCC"]

#Preguntas
def archivo_conceptos_lectura():
    matriz_datos=[]
    folder_lectura = "C:\\Users\\HP\\Documents\\TEC PROFESIONAL\\Andre\\Periodo 2 Semestre 1\\Programación\\Proyecto Integrador 1\\conceptos_lectura_nuevo.csv"
    with open(folder_lectura,"r") as file:
        csvreader = csv.reader(file)
        for row in csvreader:
            matriz_datos.append(row)
        return (matriz_datos)

def archivo_conceptos_mate():
    matriz_datos=[]
    folder_mate = "C:\\Users\\HP\\Documents\\TEC PROFESIONAL\\Andre\\Periodo 2 Semestre 1\\Programación\\Proyecto Integrador 1\\conceptos_mate_nuevo.csv"
    with open(folder_mate,"r") as file:
        csvreader = csv.reader(file)
        for row in csvreader:
            matriz_datos.append(row)
        return (matriz_datos)

def archivo_conceptos_ciencias():
    matriz_datos=[]
    folder_ciencias = "C:\\Users\\HP\\Documents\\TEC PROFESIONAL\\Andre\\Periodo 2 Semestre 1\\Programación\\Proyecto Integrador 1\\conceptos_ciencias_nuevo.csv"
    with open(folder_ciencias,"r") as file:
        csvreader = csv.reader(file)
        for row in csvreader:
            matriz_datos.append(row)
        return (matriz_datos)
        
#Pantalla de Inicio
def pantalla (a):
    if a in inicio:
        limpiar()
        print ("\nAntes de comenzar, ¿te gustaría leer las instrucciones del juego?\n\n      En caso de que sí, presiona 'A'.\n      Si quieres iniciar directamente sin leer las instrucciones, presiona 'B'.\n\n(Confirma tu decisión dándole ENTER)\n")
        b=str(input("Respuesta: "))
        while not (b in inicio or b in salir):
            b=str(input("Respuesta: "))
        limpiar()
        if b in inicio:
            rachita(a,b)
        elif b in salir:
            rachita(a,b)
    elif a in salir:
        limpiar()

#Racha
def rachita (a,b):
    racha=0
    if b in inicio:
        instrucciones(a,racha)
    else:
        tema(racha)

#Pantalla de Instrucciones
def instrucciones(a,racha):
    print("\nInstrucciones:\n\n      A continuación, te aparecerán tres temas a elegir para estudiar: Lectura, Matemáticas o Ciencias.\n      Dependiendo del que elijas, te aparecerá la definición de un concepto relacionado a este.\n      Por lo tanto, debes ingresar la palabra o concepto que corresponde a esa definición en minúsculas\n      (la ventana te dará el número de letras que tiene la palabra correcta).\n\n      Cada vez que introduzcas una palabra a manera de respuesta, te aparecerán las letras que tienen\n      en común tu respuesta con la palabra correcta, pero solamente si estas se encuentran en la misma posición.\n      En caso de que ninguna letra coincida o no se encuentre en la ubicación correspondiente, te aparecerá [*].\n\n      Además, si la palabra que ingresas tiene una mayor extensión que la palabra correcta, el programa\n      te seguirá pidiendo la respuesta.\n\n      Tienes tres intentos para ingresar la palabra correcta.\n      Si en esos intentos, adivinas la palabra correcta, sumarás 1 victoria a tu racha.\n      En caso de que no, aparecerá tu racha total y tendrás que volver a empezar.\n\n      ¡Tú puedes! ¡A iniciar el juego!\n\nPresiona 'A' para INICIAR.\n\n(Confirma tu decisión dándole ENTER)\n")
    b=str(input("Respuesta: "))
    while not (b in inicio or b in salir):
        b=str(input("Respuesta: "))
    limpiar()
    if b in inicio:
        tema(racha)
    elif b in salir:
        limpiar()

#Analizando listas
def tema(racha):
    limpiar()
    lectura=["(a)","(A)","a","aa","aaa","A","AA","AAA",1]
    mate=["(b)","(B)","b","bb","bbb","B","BB","BBB",2]
    ciencias=["(c)","(C)","c","cc","ccc","C","CC","CCC",3]
    print ("\nElige el tema que deseas estudiar ingresando la letra correspondiente : \n\n      (A)  Lectura\n      (B)  Matemáticas\n      (C)  Ciencias\n\n(Confirma tu decisión dándole ENTER)\n")
    a=str(input("Respuesta: "))
    while not (a in lectura or a in mate or a in ciencias):
        a=str(input("Respuesta: "))
    limpiar()
    if a in lectura:
        t=0
        preguntas(t,racha)
    elif a in mate:
        t=1
        preguntas(t,racha)
    elif a in ciencias:
        t=2
        preguntas(t,racha)

#Analisis de la lista elegida
def preguntas(t,racha):
    if t==0:
        pregunta=(random.choice(archivo_conceptos_lectura()))
        contador(pregunta,t,racha)
    elif t==1:
        pregunta=(random.choice(archivo_conceptos_mate()))
        contador(pregunta,t,racha)
    elif t==2:
        pregunta=(random.choice(archivo_conceptos_ciencias()))
        contador(pregunta,t,racha)

#Contador de intentos
def contador (pregunta,t,racha):
    contador=0
    juego(pregunta,t,racha,contador)

#Pantalla del juego
def juego (pregunta,t,racha,contador):
    definicion=(pregunta[1])
    palabra=(pregunta[0])
    while contador!=3:
        contador+=1
        print(f"\nIntento número: {contador}")
        print (f"\nDefinición: \n\n      ->  {definicion}\n\n      ->  (Número de letras: {len(palabra)})\n\n")
        r=(input("Respuesta: "))
        while (len(r))>(len(palabra)):
            r=(input("Respuesta: "))
        limpiar()
        r=list(r)
        respuesta=copy.copy(r)
        for i in r:
            for w in range (0,10):
                if i==(f"{w}"):
                    respuesta.remove(i)
            r=respuesta
        print (f"\nTu respuesta fue: {r}")
        conjunto=[]
        palabra=palabra.lower()
        palabra_oficial=list(palabra) 
        for i in range(len(r)):
            if palabra_oficial[i] == r[i]:
                conjunto.append(r[i])
            elif palabra_oficial[i] != r[i]:
                conjunto.append("*")
        if conjunto==palabra_oficial:
            resultado=1
            comparar(pregunta,conjunto,r,palabra,definicion,t,resultado,racha,contador)
            break
        elif conjunto!=palabra_oficial:
            resultado=0
            comparar(pregunta,conjunto,r,palabra,definicion,t,resultado,racha,contador)
            break

#Analisis del juego
def comparar (pregunta,conjunto,r,palabra,definicion,t,resultado,racha,contador):
    if resultado==1:
        racha+=1
        print (f"\n¡Felicidades! Aprendiste este concepto. En total llevas racha de: {racha} ¡Sigue así! \n\n\nPresiona 'A' para continuar.\n\n(Confirma tu decisión ENTER)\n")
        b=str(input("Respuesta: "))
        while not (b in inicio):
            b=str(input("Respuesta: "))
        if b in inicio:
            limpiar()
            print (f"\n¿Quieres seguir en el mismo tema?\n\n      Presiona 'A' para SÍ.\n      Presiona 'B' para NO.\n      Presiona 'C' para SALIR.\n\n(Confirma tu decisión ENTER)\n")
            b=str(input("Respuesta: "))
            while not (b in inicio or b in salir or b in final):
                b=str(input("Respuesta: "))
            if b in inicio:
                limpiar()
                preguntas(t,racha)
            elif b in salir:
                limpiar()
                tema(racha)
            elif b in final:
                limpiar()
                pantalla_final(racha)
    elif resultado==0:
        if contador==3:
            print (f"\nPERDISTE\n\nTu racha fue: {racha}\n\nPresiona 'A' para coninuar.\n\n(Confirma tu decisión ENTER)\n")
            b=str(input("Respuesta: "))
            while not (b in inicio):
                b=str(input("Respuesta: "))
            if b in inicio:
                limpiar()
                print ("\n¡Bienvenido a *LOOK*!\n\nUn juego en donde pondrás a prueba tus conocimientos sobre conceptos y definiciones.\n\nPresiona 'A' para INICIAR el juego.\nPresiona 'B' para SALIR del juego.\n\n(Confirma tu decisión dándole ENTER)\n")
                a=str(input("Respuesta: "))
                while not (a in inicio or a in salir):
                    a=str(input("Respuesta: "))
                limpiar()
                pantalla(a)
        elif contador !=3:
            print (f"\n{conjunto}\n\nDefinición: \n\n      ->  {definicion}\n\n      ->  (Número de letras: {len(palabra)})\n\nPresiona 'A' para continuar.\n\n(Confirma tu decisión ENTER)\n")
            b=str(input("Respuesta: "))
            while not (b in inicio):
                b=str(input("Respuesta: "))
            limpiar()
            juego (pregunta,t,racha,contador)
        
#Racha total
def pantalla_final (racha):
    limpiar()
    print (f"\nHaz terminado tu sesión de práctica. ¡Muy bien!\n\n      Tu racha final fue de: {racha}\n\n¡Gracias por usar *LOOK*!\n\n")

#Inicio de todo
limpiar()
print ("\n¡Bienvenido a *LOOK*!\n\nUn juego en donde pondrás a prueba tus conocimientos sobre conceptos y definiciones.\n\n      Presiona 'A' para INICIAR el juego.\n      Presiona 'B' para SALIR del juego.\n\n(Confirma tu decisión dándole ENTER)\n")
a=str(input("Respuesta: "))
while not (a in inicio or a in salir):
    a=str(input("Respuesta: "))
limpiar()
pantalla(a)

