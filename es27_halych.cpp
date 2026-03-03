#include <iostream>
using namespace std;

struct prodotto
{
	string nome;
	float prezzo;
	string categoria;
	
}apple, pear;

void aggiunta(int v[], int &fillcounter)
{
    string value;
    cout<<"Inserisci il nome del prodotto: ";
    getline(cin,value);
    
    float price;
    cout<<"Inserisci il prezzo del prodotto: ";
    cin>>price;
    
    string category;
    cout<<"Inserisci la categoria del prodotto: ";
    getline(cin,value);



    if(fillcounter<100)
    {
        v[fillcounter].nome=value;
        v[fillcounter].prezzo=price;
        v[fillcounter].categoria=category;
        
        fillcounter++;
        cout<<"prodotto aggiunto"<<endl;
    }
    else
        cout<<"Array pieno"<<endl;
    
}

void visualizzazione(int v[], int dim)
{
    cout<<"Prodotti visualizzati:"<<endl;
    for(int i=0;i<dim;i++)
    {
    	cout<<
        cout<<" ["<<v[i]<<"]";
        cout<<endl;
        
    }
    
    cout<<endl;
}

void modifica(int v[], int dim)
{
    int modpos;
    
    do
    {
        cout<<"Inserisci valore del posizione della variabile di array che vuoi cambiare: ";
        cin>>modpos;
    }while(modpos>99 || modpos<0);
    
    
    int modval;
    cout<<"Inserisci valore con quale vuoi restituire il valore della variabile di array che vuoi cambiare: ";
    cin>>modval;
    
    v[modpos]=modval;
    cout<<endl;
}

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

// funzione di ricerca
int ricerca(int v[], int dim)
{
    int fval;
    cout<<"Inserisci il valore posizione del quale vuoi trovare: ";
    cin>>fval;
    
    for(int i=0; i<dim; i++)
    {
        if(v[i]==fval)
            return i;
    }
    return -1;
}


int main()
{
	prodotto vector[20];
	int dimension=20;
	int fillcounter=0;
	
	for(int i=0;i<20;i++)
	{
	    vector[i].nome=-1;
	    vector[]
	}
	

	//cout<<"Un codice crud per lavorare con gli array"<<endl<<endl;
	char option=0;
	
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
		        aggiunta(vector, fillcounter);
		        break;
		    
		    
		    case 'r':
		    case 'R':
		        visualizzazione(vector, dimension);
		        break;
		        
		    case 'u':
		    case 'U':
		        modifica(vector, dimension);
		        break;
		        
		    case 'd':
		    case 'D':
		        cancellazione(vector, dimension);
		        break;
		        
		        
		    case 'f':
		    case 'F':
		        int research_result=ricerca(vector, dimension);
		        cout<<"Posizione: "<<research_result<<endl;
		        break;
		    
		        
		    
		}
		
		
		
		
		
		
	}while(option!='s'||option!='S');

    return 0;
}