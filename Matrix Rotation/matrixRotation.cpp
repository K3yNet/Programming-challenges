#include <iostream>

#define N 10

using namespace std;

int** criarMatriz(){
    int** mtz = new int*[N];
    for(int i=0; i<N; i++){
        mtz[i] = new int[N];
        for(int j=0; j<N; j++){
            mtz[i][j] = N*i + j + 1;
        }
    }
    return mtz;
}

int main(){
    int** mtz = criarMatriz();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << mtz[i][j] << "\t";
        cout << endl;
    }
    cout << "--------------------------------------" << endl;

    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            swap(mtz[i][j], mtz[j][i]);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N/2; j++)
            swap(mtz[i][j], mtz[i][N-j-1]);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << mtz[i][j] << "\t";
        cout << endl;
    }

    for(int i=0; i<N; i++)
        delete [] mtz[i];
    delete [] mtz;

    return 0;
}