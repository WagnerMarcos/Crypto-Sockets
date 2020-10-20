# Ejercicio 1

    Alumno: Wagner Marcos
    Padrón: 98607
    github: https://github.com/WagnerMarcos/Crypto-Sockets


## Introducción:
En este ejercicio se deberán desarrollar dos programas: uno emisor (o cliente), y otro receptor (o servidor) de
un mensaje cifrado.
El programa emisor deberá leer mensajes por entrada estándar y enviarlos cifrados, mientras que el receptor
deberá descifrarlos y mostrarlos por salida estándar.

La idea de este ejercicio es practicar el uso de TDAs, sockets, strings, entre otros temas de C.


## Estructura utilizada:
Como solución a este problema, se ejecuta un programa para el cliente y otro para el servidor. Tanto el servidor como el cliente conocen lo que es encriptar, procesamiento de texto, y envío de datos por sockets. 

El cliente al ser ejecutado buscará conectarse a un servidor y luego invocará a la función indicada por el parseo de argumentos. Dentro del transmisor se realiza un ciclo que consiste en la lectura de texto, su encriptación y su posterior envío hasta que ya no quede más texto por leer. 

El servidor luego de preparar la conexión por sockets y verificar que se eligió un método correcto invoca a la función en el receptor que procesará con el método indicado lo enviado por el cliente. Al recibir texto encriptado por socket, lo desencriptará y luego se lo mostrará al usuario.

La lógica que se utilizó es que el transmisor debe tener la capacidad de recibir un mensaje y enviarlo encriptado, y el que el receptor debe poder recibir un mensaje encriptado y mostrarlo de una manera legible al usuario.

Todo el trabajo se realizó sin hacer uso de memoria dinámica.