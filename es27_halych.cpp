#include <iostream>
#include <string>
using namespace std;

struct prodotto
{
	string nome;
	float prezzo;
	string categoria;
	
};


void aggiunta(prodotto v[], int &fillcounter, string nome, float prezzo, string categoria)
{
    if(fillcounter < 100)
    {
        v[fillcounter].nome = nome;
        v[fillcounter].prezzo = prezzo;
        v[fillcounter].categoria = categoria;

        fillcounter++;
        cout << "Prodotto aggiunto" << endl;
    }
    else
        cout << "Array pieno" << endl;
}

void visualizzazione(prodotto v[], int dim)
{
    cout << endl;

    for(int i = 0; i < dim; i++)
    {
        cout << "Nome del prodotto: " << v[i].nome << endl;
        cout << "Prezzo del prodotto: " << v[i].prezzo << endl;
        cout << "Categoria del prodotto: " << v[i].categoria << endl;
        cout << endl;
    }
}

void modifica(prodotto v[], int dim)
{
    int modpos;

    do
    {
        cout << "Inserisci posizione del prodotto da modificare: ";
        cin >> modpos;
    }while(modpos >= dim || modpos < 0);

    cout << "Nuovo nome: ";
    cin >> v[modpos].nome;

    cout << "Nuovo prezzo: ";
    cin >> v[modpos].prezzo;

    cout << "Nuova categoria: ";
    cin >> v[modpos].categoria;

    cout << "Prodotto modificato" << endl;
}

/*
void cancellazione(int v[], int dim)
{
    int cpos;
    do
    {
        cout<<"Inserisci valore del posizione della variabile valore di quale vuoi cancellare: ";
        cin>>cpos;
    }while(cpos>99 || cpos<0);
    
    v[cpos]=-1;
}
*/

// funzione di ricerca
int ricerca(prodotto v[], int dim)
{
    string fval;
    cin >> fval;

    for(int i = 0; i < dim; i++)
    {
        if(v[i].nome == fval)
            return i;
    }

    return -1;
}


int main()
{
	prodotto supermarket[20];
	int dimension=20;
	int fillcounter=0;
	
	/*for(int i=0;i<20;i++)
	{
	    vector[i].nome=-1;
	    vector[];
	}
	*/

	//cout<<"Un codice crud per lavorare con gli array"<<endl<<endl;
	char option=0;
	string value;
	float price;
	string category;
	
	do
	{
	    cout<<"Opzioni: "<<endl;
		cout<<"   Per fare fare aggiunta, premi 'C'."<<endl<<"   Per visualizzare array, premi 'R'."<<endl<<"   Per fare modifica veloce di array premi 'U'."<<endl;
		cout<<"   Per cancellare un elemento di array premi 'D'."<<endl<<"    Per fare ricerca veloce premi 'F'."<<endl;
		cout<<"   Per uscire dal menu premi 'S'."<<endl<<endl;
		
		cout<<"Quale operazione vuoi fare? Inserisci la lettera: ";
		cin>>option;
		
		cout<<endl;
		
		
		switch(option)
		{
		    case 'c':
		    case 'C':
		    	
    			cout<<"Inserisci il nome del prodotto: ";
    			getline(cin,value);
    			cout<<endl;
    
    			
    			cout<<"Inserisci il prezzo del prodotto: ";
    			cin>>price;
    			cout<<endl;
    
    			
    			cout<<"Inserisci la categoria del prodotto: ";
    			getline(cin,value);
    			cout<<endl;
		        aggiunta(supermarket, fillcounter,value,price,category);
		        break;
		    
		    
		    case 'r':
		    case 'R':
		    	cout<<endl;
		    	cout<<"Prodotti visualizzati:"<<endl;
    			for(int i=0;i<dimension;i++)
    			{
    			cout<<"Prodotto n "<<i<<endl;
    			cout<<"Nome:"<<supermarket[i].nome<<endl;
    			cout<<"Prezzo:"<<supermarket[i].prezzo<<endl;
    			cout<<"Categoria:"<<supermarket[i].categoria<<endl;
        		cout<<endl;
    			}
    
		        break;
		        
		    case 'u':
		    case 'U':
		        modifica(supermarket, dimension);
		        break;
		        
		    case 'd':
		    case 'D':
		        //cancellazione(supermarket, dimension);
		        break;
		        
		        
		    case 'f':
		    case 'F':
		    	cout<<"Inserisci il nome del prodotto posizione del del quale vuoi trovare: ";
		        int research_result=ricerca(supermarket, dimension);
		        if(research_result==-1)
		        {
		        	cout<<"Prodotto non è stato trovato";
				}
		        cout<<"Posizione: "<<research_result<<endl;
		        break;
		}
	}while(option!='s'||option!='S');
	

    return 0;

}
