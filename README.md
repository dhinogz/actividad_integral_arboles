# Act 3.4 - Actividad Integral de Árboles 

El canal de Suez es un canal navegable que conecta el mar Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente. Se tiene un registro de los barcos que navegan por el canal con el siguiente formato.

<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>

Ejemplo:

3-jan-20 13:45 M 8PAK7

Donde el punto de entrada puede ser M – Mar Mediterráneo y R – Mar Rojo.

En equipos de tres personas, hacer una aplicación que:

Solicite los nombre del archivo de entrada de cada uno de los mares (generados en la actividad 2.3) (Ej. canalM.txt y canalR.txt) y los abra, y contabilice las incidencias de cada una de las series (los primeros tres caracteres de el UBI). y almace como data único la UBI + Cantidad (donde cantidad es la llave del BST) en dos árboles binarios de búsqueda, uno para los que entran por el Mar Mediterráneo y otro para los buques que entran por el mar Rojo.
Despliegue en pantalla lo datos almacenados en en cada uno de los árboles en forma descendente, esto es la serie del buque que mas acceso tuvo.
<serie-UBI> <cant>

Ejemplo:

Entradas Mar ROJO

D9A 120

TIA 98

...

Entradas Mar MEDITERRANEO

D9A 112

V2L 56

…

Realiza en forma individual una investigación y reflexión de la importancia y eficiencia del uso de los árboles binarios de búsqueda (BST en una situación problema de esta naturaleza,  generando un documento llamado "ReflexAct3.4.pdf ".
