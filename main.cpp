#include <iostream>
#include <ctime>
using namespace std;

// Prototipi funzioni
void menu_principale();
void carica_vettore_man(int v[], int n);
void carica_vettore_cas(int v[], int n);
void visualizza_vettore(int v[], int n);
void min_max(int v[], int n);
void scambio_centro(int v[], int n);
void shift_sinistra(int v[], int n);
void somma_indici(int v[], int n);
void sposta_seguenti(int pos, int v[], int n);
void ordina1(int v[], int n);
void ordina2(int v[], int n);
void ordina3(int v[], int n);
void fusione(int v[], int n);
int elimina_elemento(int v[], int n);
void frequenza_elementi(int v[], int n);
int posizione_maggiore(int v[], int limite_sup, int limite_inf);
int posizione_minore(int v[], int limite_sup, int limite_inf);


int main(){
    int num_elementi1;               // numero elementi del vettore
    cout << endl << endl;
    cout << "\tInserisci il numero di elementi del vettore: ";
    cin >> num_elementi1;
    int vett1[num_elementi1];        // dichiarazione del vettore
    char scelta;
    int posizione;
    srand(time(NULL));

    do{
        system("CLS");
        menu_principale();
        cout << "\tCosa vuoi eseguire? ";
        cin >> scelta;
        cout << endl;

        // flusso di elaborazione
        switch (scelta){
            case 'a':{
                carica_vettore_man(vett1, num_elementi1);
                cout << "\tIl vettore e\' stato caricato" << endl << endl;
                break;
            }
            case 'b':{
                carica_vettore_cas(vett1, num_elementi1);
                cout << "\tIl vettore e\' stato caricato" << endl << endl;
                break;
            }
            case 'c':{
                visualizza_vettore(vett1, num_elementi1);
                cout << endl << endl;
                break;
            }
            case 'd':{
                min_max(vett1, num_elementi1);
                cout << endl << endl;
                break;
            }
            case 'e':{
                scambio_centro(vett1, num_elementi1);
                cout << "\tGli elementi sono stati scambiati";
                cout << endl << endl;
                break;
            }
            case 'f':{
                shift_sinistra(vett1, num_elementi1);
                cout << "\tGli elementi sono stati spostati";
                cout << endl << endl;
                break;
            }
            case 'g':{
                somma_indici(vett1, num_elementi1);
                cout << "\tGli elementi sono stati sommati";
                cout << endl << endl;
                break;
            }
            case 'h':{
                cout << "\tInserisci la posizione da cui vuoi spostare gli elementi: ";
                cin >> posizione;
                sposta_seguenti(posizione, vett1, num_elementi1);
                cout << "\tGli elementi sono stati spostati";
                cout << endl << endl;
                break;
            }
            case 'i':{
                ordina1(vett1, num_elementi1);
                cout << "\tGli elementi sono stati ordinati";
                cout << endl << endl;
                break;
            }
            case 'l':{
                ordina2(vett1, num_elementi1);
                cout << "\tGli elementi sono stati ordinati";
                cout << endl << endl;
                break;
            }
            case 'm':{
                ordina3(vett1, num_elementi1);
                cout << "\tGli elementi sono stati ordinati";
                cout << endl << endl;
                break;
            }
            case 'n':{
                fusione(vett1, num_elementi1);
                cout << "\tI vettori sono stati fusi in uno solo";
                cout << endl << endl;
                break;
            }
            case 'o':{
                num_elementi1 = elimina_elemento(vett1, num_elementi1);
                cout << "\tL'elemento è stato eliminato ed il vettore \"ridimensionato\"";
                cout << endl << endl;
                break;
            }
            case 'p':{
                frequenza_elementi(vett1, num_elementi1);
                cout << endl << endl;
                break;
            }
            case 'z':{
                cout << "\tBuona giornata";
                cout << endl << endl;
                break;
            }
        }
        cout << "\t" << system("PAUSE");
    }while ((scelta != 'z') && (scelta != 'Z'));
    return 0;
}
void menu_principale(){
    cout << "\ta ................. Caricamento manuale di un vettore di n elementi" << endl << endl;
    cout << "\tb ................. Caricamento casuale di un vettore di n elementi" << endl << endl;
    cout << "\tc ................. Visualizza vettore di n elementi" << endl << endl;
    cout << "\td ................. Trova valore minimo e valore massimo" << endl << endl;
    cout << "\te ................. Scambio elementi rispetto al centro" << endl << endl;
    cout << "\tf ................. Shift sinistra di una posizione" << endl << endl;
    cout << "\tg ................. Somma indici" << endl << endl;
    cout << "\th ................. Sposta i seguenti data la posizione" << endl << endl;
    cout << "\ti ................. Ordina vettore versione 1 - GT sort" << endl << endl;
    cout << "\tl ................. Ordina vettore versione 2 - Bouble sort" << endl << endl;
    cout << "\tm ................. Ordina vettore versione 3 - GH sort" << endl << endl;
    cout << "\tn ................. Fusione di due vettori" << endl << endl;
    cout << "\to ................. Elimina elemento" << endl << endl;
    cout << "\tp ................. Frequenza di ogni elemento di un vettore" << endl << endl;
    cout << "\tz ................. Esci dal programma" << endl << endl;
}

// inserimento manuale degli elementi del vettore
void carica_vettore_man(int v[], int n){
    int i = 0;			            // indice vettore
    int num_elemento = 1;		    // contatore elementi, solo per stampa
    do{
        cout << "\tInserisci elemento " << num_elemento << ": ";
        cin >> v[i];
        num_elemento++;
        i++;
    }while (i <= n - 1);
}

// carica vettore con interi casuali
void carica_vettore_cas(int v[], int n){
    int i = 0;
    while (i <= n - 1){
        v[i] = (rand() % 100) + 1;
        i++;
    }
}

// stampa vettore
void visualizza_vettore(int v[], int n){
    int i = 0;
    while (i <= n - 1){
        cout << " " << v[i] << "  ";
        i++;
    }
}

// visualizza min e max
void min_max(int v[], int n){
    int i = 1, min = v[0], max = v[0];
    while (i <= n - 1){
        if (v[i] < min)
            min = v[i];
        else
            if (v[i] > max)
                max = v[i];
        i++;
    }
    cout << endl;
    cout << endl << "\tIl valore minimo e\': " << min << endl;
    cout << endl << "\tIl valore massimo e\': " << max << endl;
}

// ribalta il vettore
void scambio_centro(int v[], int n){
    int i = 0, temp = 0;
    while (i <= n/2){
        temp = v[i];
        v[i] = v[n-1];
        v[n-1] = temp;
        i++;
        n--;
    }
}

// shift a sinistra di tutto il vettore
void shift_sinistra(int v[], int n){
    int i = 0, temp = 0;
    temp = v[i];
    while (i < n-1){
        v[i] = v[i+1];
        i++;
    }
    v[i] = temp;
}

// somma gli elementi
void somma_indici(int v[], int n){
    int i = 1;
    while (i < n-1){
        v[i] = v[i] + v[i+1];
        i++;
    }
}

// shift a sinistra da posizione
void sposta_seguenti(int pos, int v[], int n){
    int temp = v[pos];
    while (pos < n-1){
        v[pos] = v[pos+1];
        pos++;
    }
    v[pos] = temp;
}

// Sele_Scambio-sort, variante non ufficiale di Selection-sort
void ordina1(int v[], int n){
    int temp, j = 0, i = j+1;
    while (j < n-1){
        while (i <= n-1){
            if (v[i] < v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
            i++;
        }
        j = j + 1;
        i = j + 1;
    }
}

// Bubble-sort
void ordina2(int v[], int n){
    int i = 0, j = n-1, temp;
    while (j > 0){
        while (i <= j-1){
            if (v[i] > v[i+1]){
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
            i++;
        }
        i = 0;
        j = j -1;
    }
}

// posizione del maggiore
int posizione_maggiore(int v[], int limite_sup, int limite_inf){
    int pos_max = limite_inf;
    for(int i = limite_inf; i < limite_sup - 1; i++)
        if(v[i] > v[i+1]) pos_max = i;
    return pos_max;
}

// posizione del maggiore
int posizione_minore(int v[], int limite_sup, int limite_inf){
    int pos_min = limite_inf;
    for(int i = limite_inf; i < limite_sup - 1; i++)
        if(v[i]<v[i+1]) pos_min = i;
    return pos_min;
}

// GH-Sort
void ordina3(int v[], int n){
    int f = 0, j = n-1, i = f+1, temp;
    while (f <= n/2){
        while (i <= j){
            if (v[i] < v[f]){
                temp = v[i];
                v[i] = v[f];
                v[f] = temp;
            }else{
                if (v[i] > v[j]){
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
            i++;
        }
        f++;
        j--;
        i = f+1;
    }
}

// fusione di due vettori
void fusione(int v[], int n){
    int m, p;                     	// Dimensioni dei vettori 2 e 3
    int i = 0, j = 0, z = 0;      	// Indici dei tre vettori
    char risp;

    // gestione sottomenu
    cout << "\tIndica la dimensione del secondo vettore: ";
    cin >> m;
    cout << endl;
    p = m+n;
    int vett2[m];                 	// Secondo vettore dimensione m
    int vett_fus[p];               	// Vettore Fusione dimensione m+n

    cout << "\tCome vuoi caricare il secondo vettore?" << endl << endl;
    cout << "\ta ...................... Manualmente" << endl << endl;
    cout << "\tb ...................... Casualmente" << endl << endl;
    cout << "\tRisposta: ";
    cin >> risp;
    cout << endl;
    if ( risp == 'a') carica_vettore_man(vett2, m);		// carica vettore 2 manuale
    if ( risp == 'b') carica_vettore_cas(vett2, m);		// carica vettore 2 casuale

    ordina2(v, n);				            // ordina il vettore 1
    ordina2(vett2, m);			            // ordina il vettore 2

    cout << "\tVettore 1: ";        	    // Visualizza vettore 1
    visualizza_vettore(v, n);
    cout << endl;

    cout << "\tVettore 2: ";        	    // Visualizza vettore 2
    visualizza_vettore(vett2, m);
    cout << endl;

    while ((i <= n-1) && (j <= m-1)){		// eseguo la fusione
        if (v[i] < vett2[j]){
            vett_fus[z] = v[i];
            i++;
        }else{
            vett_fus[z] = vett2[j];
            j++;
        }
        z++;
    }
    while (i <= n-1){			            // completo primo vettore
        vett_fus[z] = v[i];
        z++;
        i++;
    }
    while (j <= m-1){			            // completo secondo vettore
        vett_fus[z] = vett2[j];
        z++;
        j++;
    }

    cout << "\tVettore risultante: ";
    visualizza_vettore(vett_fus, p);
    cout << endl;
}

// elimina elemento in input
int elimina_elemento(int v[], int n){
    int ele, i = 0;
    cout << "\tQuale elemento vuoi eliminare? ";
    cin >> ele;
    while (i < n && v[i] != ele) i++;
    while (i <= n-1){		// shift a sinistra
        v[i] = v[i+1];
        i++;
    }
    n--;
    return n;
}

// conta occorrenze di tutti gòi elementi
void frequenza_elementi(int v[], int n){
    int i = 0;		                // indice del vettore
    int cont = 1;
    ordina2(v, n);		            // ordino il vettore
    cout << "\tValore" << "\tOccorrenze" << endl;

    while (i < n-1){
        while (v[i+1] == v[i]){		// conto le occorrenze
            cont++;
            i++;
        }

        // stampa valore e occorrenze
        cout << "\t" << v[i] << "\t" << cont << "\t";

        // stampa stelline
        for(int i = 1; i <= cont; i++) cout << "* ";
        cout << endl;
        i++;
        cont = 1;
    }
    cout << "\t" << v[i] << "\t" << cont << "\t" << "*" << endl;
}
