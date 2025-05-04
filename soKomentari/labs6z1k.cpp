#include <iostream>
#include <cstring>
using namespace std;

class recenica{
    private:
    char *rec=nullptr;//mora da e nullptr tuka zasho vo setRec se brihse a ako nema zadadena vrednost chrasnuva
    int brNaEl;
    public:
    recenica(const char *recc=nullptr){
        if(recc!=nullptr){
            brNaEl=strlen(recc);//strlen vraka dolzina na char niza ama ne go broi '\0'
            rec = new char[brNaEl+1];//zasho strlen ne go broi '\0' se dodava 1 za da ima prostor za nego
            strcpy(rec,recc);
        }
    }
    char* getRec(){return rec;}
    void setRec(const char *recc=nullptr){
        if(recc!=nullptr){
            delete[] rec;//se brishe prethodniot rec zasho se site mesta iskoriseni
            brNaEl=strlen(recc);
            rec=new char[brNaEl+1];//se dodeluva mesto za novata rec
            strcpy(rec,recc);
        }
    }
    int getBrNaEl(){return brNaEl;}
    ~recenica(){delete[] rec;}
};

class korisnik{
    private:
    recenica r;
    public:
    korisnik(){r.setRec("Zdravo!");}//default konstruktor, koga nema da dademe nikava vrednost
    //se povikuva ovoj
    korisnik(const char *rec=nullptr){r.setRec(rec);}//normalen konstructor
    korisnik(korisnik &r1){r.setRec(r1.r.getRec());}//copy construktor
    void dodadi(const char *bukv,bool lok){
        char *novRec=new char[strlen(bukv)+strlen(r.getRec())+1];//pomosna promenliva, se sobiraat dolzinita da
        //postoeckata rec i toa sto treba da se dodade pak +1 za \0
        if(lok==0){
            strcpy(novRec,bukv);//prvo toa shto se dodava
            strcat(novRec,r.getRec());//pa posteckoto, strcat dodava na kraj na niza
        }else if(lok==1){//obratno od prethodnoto
            strcpy(novRec,r.getRec());
            strcat(novRec,bukv);
        }
        r.setRec(novRec);//se vnesuva novata recenica
    }
    void brishiZnak(int n){
        char *pom;
        strcpy(pom,r.getRec());
        for(int i=n;i<r.getBrNaEl();i++)pom[i]=pom[i+1];//se pocnuva od dadeniot indeks i sekoj clen se stava da 
        //e naredniot odnosno pocnuvajki od dadeniot indeks se pomestuva nizata na levo
        r.setRec(pom);
    }
    void pechati(){cout<<r.getRec()<<endl;}
    ~korisnik(){}
};

int main(){
    char c[]="Mnogu sakam da ucham PSP!";
    korisnik k(c);
    k.pechati();
    k.dodadi(" za copy konstruktor.",1);
    k.brishiZnak(24);
    k.pechati();
}