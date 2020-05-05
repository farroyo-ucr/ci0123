#include <pthread.h>
#include <iostream>

int x = 0;
void * sumaUno( void * hilo ) {
   x++;
   return 0;
}


class MyThread {
public:
    MyThread() {
       this->thread = (pthread_t *) calloc( 1, sizeof( pthread_t ) );
    }

    ~MyThread() {
       free( this->thread );
    }

    void Fork() {
        pthread_create( this->thread, 0, helper, this);
    }

    void join()
    {
        pthread_join( * this->thread, 0);
    }

private:
    static void* helper( void* arg )
    {
        MyThread* mt = reinterpret_cast<MyThread*>(arg);
        mt->doSomething();
        pthread_exit( 0 );
        return 0;
    }

    void virtual doSomething() = 0;

    pthread_t * thread;
    pthread_attr_t * attr;

};

class OtroThread : public MyThread {
   void doSomething() {
      int n = 10;
      sumaUno( (void *) & n );
      std::cout << "X es " << x << std::endl;

   }

};


int main() {
    OtroThread mt, m2;
    mt.Fork(); m2.Fork();
    mt.join(); m2.join();
}

