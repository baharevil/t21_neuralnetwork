#ifndef NEURALNETWORK
#define NEURALNETWORK

/*!
    @def Определение нейрона
    @todo Проработать хранение и ассоциативность весов
    @version 1
*/

typedef struct neuron {
    neuron **prev;
    neuron **next;
    float input;
    float output;
    float (*initiator)(float *, float *);
} neuron;

#endif