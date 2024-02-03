#include "t21_neuralnetwork.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

float f(float *x){
    return *x;
}

int main() {
    uint8_t layers_num = 3, neurons_total = 0;
    uint8_t *layers = malloc(sizeof(uint8_t) * layers_num);
    memset(layers, 0, sizeof(uint8_t) * layers_num);

    //! @todo Тут должна загружаться некая карта. Нужен стек/дек.
    neurons_total += *(layers + 0) = 3;
    neurons_total += *(layers + 1) = 3;
    neurons_total += *(layers + 2) = 1;

    // Выделяем не одним куском (может быть много), а "мультисосиской".
    neuron **neural_network = malloc(sizeof(neuron*) * layers_num);
    memset(neural_network, 0, sizeof(neuron*) * layers_num);

    // Инициализация массива указателей на слои
    for(uint8_t i = 0; i < layers_num; i++) {
        *(neural_network + i) = malloc(sizeof(neuron*) * *(layers + i));
    }

    // Инициализация массива синапсов.
    synapse *synapse_network = malloc(sizeof(synapse*) * layers_num * neurons_total);
    memset(synapse_network, 0, sizeof(synapse*) * layers_num * neurons_total);

    // Установка указателей (добавить расстановку синапсов)
    for(uint8_t i = 0; i < layers_num; i++) {
        for (uint8_t j = 0; j < *(layers + i); j++) {
            (*(neural_network + i) + *(layers + j))->initiator = f;
        }
    }

    //! @todo: Заполнение входного слоя

    // Освобождение массива указателей на слои
    for(uint8_t i = 0; i < layers_num; i++) {
        free(*(neural_network + i));
    }

    free(synapse_network);
    free(neural_network);
    free(layers);

    return 0; 
}