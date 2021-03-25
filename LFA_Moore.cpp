#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int nr_stari, tranz, st_init, nr_fin, nr_cuv, output[100];
vector<int> stariFinale, outputuri, traseu;
char mat[100][101], cuv[100];

int efectuare_pas (int S, char a){
    for (int i = 0; i < nr_stari; i ++){
        if (mat[S][i] == a){
            return i;
        }
    }
    return -1;
}

int main(){

    fin >> nr_stari >> tranz;

    for (int i = 0; i < nr_stari; i++){
        int a;
        fin >> a;
        outputuri.push_back(a);
    }

    for (int i = 0; i < tranz; i++){
        int x, y;
        char temp;
        fin >> x >> y;
        fin >> temp;
        mat[x][y] = temp;
    }

    fin >> st_init >> nr_fin;

    for (int i = 0; i < nr_fin; i++){
        int a;
        fin >> a;
        stariFinale.push_back(a);
    }

    fin >> nr_cuv;

    for (int i = 0; i < nr_cuv; i++){
        fin >> cuv;
        traseu.clear();

        int S = st_init;
        traseu.push_back(S);
        int contor = 1;

        for (int j = 0; j < strlen(cuv); j ++){

            output[j] = outputuri[S];
            S = efectuare_pas(S, cuv[j]);

            if (S == -1){
                cout << "NU\n";
                contor = 0;
                break;
            } else traseu.push_back(S);
        }
        output[strlen(cuv)] = outputuri[S];

        if (contor == 1){
            for (unsigned int j = 0; j < stariFinale.size(); j++){
                if (stariFinale[j] == S){

                    contor = 2;

                    cout << "DA\n";
                    for (int k = 0; k <= strlen(cuv); k ++){
                        cout << output[k];
                    }
                    cout << "\nTraseu: ";
                    for (unsigned int k = 0; k < traseu.size(); k ++){
                        cout << traseu[k] << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
        }

        if (contor == 1){
            cout << "NU\n";
        }
    }
    return 0;
}