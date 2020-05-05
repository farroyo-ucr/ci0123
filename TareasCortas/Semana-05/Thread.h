/*  Esta clase encapsula las funciones para la utilizacion de PThreads
 *  Se provee las estructuras para crear los trabajadores (hilos)
 *
 *  Autor: Programacion Paralela y Concurrente (Francisco Arroyo)
 *  Fecha: 2020/Abr/23
 */

#ifndef _THREAD_H
#define _THREAD_H

#include <pthread.h>

class Thread {
public:
   Thread();
   ~Thread();
   int Fork( void *(*startRoutine) (void *), void * );
   void * Join();
   void Exit( void * );
   

private:

// Class variables
   pthread_t * thread;
   pthread_attr_t * attr;

};

#endif

