/*************/
/*  MARSANA  */
/*  CARMELO  */
/*  3D       */
/*************/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class codiceFiscale{
    public:
        char codiceFiscale[20];
        int counterCodice = 1;

        char name[20];
        char surname[20];
        char year[5];
        char day[3];
        char gender;
        int month;
        string location;

        void getName(){
            cout<<"Inserisci il nome: ";
            cin>>name;
        }
        void getSurname(){
            cout<<"Inserisci il cognome: ";
            cin>>surname;
        }
        void getYear(){
            cout<<"Inserisci il tuo anno di nascita: ";
            cin>>year;
        }
        void getMonth(){
            cout<<"Inserisci il tuo mese di nascita: ";
            cin>>month;
        }
        void getGender(){
            cout<<"Inserisci il tuo sesso di appartenenza(M/F): ";
            cin>>gender;
        }
        void getDay(){
            cout<<"Inserisci il tuo giorno di nascita(aa): ";
            cin>>day;
        }
        void getLocation(){
            cout<<"Inserisci il tuo comune di nascita: ";
            //scanf("%[^\n]s", location);
            cin>>location;
        }

        void setSurname(){
        /*Dobbiamo ricavare 3 lettere per il cognome. Bisogna prendere la prima, la seconda
        e la terza consonante. Però potrebbe anche succedere che ci siano solo due consonanti
        oppure una sola; in tal caso dopo aver preso le consonanti si inizia a prendere anche
        le vocali. Se ancora mancano altre lettere per completare la nostra stringa di tre
        caratteri si aggiunge la lettera X.
        I cognomi composti da più parole vanno considerati come se fossero una sola parola.*/
            int lenght;
            int cons = 1;
            lenght = strlen(surname);
            for(int i=0; i<lenght; i++){
                if(surname[i] != 'A' && surname[i] != 'E' && surname[i] != 'I' && surname[i] != 'O' && surname[i] != 'U'){
                    codiceFiscale[counterCodice] = surname[i];
                    counterCodice++;
                    cons++;
                }
                if(cons>3){
                    i = 20;
                }
            }
        }
    void setName(){
        /*Il procedimento che si utilizza per ricavare le tre lettere del nome, è uguale a quello
        del cognome con l'unica differenza che adesso dobbiamo prendere la prima, la terza e la
        quarta consonante. Nel caso non ci sono quattro consonanti, si prendono le prime tre e
        se ci sono meno di tre consonanti si effettua lo stesso procedimento del cognome.*/
        int lenght;
        int cons = 0;
        lenght = strlen(name);
        for(int i=0; i<lenght; i++){
            if(name[i] != 'A' && name[i] != 'E' && name[i] != 'I' && name[i] != 'O' && name[i] != 'U'){
                cons++;
            }
        }
        if(cons>4){
            int temp_counter = 0;
            for(int i=0; i<lenght; i++){
                if(name[i] != 'A' && name[i] != 'E' && name[i] != 'I' && name[i] != 'O' && name[i] != 'U'){
                    if(i!=1){
                        codiceFiscale[counterCodice] = name[i];
                        counterCodice++;
                        temp_counter++;
                    }
                    if(temp_counter > 2){
                        i = 100;
                    }
                }
            }
        }
        if(cons==4){
            int temp_counter = 0;
            for(int i=0; i<lenght; i++){
                if(name[i] != 'A' && name[i] != 'E' && name[i] != 'I' && name[i] != 'O' && name[i] != 'U'){
                    if(i!=2){
                        codiceFiscale[counterCodice] = name[i];
                        counterCodice++;
                        temp_counter++;
                    }
                    if(temp_counter > 2){
                        i = 100;
                    }
                }
            }
        }else if(cons == 3){
            for(int i=0; i<lenght; i++){
                if(name[i] != 'A' && name[i] != 'E' && name[i] != 'I' && name[i] != 'O' && name[i] != 'U'){
                        codiceFiscale[counterCodice] = name[i];
                        counterCodice++;
                }
            }
        }else if(cons == 2){
            int temp_cons = 0;
            for(int i=0; i<lenght; i++){
                if(name[i] != 'A' && name[i] != 'E' && name[i] != 'I' && name[i] != 'O' && name[i] != 'U'){
                        codiceFiscale[counterCodice] = name[i];
                        counterCodice++;
                        temp_cons++;
                }
                if(temp_cons >= 2){
                    codiceFiscale[counterCodice] = name[i+1];
                    counterCodice++;
                    i = 1000;
                }
            }
        }
    }
    void setYear(){
        //I due numeri dell'anno di nascita sono semplicemente le sue ultime due cifre.
        codiceFiscale[counterCodice] = year[2];
        counterCodice++;
        codiceFiscale[counterCodice] = year[3];
        counterCodice++;
    }
    void setMonth(){
        /*Per il mese di nascita non dobbiamo inserire il numero del mese, ma una lettera;
        questo perché i mesi sono 12 e lo spazio a disposizione è ristretto ad un carattere
        solo.*/
        switch(month){
            case 1:
                codiceFiscale[counterCodice] = 'A';
            break;

            case 2:
                codiceFiscale[counterCodice] = 'B';
            break;

            case 3:
                codiceFiscale[counterCodice] = 'C';
            break;

            case 4:
                codiceFiscale[counterCodice] = 'D';
            break;

            case 5:
                codiceFiscale[counterCodice] = 'E';
            break;

            case 6:
                codiceFiscale[counterCodice] = 'H';
            break;

            case 7:
                codiceFiscale[counterCodice] = 'L';
            break;

            case 8:
                codiceFiscale[counterCodice] = 'M';
            break;

            case 9:
                codiceFiscale[counterCodice] = 'P';
            break;

            case 10:
                codiceFiscale[counterCodice] = 'R';
            break;

            case 11:
                codiceFiscale[counterCodice] = 'S';
            break;

            case 12:
                codiceFiscale[counterCodice] = 'T';
            break;

            default:
                cout<<"ERRORE!";
        }
        counterCodice++;
    }

    void setDay(){
        /*Per definire il giorno di nascita ed il sesso di una persona abbiamo a disposizione 2 cifre.
        Nel caso si tratti di un uomo basta usare queste 2 cifre per indicarne semplicemente il giorno
        di nascita (con lo zero davanti se il giorno è di una sola cifra),
        mentre se si tratta di una donna dobbiamo inserire il giorno di nascita sommato a 40.*/
        if(gender == 'F') {
            int num = (day[0]-48);
            num+=4;
            num+=48;
            day[0] = num;
        }
            codiceFiscale[counterCodice] = day[0];
            counterCodice++;
            codiceFiscale[counterCodice] = day[1];
            counterCodice++;
    }

    void setCatastale(){
        /*Il luogo di nascita può essere uno degli 8100 comuni d'Italia oppure un
        paese straniero. Il metodo per calcolare il codice corrispondente, è simile
        a quello per il mese di nascita, perché ad ogni comune italiano o stato estero
        corrisponde un determinato codice formato da 1 carattere alfabetico e 3
        caratteri numerici, questi codici vengono redatti dalla Direzione generale del Catasto.*/
        ifstream in;
        in.open("comuni.txt");
        bool found = false;
        char comune[100];
        int lenght;
        while(!found){
            in>>comune;
            lenght = strlen(comune);
            string temp;
            temp = strtok(comune, ",");
            if(temp == location){
                found = true;
            }
        }
        for(int i=0; i<lenght; i++){
            if(lenght - i <= 4){
                codiceFiscale[counterCodice] = comune[i];
                counterCodice++;
            }
        }
    }
    void setLastLetter(){
        /*Siamo quindi arrivati all'ultima fase che corrisponde
        al calcolo, tramite un ben determinato algoritmo, della
        lettera di controllo. L'algoritmo consiste nel convertire
        i vari caratteri in numeri secondo la tabella sottostante
        e poi eseguire varie operazioni seguendo questi passi:
    *Convertire in numeri i caratteri di posizione pari.
    *Convertire in numeri i caratteri di posizione dispari.
    *Addizionare tutti i valori ottenuti e dividerli per 26.
    *Determinare una lettera alfabetica corrispondente al resto dell'operazione*/
        int somma_pari = 0;
        int somma_dispari = 0;
        for(int i=1; i<=counterCodice; i++){
            //SWITCH PER POSIZIONI PARI
            if(i%2 == 0){
                switch(codiceFiscale[i]){
                    case 'A':
                        somma_pari += 0;
                    break;
                    case 'B':
                        somma_pari += 1;
                    break;
                    case 'C':
                        somma_pari += 2;
                    break;
                    case 'D':
                        somma_pari += 3;
                    break;
                    case 'E':
                        somma_pari += 4;
                    break;
                    case 'F':
                        somma_pari += 5;
                    break;
                    case 'G':
                        somma_pari += 6;
                    break;
                    case 'H':
                        somma_pari += 7;
                    break;
                    case 'I':
                        somma_pari += 8;
                    break;
                    case 'J':
                        somma_pari += 9;
                    break;
                    case 'K':
                        somma_pari += 10;
                    break;
                    case 'L':
                        somma_pari += 11;
                    break;
                    case 'M':
                        somma_pari += 12;
                    break;
                    case 'N':
                        somma_pari += 13;
                    break;
                    case 'O':
                        somma_pari += 14;
                    break;
                    case 'P':
                        somma_pari += 15;
                    break;
                    case 'Q':
                        somma_pari += 16;
                    break;
                    case 'R':
                        somma_pari += 17;
                    break;
                    case 'S':
                        somma_pari += 18;
                    break;
                    case 'T':
                        somma_pari += 19;
                    break;
                    case 'U':
                        somma_pari += 20;
                    break;
                    case 'V':
                        somma_pari += 21;
                    break;
                    case 'W':
                        somma_pari += 22;
                    break;
                    case 'X':
                        somma_pari += 23;
                    break;
                    case 'Y':
                        somma_pari += 24;
                    break;
                    case 'Z':
                        somma_pari += 25;
                    break;
                    case '0':
                        somma_pari += 0;
                    break;
                    case '1':
                        somma_pari += 1;
                    break;
                    case '2':
                        somma_pari += 2;
                    break;
                    case '3':
                        somma_pari += 3;
                    break;
                    case '4':
                        somma_pari += 4;
                    break;
                    case '5':
                        somma_pari += 5;
                    break;
                    case '6':
                        somma_pari += 6;
                    break;
                    case '7':
                        somma_pari += 7;
                    break;
                    case '8':
                        somma_pari += 8;
                    break;
                    case '9':
                        somma_pari += 9;
                    break;

                    default:
                        int s = 1;
                    break;
                }
            }
            if(i%2 != 0){
                //POSIZIONI DISPARI
                switch(codiceFiscale[i]){
                    case 'A':
                        somma_dispari += 1;
                    break;
                    case 'B':
                        somma_dispari += 0;
                    break;
                    case 'C':
                        somma_dispari += 5;
                    break;
                    case 'D':
                        somma_dispari += 7;
                    break;
                    case 'E':
                        somma_dispari += 9;
                    break;
                    case 'F':
                        somma_dispari += 13;
                    break;
                    case 'G':
                        somma_dispari += 15;
                    break;
                    case 'H':
                        somma_dispari += 17;
                    break;
                    case 'I':
                        somma_dispari += 19;
                    break;
                    case 'J':
                        somma_dispari += 21;
                    break;
                    case 'K':
                        somma_dispari += 2;
                    break;
                    case 'L':
                        somma_dispari += 4;
                    break;
                    case 'M':
                        somma_dispari += 18;
                    break;
                    case 'N':
                        somma_dispari += 20;
                    break;
                    case 'O':
                        somma_dispari += 11;
                    break;
                    case 'P':
                        somma_dispari += 3;
                    break;
                    case 'Q':
                        somma_dispari += 6;
                    break;
                    case 'R':
                        somma_dispari += 8;
                    break;
                    case 'S':
                        somma_dispari += 12;
                    break;
                    case 'T':
                        somma_dispari += 14;
                    break;
                    case 'U':
                        somma_dispari += 16;
                    break;
                    case 'V':
                        somma_dispari += 10;
                    break;
                    case 'W':
                        somma_dispari += 22;
                    break;
                    case 'X':
                        somma_dispari += 25;
                    break;
                    case 'Y':
                        somma_dispari += 24;
                    break;
                    case 'Z':
                        somma_dispari += 23;
                    break;
                    case '0':
                        somma_dispari += 1;
                    break;
                    case '1':
                        somma_dispari += 0;
                    break;
                    case '2':
                        somma_dispari += 5;
                    break;
                    case '3':
                        somma_dispari += 7;
                    break;
                    case '4':
                        somma_dispari += 9;
                    break;
                    case '5':
                        somma_dispari += 13;
                    break;
                    case '6':
                        somma_dispari += 15;
                    break;
                    case '7':
                        somma_dispari += 17;
                    break;
                    case '8':
                        somma_dispari += 19;
                    break;
                    case '9':
                        somma_dispari += 21;
                    break;

                    default:
                        int s = 1;
                    break;
                }
            }
        }
        int somma_totale = somma_dispari + somma_pari;
        int resto = somma_totale % 26;
        switch(resto){
            case 0:
                codiceFiscale[counterCodice] = 'A';
                counterCodice++;
            break;
            case 1:
                codiceFiscale[counterCodice] = 'B';
                counterCodice++;
            break;
            case 2:
                codiceFiscale[counterCodice] = 'C';
                counterCodice++;
            break;
            case 3:
                codiceFiscale[counterCodice] = 'D';
                counterCodice++;
            break;
            case 4:
                codiceFiscale[counterCodice] = 'E';
                counterCodice++;
            break;
            case 5:
                codiceFiscale[counterCodice] = 'F';
                counterCodice++;
            break;
            case 6:
                codiceFiscale[counterCodice] = 'G';
                counterCodice++;
            break;
            case 7:
                codiceFiscale[counterCodice] = 'H';
                counterCodice++;
            break;
            case 8:
                codiceFiscale[counterCodice] = 'I';
                counterCodice++;
            break;
            case 9:
                codiceFiscale[counterCodice] = 'J';
                counterCodice++;
            break;
            case 10:
                codiceFiscale[counterCodice] = 'K';
                counterCodice++;
            break;
            case 11:
                codiceFiscale[counterCodice] = 'L';
                counterCodice++;
            break;
            case 12:
                codiceFiscale[counterCodice] = 'M';
                counterCodice++;
            break;
            case 13:
                codiceFiscale[counterCodice] = 'N';
                counterCodice++;
            break;
            case 14:
                codiceFiscale[counterCodice] = 'O';
                counterCodice++;
            break;
            case 15:
                codiceFiscale[counterCodice] = 'P';
                counterCodice++;
            break;
            case 16:
                codiceFiscale[counterCodice] = 'Q';
                counterCodice++;
            break;
            case 17:
                codiceFiscale[counterCodice] = 'R';
                counterCodice++;
            break;
            case 18:
                codiceFiscale[counterCodice] = 'S';
                counterCodice++;
            break;
            case 19:
                codiceFiscale[counterCodice] = 'T';
                counterCodice++;
            break;
            case 20:
                codiceFiscale[counterCodice] = 'U';
                counterCodice++;
            break;
            case 21:
                codiceFiscale[counterCodice] = 'V';
                counterCodice++;
            break;
            case 22:
                codiceFiscale[counterCodice] = 'W';
                counterCodice++;
            break;
            case 23:
                codiceFiscale[counterCodice] = 'X';
                counterCodice++;
            break;
            case 24:
                codiceFiscale[counterCodice] = 'Y';
                counterCodice++;
            break;
            case 25:
                codiceFiscale[counterCodice] = 'Z';
                counterCodice++;
            break;

            default:
                cout<<"ERRORE!";
            break;
        }
    }
    void stampaCodice(){
        for(int i=1; i<counterCodice; i++){
            cout<<codiceFiscale[i];
        }
    }

};

int main(){
    codiceFiscale cf;
        cout<<"============================================"<<endl;
    cf.getSurname();
    cf.getName();
    cf.getYear();
    cf.getMonth();
    cf.getDay();
    cf.getGender();
    cf.getLocation();
        cout<<"============================================"<<endl;
    cf.setSurname();
    cf.setName();
    cf.setYear();
    cf.setMonth();
    cf.setDay();
    cf.setCatastale();
    cf.setLastLetter();
    //cf.codiceFiscale[16]='\0';
    cout<<endl;
    cout<<"------------------"<<endl;
    cout<<"|";
    cf.stampaCodice();
    cout<<"|"<<endl;
    cout<<"------------------"<<endl;
    return 0;
}
