#include <iostream>
#include <cstring>
using namespace std;

class korisnik{
    private:
    char ime[20];
    float tezina[30];
    int brNaMer;
    public:
    korisnik(){//default konstruktor
        ime[0]='\0';
        tezina[0]=60;
        brNaMer=1;
    }
    korisnik(korisnik &k){//copy
        strcpy(ime,k.ime);
        for(int i=0;i<k.brNaMer;i++){
            tezina[i]=k.tezina[i];
        }
        brNaMer=k.brNaMer;
    }
    
    korisnik(const char *imee=nullptr,float *tezinaa=nullptr,int brNaMerr=0):brNaMer(brNaMerr){//normalen
        strcpy(ime,imee);
        for(int i=0;i<brNaMer;i++)tezina[i]=tezinaa[i];
    }

    void dodadiMer(float n){
        if(brNaMer<30){
            for(int i=brNaMer-1;i>=0;i--)tezina[i+1]=tezina[i];//se pomestuvaat site clenovi na desno
            tezina[0]=n;//prviot se stava da e vnesenata vrednost
            brNaMer++;
        }
    }
    void brishiMer(){
        for(int i=0;i<brNaMer;i++)tezina[i]=tezina[i+1];//nizata se pomestuva na levo
        brNaMer--;
    }

    void pechati(){
        cout<<ime<<endl;
        cout<<brNaMer<<endl;
        for(int i=0;i<brNaMer;i++)cout<<tezina[i]<<' ';
        cout<<endl;
    }
};

int main(){
    float t[]={1,2,3,4};
    korisnik k("ime",t,4);
    k.pechati();
    k.dodadiMer(75.3);
    k.pechati();
    k.brishiMer();
    k.pechati();
}