#include <iostream>
#include <string>
using namespace std;

struct prodotto
{
	string nome;
	float prezzo;
	string categoria;
	
};

/*
nel array di struct con contatore globale viene messa struct d'appogio dalla main. Contatore globale incrementa.
*/
void aggiunta(prodotto v[], int &fillcounter, prodotto n)
{
        v[fillcounter]=n;
        fillcounter++;
}

/*
tutte struct vengono uniti in una stringa che viene restituita con return
*/
string visualizzazione(prodotto v[], int dim)
{
    string output;
	for(int i=0;i<dim;i++)
	{
		output+=v[i].nome+"\t";
		output+=v[i].categoria+"\t";
		output+=to_string(v[i].prezzo)+"\n";
	}
	return output;
}


/*
nel array di struct con contatore speciale dal main viene messa struct d'appogio
*/
void modifica(prodotto v[], prodotto n, int g)
{
    v[g]=n;
}


/*
tutte struct di array vengono spostati a sinistra iniziando dalla posizione di (struct da eliminare)+1. Contatore globale si diminuiusce
*/
void cancellazione(prodotto v[], int &fillcounter, int dim)
{
    for(int i=dim; i<fillcounter-1; i++)
    {
        v[i]=v[i+1]; 
    }
    fillcounter--;
}



/*
con stringa bean(stringa messa dal'utente) faccio comparazione per trovare la posizione del prodotto con lo stesso nome
*/
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
    //dichiarazione struct
	prodotto supermarket[20];
	prodotto prodhelp;
	
	//dichiarazione contatori
	int dimension=20;
	int fillcounter=0;

	
	//dichiarazione variabili d'appoggio
	int option=0;

	int inthelp;
	string stringhelp;

	
	do
	{
	    /*
	    Si annula inthelp perche' e' una veriabile d'appoggio universale.
	    */
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
		    /*
		    Riempisco struc d'appoggio per copiarlo nel array di struct con funzione aggiunta
		    */
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
		        
		    
		    /*
		    Cout della stringa fatta nella funzione
		    */    
		    case 2:
		        if(fillcounter>0)
		    	    cout<<visualizzazione(supermarket,fillcounter)<<endl;
		    	else
		    	    cout<<"Array e' vuoto"<<endl<<endl;
		        break;	
		        
		        
		        
		    /*
		    Con funzione ricerca trovo posizione del prodotto con nome inserito. Con algoritmo di case 1 riempisco struct d'appoggio.
		    Che deve essere inserito nel array
		    */
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
            
            
            /*
            con ricerca trovo posizione del prodotto nome di cui inserisco e poi faccio spostamento(shift) sulla posizione trovata
            */
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
		        
		    
		    /*
		    Inserisco nome che sara messo come parametro nella funzione ricerca che trova posizione facendo comparazione dei nomi.
		    Comparando stringa inserita dal'utente e nomi presenti nel array di struct
		    */    
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
