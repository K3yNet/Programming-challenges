#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int* gerarVetorAleatorio(int tam, int seed = time(NULL), int min = 0, int max = 100){
    int *vet = new int[tam];

    srand(seed);
    for(int i=0; i<tam; i++){
        vet[i] = ((rand() % max) + min) % max;
    }

    return vet;
}

pair<int, int> twoSum1(int vet[], int tam, int soma){
    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(vet[i] + vet[j] == soma)
                return pair<int, int>(i, j);
        }
    }

    return pair<int,int>(-1, -1);
}



pair<int, int> twoSum2(int vet[], int tam, int soma){
    sort(vet, vet+tam);

    int i = 0, j = tam-1;
    while(i < j){
        int somaAux = vet[i] + vet[j];
        if(somaAux == soma)
            return pair<int, int>(i, j);
        else if(somaAux < soma)
            i++;
        else
            j--;
    }

    return pair<int, int>(-1, -1);
}

pair<int, int> twoSum3(int vet[], int tam, int soma){
    map<int, int> mapa;
    for(int i=0; i<tam; i++){
        int value = vet[i];
        int diff = soma - value;
        if(mapa.count(value)){
            return pair<int, int>(mapa[value], i);
        }
        else{
            mapa[diff] = i;
        }
    }

    return pair<int, int>(-1, -1);
}

int main(int argc, char* argv[]){
    int tam = 10, soma = 9;
    if(argc == 3){
        try{
            tam = stoi(argv[1]);
            soma = stoi(argv[2]);
        }
        catch(exception &err){
            cout << "Digite valores inteiros" << endl;
        }
    }

    int *vet = gerarVetorAleatorio(tam, 1, 0, 15);

    for(int i=0; i<tam; i++)
        cout << vet[i] << " ";
    cout << endl;

    pair<int, int> res = twoSum2(vet, tam, soma);

    if(res.first != -1)
        cout << vet[res.first] << " + " << vet[res.second] << " = " << soma << endl;
    else
        cout << "Soma nao encontrada" << endl;
    
    return 0;
}