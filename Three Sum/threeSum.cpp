/*
Feito por: Gustavo
*/

#include <iostream>
#include <time.h>
#include <vector>
#include <tuple>
#include <algorithm>

#define N 10

using namespace std;

int* gerarVetorAleatorio(int tam, int seed = time(NULL), int min = 0, int max = 100){
    int *vet = new int[tam];

    srand(seed);
    for(int i=0; i<tam; i++){
        vet[i] = (rand() % (max-min)) + min;
    }

    return vet;
}

vector<tuple<int,int,int>> threeSum(int *vet){
    sort(vet, vet+N);
    //ordenar
    vector<tuple<int,int,int>> res;
    for(int i=0; i<N-2; i++){
        while(vet[i] == vet[i-1]){
            i++;
        }
        int j = i+1, k = N-1;
        while(j < k){
            int sum = vet[i] + vet[j] + vet[k];
            if(sum == 0){
                res.push_back(tuple<int,int,int>(vet[i], vet[j], vet[k]));
                do{
                    j++;
                }while(vet[j] == vet[j-1] and j < k);
                do{
                    k--;
                }while(vet[k] == vet[k+1] and k > j);
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
        }
    }

    return res;
}

int main(int argc, char* argv[]){
    int *vet = gerarVetorAleatorio(N, 1, -10, 10);

    for(int i=0; i<N; i++)
        cout << vet[i] << " ";
    cout << endl;

    vector<tuple<int,int,int>> res = threeSum(vet);

    for(tuple<int,int,int> item : res){
        cout << get<0>(item) << " " << get<1>(item) << " " << get<2>(item) << endl;
    }
    cout << endl;

    delete [] vet;

    return 0;
}