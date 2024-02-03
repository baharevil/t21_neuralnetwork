#ifndef NEURALNETWORK
#define NEURALNETWORK


/*!
    @brief Определение синапса.
    @def Синапс имеет направление относительно нейрона, адрес нейрона на который он смотрит и вес.
    @todo Проработать хранение и ассоциативность весов
    @version 1.1
*/
typedef struct synapse {
    enum direction {
        prev;
        next;
    }
    neuron *neuron;
    float weight;
} synapse;

/*!
    @brief Определение нейрона
    @def У одного нейрона может быть несколько синапсов, смотрящих на другие нейроны.
    @todo Проработать хранение и ассоциативность весов
    @version 1.1
*/
typedef struct neuron {
    synapse **synapses;
    float input;
    float output;
    float (*initiator)(float *);
} neuron;

#endif