#include <iostream>
#include <cstring>
using namespace std;

class recenica{
    private:
    char *rec=nullptr;
    int brNaEl;
    public:
    recenica(){setRec("Zdravo!");}
    recenica(recenica &r1){
        strcpy(r1.rec,rec);
        brNaEl=r1.brNaEl;
    }
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
    void dodadi(const char *bukv,bool lok){
        char *novRec=new char[strlen(bukv)+strlen(rec)+1];
        if(lok==0){
            strcpy(novRec,bukv);
            strcat(novRec,rec);
        }else if(lok==1){
            strcpy(novRec,rec);
            strcat(novRec,bukv);
        }
        setRec(novRec);
    }
    void brishiZnak(int n){
        char *pom;
        strcpy(pom,rec);
        for(int i=n;i<brNaEl;i++)pom[i]=pom[i+1];
        setRec(pom);
    }
    int getBrNaEl(){return brNaEl;}
    void pechati(){cout<<rec<<endl;}
    ~recenica(){delete[] rec;}
};

int main(){
    char c[]="Mnogu sakam da ucham PSP!";
    recenica k(c);
    k.pechati();
    k.dodadi(" za copy konstruktor.",1);
    k.brishiZnak(24);
    k.pechati();

}