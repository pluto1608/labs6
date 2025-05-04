#include <iostream>
#include <cstring>
using namespace std;
//koj i da ja spushtil samo zadacata vo grupata od 5 vo cetvrtok vo 322A nemoj taka smeni bar ime na file
//ne bidete glupi ako mi go najdat githubot mozhe da blokiraat github
//samo ovoj komentar e vo ovie da ne barate drugi :)
class recenica{
    private:
    char *rec=nullptr;
    int brNaEl;
    public:
    recenica(const char *recc=nullptr){
        if(recc!=nullptr){
            brNaEl=strlen(recc);
            rec = new char[brNaEl+1];
            strcpy(rec,recc);
        }
    }
    char* getRec(){return rec;}
    void setRec(const char *recc=nullptr){
        if(recc!=nullptr){
            delete[] rec;
            brNaEl=strlen(recc);
            rec=new char[brNaEl+1];
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
    korisnik(){r.setRec("Zdravo!");}
    korisnik(const char *rec=nullptr){r.setRec(rec);}
    korisnik(korisnik &r1){r.setRec(r1.r.getRec());}
    void dodadi(const char *bukv,bool lok){
        char *novRec=new char[strlen(bukv)+strlen(r.getRec())+1];
        if(lok==0){
            strcpy(novRec,bukv);
            strcat(novRec,r.getRec());
        }else if(lok==1){
            strcpy(novRec,r.getRec());
            strcat(novRec,bukv);
        }
        r.setRec(novRec);
    }
    void brishiZnak(int n){
        char *pom;
        strcpy(pom,r.getRec());
        for(int i=n;i<r.getBrNaEl();i++)pom[i]=pom[i+1];
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