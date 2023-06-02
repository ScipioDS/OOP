#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//место за вашиот код
class NegativnaVrednost{
public:
    void msg(){
        cout << "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!" << endl;
    }
};

class Oglas{
private:
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
public:
    Oglas(){}
    Oglas(char * ot_naslov, char * ot_kat, char * ot_opis, float ot_cena){
        strcpy(this->naslov,ot_naslov);
        strcpy(this->kategorija,ot_kat);
        strcpy(this->opis,ot_opis);
        this->cena = ot_cena;
    }
    Oglas(const Oglas& ot){
        strcpy(this->naslov,ot.naslov);
        strcpy(this->kategorija,ot.kategorija);
        strcpy(this->opis,ot.opis);
        this->cena = ot.cena;
    }
    ~Oglas(){}
    friend ostream& operator<<(ostream &out,const Oglas &ot){
        out << ot.naslov << "\n"
            << ot.opis << "\n"
            << ot.cena << " evra" << "\n" << "\n";
        return out;
    }
    friend bool operator>(const Oglas& o1,const Oglas& o2){
        return (o1.cena > o2.cena);
    }
    float get_cena()const{
        return cena;
    }
    char * get_name(){
        return naslov;
    }
    char * get_opis(){
        return opis;
    }
    char * get_kat(){
        return kategorija;
    }
};

class Oglasnik{
private:
    char ime[20];
    Oglas * oglasi;
    int br_oglasi;
public:
    Oglasnik(){
        this->oglasi = new Oglas[0];
    }
    Oglasnik(char * ime){
        strcpy(this->ime,ime);
        this->oglasi = new Oglas[0];
        this->br_oglasi = 0;
    }
    ~Oglasnik(){
        delete [] oglasi;
    }
    friend ostream& operator<<(ostream& out, const Oglasnik &ogl){
        out << ogl.ime << "\n";
        for (int i = 0; i < ogl.br_oglasi; ++i) {
            out << ogl.oglasi[i];
        }
        return out;
    }
    Oglasnik& operator+=(const Oglas& oglas){
        if(oglas.get_cena()<0) throw NegativnaVrednost();
        Oglas * temp = new Oglas[br_oglasi+1];
        for (int i = 0; i < br_oglasi; ++i) {
            temp[i] = oglasi[i];
        }
        temp[br_oglasi++] = oglas;
        delete [] this->oglasi;
        oglasi = temp;
        return * this;
    }
    void oglasiOdKategorija(char *k){
        for (int i = 0; i < br_oglasi; ++i) {
            if(strcmp(oglasi[i].get_kat(),k)==0){
                cout << oglasi[i];
            }
        }
    }
    void najniskaCena(){
        float price = 1000000;
        int ii;
        for (int i = 0; i < br_oglasi; ++i) {
            if(oglasi[i].get_cena()<price){
               ii = i;
               price = oglasi[i].get_cena();
            }
        }
        cout << oglasi[ii];
    }
};

int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
    	cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch(NegativnaVrednost ne){
                ne.msg();
            }
        }
        cout<<ogl;
    }
    else if (tip==4){
      	cout<<"-----Test oglasOdKategorija -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch(NegativnaVrednost ne){
                ne.msg();
            }
        }
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
    	cout<<"-----Test Exception -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch(NegativnaVrednost ne){
                ne.msg();
            }
        }
        cout<<ogl;

    }
    else if (tip==6){
    	cout<<"-----Test najniskaCena -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch(NegativnaVrednost ne){
                ne.msg();
            }
        }
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }
    else if (tip==7){
    	cout<<"-----Test All -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch(NegativnaVrednost ne){
                ne.msg();
            }
        }
        cout<<ogl;

        cin.get();
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }

	return 0;
}
