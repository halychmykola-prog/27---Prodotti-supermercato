#include <iostream>
#include <string>
using namespace std;

struct prodotto
{
	string nome;
	float prezzo;
	string categoria;
	
};


void aggiunta(prodotto v[], int &fillcounter, prodotto n)
{
        v[fillcounter]=n;
        fillcounter++;
}

string visualizzazione(prodotto v[], int dim)
{
    string output;
	for(int i=0;i<dim;i++){
		output+=v[i].nome+"\t";
		output+=v[i].categoria+"\t";
		output+=to_string(v[i].prezzo)+"\n";
	}
	return output;
}


void modifica(prodotto v[], prodotto n, int g)
{
    v[g]=n;
}

//deve essere inserito il nome del prodotto e poi deve essere cambiata info edl prodotto


void cancellazione(prodotto v[], int &fillcounter, int dim)
{
    for(int i=dim; i<fillcounter-1; i++)
    {
        v[i]=v[i+1]; 
    }
    fillcounter--;
}


//cancelazione deve cancellare prodotto e fare shift dei tutti prodotti a sinistra


int ricerca(prodotto v[], int dim, string bean)
{
    for (int i=0; i<dim; i++) 
    {
        if(v[i].nome == bean)
            return i;
    }
    return -1;
}




int main()
{
	prodotto supermarket[20];
	prodotto prodhelp;
	
	int dimension=20;
	int fillcounter=0;
	
	int option=0;
	bool control;
	int gencounter;
	int inthelp;
	string stringhelp;

	
	do
	{
	    gencounter=0;
	    control=false;
	    inthelp=0;
	    
	    
	    cout<<"Opzioni: "<<endl;
		cout<<"   Per fare fare aggiunta, premi '1'."<<endl<<"   Per visualizzare array, premi '2'."<<endl<<"   Per fare modifica veloce di array premi '3'."<<endl;
		cout<<"   Per cancellare un elemento di array premi '4'."<<endl<<"   Per fare ricerca veloce premi '5'."<<endl;
		cout<<"   Per uscire dal menu premi '0'."<<endl<<endl;
		
		cout<<"Quale operazione vuoi fare? Inserisci la lettera: ";
		cin>>option;
		cin.ignore();
		cout<<endl;
		
		
		switch(option)
		{
		    case 1:
		        if(fillcounter<20)
		        {
		            cout<<"Inserisci il nome ";
		            getline(cin,prodhelp.nome);
		            cout<<"Inserisci la categoria ";
		            getline(cin,prodhelp.categoria);
	        	    cout<<"Inserisci il prezzo ";
	        	    cin>>prodhelp.prezzo;
		            aggiunta(supermarket, fillcounter,prodhelp);
		            cout<<endl;
		            break;
		        }
		        else
		        {
		            cout<<"Array e' pieno"<<endl;
		            break;
		        }
		        
		        
		    case 2:
		        if(fillcounter>0)
		    	    cout<<visualizzazione(supermarket,fillcounter)<<endl;
		    	else
		    	    cout<<"Array e' vuoto"<<endl<<endl;
		        break;	
		        
		    case 3:
		        cout<<"Inserisci il nome del prodotto da modificare: ";
                getline(cin, stringhelp);
                inthelp=ricerca(supermarket, fillcounter, stringhelp);
                cout<<endl;
                
                if(inthelp!=-1) 
                {
                    cout<<"Nuovo Nome: "; 
                    getline(cin, prodhelp.nome);
                    cout<<"Nuova Categoria: "; 
                    getline(cin, prodhelp.categoria);
                    cout<<"Nuovo Prezzo: "; 
                    cin>>prodhelp.prezzo;
                    modifica(supermarket, prodhelp, inthelp);
                    cout<<"Prodotto modificato!"<<endl<<endl;
                    cin.ignore();
                    break;
                } 
                else
                {
                    cout<<"Prodotto non trovato."<<endl;
                    break;
                }

		    case 4:
		        cout<<"Nome del prodotto da cancellare: ";
                getline(cin, stringhelp);
                cout<<endl;
                inthelp=ricerca(supermarket, fillcounter, stringhelp);
                if(inthelp!=-1)
                {
                    cancellazione(supermarket, fillcounter, inthelp);
                    cout<<"Prodotto eliminato con successo!"<<endl;
                } 
                else
                    cout<<"Prodotto non trovato."<<endl;
                    
                cout<<endl;
                break;
		        
		        
		    case 5:
		    	cout<<"Nome da cercare: ";
                getline(cin, stringhelp);
                cout<<endl;
                inthelp=ricerca(supermarket, fillcounter, stringhelp);
                if(inthelp != -1) 
                    cout<<"Trovato in posizione: "<<inthelp+1<<endl;
                else 
                    cout<<"Non trovato."<<endl;
                cout<<endl;
                break;
	    }
	}while(option!=0);
	
	cout<<"Lavoro e' finito"<<endl;

    return 0;

}
